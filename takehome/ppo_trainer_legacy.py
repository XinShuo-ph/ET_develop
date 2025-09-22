import torch
import torch.nn as nn
import torch.nn.functional as F
from transformers import AutoTokenizer, AutoModelForCausalLM
from datasets import load_dataset
from combined_reward import CombinedReward
import numpy as np
from typing import List

class PPOTrainer:
    def __init__(self, model_name="Qwen/Qwen2.5-Coder-0.5B-Instruct", lr=1e-5, clip_epsilon=0.2,
                 bleu_weight=0.7, llm_weight=0.3, use_llm_judge=True, max_new_tokens=400, temperature=0.3):
        self.device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
        self.clip_epsilon = clip_epsilon
        self.max_new_tokens = max_new_tokens
        self.temperature = temperature
        
        # Load model and tokenizer
        self.tokenizer = AutoTokenizer.from_pretrained(model_name)
        self.model = AutoModelForCausalLM.from_pretrained(model_name)
        self.model = self.model.to(self.device)
        
        # Simple value network
        hidden_size = self.model.config.hidden_size
        self.value_net = nn.Sequential(
            nn.Linear(hidden_size, hidden_size // 2),
            nn.ReLU(),
            nn.Linear(hidden_size // 2, 1)
        ).to(self.device)
        
        # Optimizer for both policy and value networks
        self.optimizer = torch.optim.AdamW(
            list(self.model.parameters()) + list(self.value_net.parameters()),
            lr=lr
        )
        
        # Reward system
        self.reward_system = CombinedReward(bleu_weight=bleu_weight, llm_weight=llm_weight, use_llm_judge=use_llm_judge)
        
        print(f"PPO Trainer initialized on {self.device}")
    
    def generate_response(self, prompt: str):
        """Generate response with text cleanup"""
        inputs = self.tokenizer(prompt, return_tensors="pt").to(self.device)
        input_length = inputs.input_ids.shape[1]
        
        with torch.no_grad():
            outputs = self.model.generate(
                **inputs,
                max_new_tokens=self.max_new_tokens,
                temperature=self.temperature,
                do_sample=True,
                pad_token_id=self.tokenizer.eos_token_id
            )
        
        generated_tokens = outputs[0][input_length:]
        generated_text = self.tokenizer.decode(generated_tokens, skip_special_tokens=True)
        
        # Clean up generated text
        if "```" in generated_text:
            generated_text = generated_text.split("```")[0].strip()
        if "\n" in generated_text and generated_text.find("\n") < 50:
            generated_text = generated_text[generated_text.find("\n")+1:]
        
        return generated_text, outputs[0]
    
    def get_log_probs_and_values(self, sequences: List[torch.Tensor], prompt_lengths: List[int]):
        """Get log probabilities and values for sequences - memory optimized"""
        log_probs = []
        values = []
        
        for i, (seq, prompt_len) in enumerate(zip(sequences, prompt_lengths)):
            seq = seq.unsqueeze(0)  # Add batch dimension
            
            # Monitor sequence size for first sequence
            if i == 0:
                seq_size_mb = seq.element_size() * seq.numel() / 1024**2
                print(f"  Processing {len(sequences)} sequences, first seq: {len(seq[0])} tokens ({seq_size_mb:.1f}MB)")
            
            # Forward pass
            outputs = self.model(input_ids=seq, output_hidden_states=True)
            logits = outputs.logits[0]  # Remove batch dim
            hidden_states = outputs.hidden_states[-1]  # Last layer
            
            # Monitor first sequence tensor sizes
            if i == 0:
                logits_size_mb = logits.element_size() * logits.numel() / 1024**2
                hidden_size_mb = hidden_states.element_size() * hidden_states.numel() / 1024**2
                print(f"  Logits: {list(logits.shape)} = {logits_size_mb:.1f}MB, Hidden: {list(hidden_states.shape)} = {hidden_size_mb:.1f}MB")
            
            # Get log probs for generated tokens only
            generated_logits = logits[prompt_len-1:-1]  # Shift for next token prediction
            generated_tokens = seq[0][prompt_len:]
            
            if len(generated_tokens) > 0 and len(generated_logits) > 0:
                log_probs_seq = F.log_softmax(generated_logits, dim=-1)
                token_log_probs = log_probs_seq.gather(1, generated_tokens.unsqueeze(1)).squeeze(1)
                log_probs.append(token_log_probs.mean())
                del log_probs_seq, token_log_probs
            else:
                # Use a small log prob from the last logit to maintain gradient flow
                last_logit = logits[-1:, :]  # Shape: [1, vocab_size] 
                dummy_log_prob = F.log_softmax(last_logit, dim=-1)[0, 0]  # Just pick first token
                log_probs.append(dummy_log_prob)
            
            # Get value from last hidden state
            value = self.value_net(hidden_states[0, -1:])  # Last token
            values.append(value.squeeze())
            
            # Immediately clean up large tensors to prevent accumulation
            del outputs, logits, hidden_states, seq
            
            # Clear cache after each sequence during gradient computation
            if torch.is_grad_enabled():
                torch.cuda.empty_cache()
        
        return torch.stack(log_probs), torch.stack(values)
    
    def compute_advantages(self, rewards: List[float], values: torch.Tensor):
        """Simple advantage computation"""
        rewards = torch.tensor(rewards, device=self.device, requires_grad=False)  # Explicit: no grad
        advantages = rewards - values  # advantages inherits grad from values
        returns = rewards.clone()  # returns are targets, no grad needed
        
        # Normalize advantages
        if len(advantages) > 1:
            advantages = (advantages - advantages.mean()) / (advantages.std() + 1e-8)
        
        return advantages, returns
    
    def train_step(self, prompts: List[str], reference_codes: List[str]):
        """Single PPO training step"""
        batch_size = len(prompts)
        
        # Generate responses and collect data
        sequences = []
        prompt_lengths = []
        rewards = []
        
        print(f"Collecting rollouts for {batch_size} examples...")
        
        for i, (prompt, ref_code) in enumerate(zip(prompts, reference_codes)):
            generated_text, full_sequence = self.generate_response(prompt)
            
            # Get reward
            reward_result = self.reward_system.get_reward(generated_text, ref_code)
            reward = reward_result['combined_reward']
            
            # Store data
            sequences.append(full_sequence)
            prompt_lengths.append(len(self.tokenizer(prompt, return_tensors="pt").input_ids[0]))
            rewards.append(reward)
            
            print(f"  Example {i+1}: Reward = {reward:.4f}")
        
        # Check memory usage of stored sequences
        sequences_memory_mb = sum([seq.element_size() * seq.numel() for seq in sequences]) / 1024**2
        print(f"Stored sequences memory: {sequences_memory_mb:.1f}MB")
        print(f"Sequence lengths: {[len(seq) for seq in sequences]}")
        
        # Get old log probs and values (no gradients needed for baseline)
        print("Computing baseline values...")
        with torch.no_grad():
            old_log_probs, old_values = self.get_log_probs_and_values(sequences, prompt_lengths)
        
        # Compute advantages
        advantages, returns = self.compute_advantages(rewards, old_values)
        
        # PPO updates
        for epoch in range(20):
            print(f"Epoch {epoch+1}/20:")
            
            # Check GPU memory before forward pass
            if torch.cuda.is_available():
                memory_allocated = torch.cuda.memory_allocated() / 1024**2
                memory_reserved = torch.cuda.memory_reserved() / 1024**2
                print(f"  GPU Memory: {memory_allocated:.1f}MB allocated, {memory_reserved:.1f}MB reserved")
            
            # Get new log probs and values (these WILL have gradients)
            new_log_probs, new_values = self.get_log_probs_and_values(sequences, prompt_lengths)
            
            # PPO policy loss
            ratio = torch.exp(new_log_probs - old_log_probs)
            surr1 = ratio * advantages
            surr2 = torch.clamp(ratio, 1 - self.clip_epsilon, 1 + self.clip_epsilon) * advantages
            policy_loss = -torch.min(surr1, surr2).mean()
            
            # Value loss
            value_loss = F.mse_loss(new_values, returns)
            
            # Combined loss
            total_loss = policy_loss + value_loss * 0.5
            print(f"  Loss: policy={policy_loss.item():.4f}, value={value_loss.item():.4f}, total={total_loss.item():.4f}")
            
            # Update both networks 
            self.optimizer.zero_grad()
            total_loss.backward()
            torch.nn.utils.clip_grad_norm_(self.model.parameters(), 1.0)
            self.optimizer.step()
            
            # Clean up intermediate tensors
            del new_log_probs, new_values, ratio, surr1, surr2, policy_loss, value_loss, total_loss
            
            # Clear cache after every epoch to prevent fragmentation
            torch.cuda.empty_cache()
        
        # Final memory check
        if torch.cuda.is_available():
            final_memory = torch.cuda.memory_allocated() / 1024**2
            print(f"Final GPU Memory: {final_memory:.1f}MB allocated")
        
        return {
            'mean_reward': np.mean(rewards),
            'mean_advantage': advantages.mean().item()
        }

def create_structured_prompt(example, char_limit=10000):
    """Create prompt (same as in load_infer.py)"""
    context = example['context'][:char_limit] if len(example['context']) > char_limit else example['context']
    
    prompt = f"""<|system|>
You are an expert C/C++ developer working on EinsteinToolkit, a codebase for numerical relativity simulations.

<|user|>
Create C/C++ code for the file `{example['src_filename']}` in thorn `{example['thorn_name']}`.

## Thorn Information:
- Name: {example['thorn_name']}
- Target file: {example['src_filename']}

## Interface Definition in interface.ccl:
```
{example['interface']}
```

## Schedule Definition in schedule.ccl:
```
{example['schedule']}
```

## Parameters Definition in param.ccl:
```
{example['param']}
```

## Configuration Definition in configuration.ccl:
```
{example['configuration']}
```

## Related Code Context:
```
{context}
```

## Instructions:
Generate only the complete C/C++ source code for `{example['src_filename']}`. Include necessary headers, functions, and follow EinsteinToolkit conventions.

<|assistant|>
Here is the code for `{example['src_filename']}`:
```"""
    return prompt

def test_ppo():
    """Test PPO training with a small batch"""

    # we are constrained in computing resources, set upper limits
    context_char_limit = 2000
    generated_char_limit = 500
    generated_max_tokens = 100


    trainer = PPOTrainer(
        bleu_weight=0.8, 
        llm_weight=0.2, 
        use_llm_judge=True,  # Disable for faster testing
        max_new_tokens=generated_max_tokens,
        temperature=0.3
    )
    
    # Load dataset
    ds = load_dataset("xinshuo/ET_code_with_context")
    train_ds = ds['train']
    
    # Prepare small batch
    batch_indices = [1, 3, 5]
    prompts = []
    reference_codes = []
    
    for i in batch_indices:
        example = train_ds[i]
        prompt = create_structured_prompt(example, char_limit=context_char_limit)
        ref_code = example['src_code'][:generated_char_limit]
        
        prompts.append(prompt)
        reference_codes.append(ref_code)
    
    print("Running PPO training step...")
    metrics = trainer.train_step(prompts, reference_codes)
    
    print(f"Training metrics:")
    for key, value in metrics.items():
        print(f"  {key}: {value:.4f}")

if __name__ == "__main__":
    test_ppo() 