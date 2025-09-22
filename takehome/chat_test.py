import torch
import os
from transformers import AutoTokenizer, AutoModelForCausalLM

def load_and_test_qwen():
    """Load Qwen2.5-Coder-1.5B-Instruct model and perform simple inference"""
    
    # Model name and get cache directory from environment variables
    model_name = "Qwen/Qwen2.5-Coder-0.5B-Instruct"
    cache_dir = os.environ.get('HF_HOME', '/pscratch/sd/x/xinshuo/takehome/HFcache')
    
    # Determine device
    device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
    print(f"Using device: {device}")
    
    print(f"Loading model: {model_name}")
    print(f"Using cache directory from HF_HOME: {cache_dir}")
    print("This might take a few minutes...")
    
    # Load tokenizer and model (will automatically use HF_HOME and TRANSFORMERS_CACHE env vars)
    tokenizer = AutoTokenizer.from_pretrained(model_name)
    model = AutoModelForCausalLM.from_pretrained(
        model_name,
        torch_dtype=torch.float16  # Use half precision for efficiency
    )
    
    # Move model to device
    model = model.to(device)
    
    print(f"Model loaded successfully!")
    print(f"Model device: {model.device}")
    print(f"Model dtype: {model.dtype}")
    print(f"Cache directory contents:")
    
    # Show what's in the cache directory
    if os.path.exists(cache_dir):
        cache_contents = os.listdir(cache_dir)
        for item in cache_contents[:5]:  # Show first 5 items
            item_path = os.path.join(cache_dir, item)
            if os.path.isdir(item_path):
                print(f"  📁 {item}/")
            else:
                print(f"  📄 {item}")
    else:
        print(f"  Cache directory not found: {cache_dir}")
    
    # Simple inference example
    prompt = "Write a Python function to calculate the factorial of a number:"
    
    print(f"\nPrompt: {prompt}")
    print("Generating response...")
    
    # Tokenize input
    inputs = tokenizer(prompt, return_tensors="pt")
    
    # Move inputs to same device as model
    inputs = {k: v.to(device) for k, v in inputs.items()}
    
    # Generate response
    with torch.no_grad():
        outputs = model.generate(
            **inputs,
            max_new_tokens=150,
            temperature=0.7,
            do_sample=True,
            pad_token_id=tokenizer.eos_token_id
        )
    
    # Decode the response
    response = tokenizer.decode(outputs[0], skip_special_tokens=True)
    
    print(f"\nGenerated response:\n{response}")
    
    return model, tokenizer

if __name__ == "__main__":
    model, tokenizer = load_and_test_qwen()
