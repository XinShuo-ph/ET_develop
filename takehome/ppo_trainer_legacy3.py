import torch
import torch.nn as nn
import torch.nn.functional as F
from torch.optim import Adam
from transformers import AutoTokenizer, AutoModelForCausalLM
from datasets import load_dataset
from combined_reward import CombinedReward
import numpy as np
from typing import List, Dict, Tuple, Optional, Union
from tqdm import tqdm

class PPOTrainer:
    """
    PPO Trainer for fine-tuning language models with reinforcement learning
    using BLEU score and LLM judge as rewards.
    """
    
    def __init__(
        self,
        model_name: str = "Qwen/Qwen2.5-Coder-0.5B-Instruct",
        ref_model_name: Optional[str] = None,
        lr: float = 5e-6,
        batch_size: int = 4,
        mini_batch_size: int = 2,
        gradient_accumulation_steps: int = 4,
        ppo_epochs: int = 4,
        max_grad_norm: float = 0.5,
        gamma: float = 0.99,
        lam: float = 0.95,
        cliprange: float = 0.2,
        cliprange_value: float = 0.2,
        vf_coef: float = 0.1,
        kl_coef: float = 0.05,
        max_new_tokens: int = 400,
        temperature: float = 0.7,
        top_p: float = 0.9,
        device: str = "cuda",
        bleu_weight: float = 0.6,
        llm_weight: float = 0.4,
        use_llm_judge: bool = True,
    ):
        """
        Initialize the PPO trainer with model and hyperparameters.
        
        Args:
            model_name: Name of the HuggingFace model to use
            ref_model_name: Name of reference model (if None, will use a copy of model_name)
            lr: Learning rate for optimizer
            batch_size: Batch size for training
            mini_batch_size: Mini-batch size for PPO updates
            gradient_accumulation_steps: Number of steps to accumulate gradients
            ppo_epochs: Number of PPO update epochs per batch
            max_grad_norm: Maximum gradient norm for clipping
            gamma: Discount factor
            lam: GAE lambda parameter
            cliprange: PPO clip range for policy loss
            cliprange_value: PPO clip range for value loss
            vf_coef: Value function coefficient
            kl_coef: KL divergence coefficient
            max_new_tokens: Maximum number of new tokens to generate
            temperature: Temperature for generation
            top_p: Top-p for nucleus sampling
            device: Device to use for training
            bleu_weight: Weight for BLEU score in reward
            llm_weight: Weight for LLM judge score in reward
            use_llm_judge: Whether to use LLM judge for reward
        """
        self.lr = lr
        self.batch_size = batch_size
        self.mini_batch_size = mini_batch_size
        self.gradient_accumulation_steps = gradient_accumulation_steps
        self.ppo_epochs = ppo_epochs
        self.max_grad_norm = max_grad_norm
        self.gamma = gamma
        self.lam = lam
        self.cliprange = cliprange
        self.cliprange_value = cliprange_value
        self.vf_coef = vf_coef
        self.kl_coef = kl_coef
        self.max_new_tokens = max_new_tokens
        self.temperature = temperature
        self.top_p = top_p
        self.device = device
        
        # Setup device
        self.device = torch.device(device)
        
        # Load model and tokenizer
        self.tokenizer = AutoTokenizer.from_pretrained(model_name)
        self.model = AutoModelForCausalLM.from_pretrained(model_name)
        self.model = self.model.to(self.device)
        
        # Initialize reference model (for KL penalty)
        if ref_model_name is None:
            ref_model_name = model_name
        self.ref_model = AutoModelForCausalLM.from_pretrained(ref_model_name)
        self.ref_model = self.ref_model.to(self.device)
        self.ref_model.eval()  # Reference model is frozen
        
        # Initialize reward system
        self.reward_system = CombinedReward(
            bleu_weight=bleu_weight, 
            llm_weight=llm_weight, 
            use_llm_judge=use_llm_judge
        )
        
        # Initialize optimizer
        self.optimizer = Adam(self.model.parameters(), lr=self.lr)
        
        # Initialize value head (simple linear layer on top of LLM)
        self.value_head = nn.Linear(self.model.config.hidden_size, 1)
        self.value_head = self.value_head.to(self.device)
        self.value_optimizer = Adam(self.value_head.parameters(), lr=self.lr)
        
        print(f"PPOTrainer initialized with model: {model_name}")
        print(f"Learning rate: {lr}, Batch size: {batch_size}, PPO epochs: {ppo_epochs}")
        print(f"Reward: BLEU weight={bleu_weight}, LLM weight={llm_weight}, LLM enabled={use_llm_judge}")
    
    def get_logprobs_and_values(
        self, 
        input_ids: torch.Tensor, 
        attention_mask: torch.Tensor,
        response_ids: torch.Tensor
    ) -> Tuple[torch.Tensor, torch.Tensor]:
        """
        Get log probabilities and values for the generated responses
        
        Args:
            input_ids: Input token IDs [batch_size, seq_len]
            attention_mask: Attention mask [batch_size, seq_len]
            response_ids: Response token IDs [batch_size, resp_len]
            
        Returns:
            Tuple of (log_probs, values)
        """
        # Forward pass through the model
        outputs = self.model(
            input_ids=input_ids,
            attention_mask=attention_mask,
            output_hidden_states=True,
            return_dict=True
        )
        
        logits = outputs.logits
        hidden_states = outputs.hidden_states[-1]  # Last layer hidden states
        
        # Calculate log probabilities
        log_probs = F.log_softmax(logits[:, :-1, :], dim=-1)
        
        # Gather the log probs corresponding to the response tokens
        gathered_log_probs = torch.gather(
            log_probs, 
            dim=2, 
            index=response_ids[:, 1:].unsqueeze(-1)
        ).squeeze(-1)
        
        # Calculate values using the value head
        values = self.value_head(hidden_states).squeeze(-1)
        
        return gathered_log_probs, values
    
    def generate_responses(self, prompts: List[str]) -> List[str]:
        """
        Generate responses for a batch of prompts
        
        Args:
            prompts: List of prompt strings
            
        Returns:
            List of generated response strings
        """
        # Tokenize prompts
        inputs = self.tokenizer(
            prompts, 
            return_tensors="pt", 
            padding=True, 
            truncation=True
        )
        inputs = {k: v.to(self.device) for k, v in inputs.items()}
        
        # Generate responses
        with torch.no_grad():
            outputs = self.model.generate(
                **inputs,
                max_new_tokens=self.max_new_tokens,
                temperature=self.temperature,
                top_p=self.top_p,
                do_sample=True,
                pad_token_id=self.tokenizer.eos_token_id,
                return_dict_in_generate=True,
                output_scores=True
            )
        
        # Decode generated tokens
        generated_ids = outputs.sequences
        generated_texts = self.tokenizer.batch_decode(
            generated_ids, 
            skip_special_tokens=True
        )
        
        # Extract only the response part (remove the prompt)
        responses = []
        for i, text in enumerate(generated_texts):
            prompt_text = self.tokenizer.decode(
                inputs["input_ids"][i], 
                skip_special_tokens=True
            )
            response = text[len(prompt_text):].strip()
            
            # Clean up artifacts (similar to load_infer.py)
            if "```" in response:
                response = response.split("```")[0].strip()
            if "\n" in response and response.find("\n") < 50:
                first_newline = response.find("\n")
                response = response[first_newline+1:]
                
            responses.append(response)
        
        return responses
    
    def train_step(
        self, 
        prompts: List[str], 
        reference_codes: List[str]
    ) -> Dict[str, float]:
        """
        Perform a single PPO training step
        
        Args:
            prompts: List of prompt strings
            reference_codes: List of reference code strings
            
        Returns:
            Dictionary with training metrics
        """
        # Generate responses and compute rewards
        responses = self.generate_responses(prompts)
        rewards = []
        
        for response, reference in zip(responses, reference_codes):
            reward_dict = self.reward_system.get_reward(response, reference)
            rewards.append(reward_dict["combined_reward"])
        
        rewards = torch.tensor(rewards, device=self.device)
        
        # Tokenize prompts and responses for PPO
        tokenized_prompts = self.tokenizer(
            prompts, 
            return_tensors="pt", 
            padding=True, 
            truncation=True
        )
        tokenized_prompts = {k: v.to(self.device) for k, v in tokenized_prompts.items()}
        
        tokenized_responses = self.tokenizer(
            responses, 
            return_tensors="pt", 
            padding=True, 
            truncation=True
        )
        tokenized_responses = {k: v.to(self.device) for k, v in tokenized_responses.items()}
        
        # Get log probabilities and values for the old policy
        with torch.no_grad():
            old_log_probs, old_values = self.get_logprobs_and_values(
                tokenized_prompts["input_ids"],
                tokenized_prompts["attention_mask"],
                tokenized_responses["input_ids"]
            )
        
        # Compute advantages and returns
        advantages, returns = self._compute_advantages_and_returns(
            old_values, 
            rewards
        )
        
        # PPO training loop
        metrics = {
            "policy_loss": 0.0,
            "value_loss": 0.0,
            "kl_div": 0.0,
            "mean_reward": rewards.mean().item()
        }
        
        for _ in range(self.ppo_epochs):
            # Create mini-batches
            batch_size = len(prompts)
            indices = torch.randperm(batch_size)
            
            for start_idx in range(0, batch_size, self.mini_batch_size):
                end_idx = min(start_idx + self.mini_batch_size, batch_size)
                mb_indices = indices[start_idx:end_idx]
                
                # Get mini-batch data
                mb_prompt_ids = tokenized_prompts["input_ids"][mb_indices]
                mb_prompt_mask = tokenized_prompts["attention_mask"][mb_indices]
                mb_response_ids = tokenized_responses["input_ids"][mb_indices]
                mb_old_log_probs = old_log_probs[mb_indices]
                mb_advantages = advantages[mb_indices]
                mb_returns = returns[mb_indices]
                
                # Forward pass
                new_log_probs, new_values = self.get_logprobs_and_values(
                    mb_prompt_ids,
                    mb_prompt_mask,
                    mb_response_ids
                )
                
                # Calculate KL divergence with reference model
                with torch.no_grad():
                    ref_outputs = self.ref_model(
                        input_ids=mb_prompt_ids,
                        attention_mask=mb_prompt_mask,
                        output_hidden_states=True,
                        return_dict=True
                    )
                    ref_logits = ref_outputs.logits
                    ref_log_probs = F.log_softmax(ref_logits[:, :-1, :], dim=-1)
                    ref_gathered_log_probs = torch.gather(
                        ref_log_probs, 
                        dim=2, 
                        index=mb_response_ids[:, 1:].unsqueeze(-1)
                    ).squeeze(-1)
                
                # Calculate KL divergence
                kl_div = (new_log_probs.exp() * (new_log_probs - ref_gathered_log_probs)).sum(-1)
                
                # Calculate policy loss (PPO objective)
                ratio = torch.exp(new_log_probs - mb_old_log_probs)
                surr1 = ratio * mb_advantages
                surr2 = torch.clamp(ratio, 1.0 - self.cliprange, 1.0 + self.cliprange) * mb_advantages
                policy_loss = -torch.min(surr1, surr2).mean()
                
                # Add KL penalty
                policy_loss += self.kl_coef * kl_div.mean()
                
                # Calculate value loss
                value_pred_clipped = mb_old_log_probs + torch.clamp(
                    new_values - mb_old_log_probs,
                    -self.cliprange_value,
                    self.cliprange_value
                )
                value_loss1 = (new_values - mb_returns) ** 2
                value_loss2 = (value_pred_clipped - mb_returns) ** 2
                value_loss = 0.5 * torch.max(value_loss1, value_loss2).mean()
                
                # Total loss
                loss = policy_loss + self.vf_coef * value_loss
                
                # Backward pass with gradient accumulation
                loss = loss / self.gradient_accumulation_steps
                loss.backward()
                
                # Update metrics
                metrics["policy_loss"] += policy_loss.item() / self.ppo_epochs
                metrics["value_loss"] += value_loss.item() / self.ppo_epochs
                metrics["kl_div"] += kl_div.mean().item() / self.ppo_epochs
                
                # Gradient accumulation
                if (start_idx + self.mini_batch_size) % (self.gradient_accumulation_steps * self.mini_batch_size) == 0:
                    # Clip gradients
                    torch.nn.utils.clip_grad_norm_(
                        self.model.parameters(), 
                        self.max_grad_norm
                    )
                    torch.nn.utils.clip_grad_norm_(
                        self.value_head.parameters(), 
                        self.max_grad_norm
                    )
                    
                    # Update model and value head
                    self.optimizer.step()
                    self.value_optimizer.step()
                    self.optimizer.zero_grad()
                    self.value_optimizer.zero_grad()
        
        return metrics
    
    def _compute_advantages_and_returns(
        self, 
        values: torch.Tensor, 
        rewards: torch.Tensor
    ) -> Tuple[torch.Tensor, torch.Tensor]:
        """
        Compute advantages and returns using GAE
        
        Args:
            values: Value predictions [batch_size, seq_len]
            rewards: Final rewards [batch_size]
            
        Returns:
            Tuple of (advantages, returns)
        """
        # For simplicity, treat each response as a single step
        # (we're not doing token-level rewards)
        advantages = rewards - values[:, -1]
        returns = rewards
        
        return advantages, returns
    
    def save_model(self, output_dir: str):
        """Save the fine-tuned model and tokenizer"""
        self.model.save_pretrained(output_dir)
        self.tokenizer.save_pretrained(output_dir)
        # Save value head separately
        torch.save(self.value_head.state_dict(), f"{output_dir}/value_head.pt")
        print(f"Model saved to {output_dir}")

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
        # generation_config={
        #     "max_new_tokens": generated_max_tokens,
        #     "temperature": 0.3
        # }
        max_new_tokens=generated_max_tokens,
        temperature=0.3
    )
    
    # Load dataset
    ds = load_dataset("xinshuo/ET_code_with_context")
    train_ds = ds['train']
    
    # Prepare small batch
    batch_indices = [1, 3, 5, 7]
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