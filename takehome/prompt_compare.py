from transformers import AutoTokenizer, AutoModelForCausalLM
from datasets import load_dataset
import torch

model_name = "Qwen/Qwen2.5-Coder-0.5B-Instruct"
device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
tokenizer = AutoTokenizer.from_pretrained(model_name)
model = AutoModelForCausalLM.from_pretrained(model_name)
model = model.to(device)

print("Loading EinsteinToolkit code dataset...")

ds = load_dataset("xinshuo/ET_code_with_context")
train_ds = ds['train']

def create_concise_prompt(example, char_limit=8000):
    """Concise, focused prompt"""
    context = example['context'][:char_limit] if len(example['context']) > char_limit else example['context']
    
    prompt = f"""Generate C/C++ code for EinsteinToolkit thorn: {example['thorn_name']}

Target file: {example['src_filename']}

Configuration files:
- interface.ccl: {example['interface'][:300]}...
- schedule.ccl: {example['schedule'][:300]}...

Related code context:
{context}

Generate only the C/C++ code for {example['src_filename']}:"""
    return prompt

def create_structured_prompt(example, char_limit=8000):
    """Structured prompt with clear sections"""
    context = example['context'][:char_limit] if len(example['context']) > char_limit else example['context']
    
    prompt = f"""<|system|>
You are an expert C/C++/Fortran/Makefile developer working on EinsteinToolkit, a codebase for numerical relativity simulations.

<|user|>
Create C/C++/Fortran/Makefile code for the file `{example['src_filename']}` in thorn `{example['thorn_name']}`.

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
Generate only the complete C/C++/Fortran/Makefile source code for `{example['src_filename']}`. Include necessary headers, functions, and follow EinsteinToolkit conventions.

<|assistant|>
```"""
    return prompt

def create_instruction_prompt(example, char_limit=8000):
    """Instruction-following format"""
    context = example['context'][:char_limit] if len(example['context']) > char_limit else example['context']
    
    prompt = f"""You are an expert in EinsteinToolkit development. Generate C/C++/Fortran/Makefile code for the specified file.

**Task**: Write `{example['src_filename']}` for thorn `{example['thorn_name']}`

**Context**:
Interface: {example['interface']}
Parameters: {example['param']}
Schedule: {example['schedule']}
Configuration: {example['configuration']}

**Related Files**:
{context}

**Output**: Complete C/C++/Fortran/Makefile code for `{example['src_filename']}` only, no explanations:

```"""
    return prompt

def create_prompt(example, char_limit=10000):
    example_context = example['context']
    if len(example_context) > char_limit:
        example_context = example_context[:char_limit]
        example_context += "\n... (truncated)"
    prompt = "You are an AI code assistant specialized in Cactus Compuattion language and EinsteinToolkit. Based on the following context, generate the appropriate code. You are tasked with writing code for a particular module (a.k.a. thorn) in a Cactus codebase, EinsteinToolkit. You will be given a description of the thorn, a few Cactus Compuattion language snippets that are relevant to the thorn, and the names of other files in the same thorn. Your task is to write one appropriate code file for the thorn.\n\n"
    prompt += "Here is the description of the thorn:\n"
    prompt += f"thorn_name: ```{example['thorn_name']}```\n"
    prompt += f"url: {example['url']}\n"
    prompt += "Here are the relevant Cactus Compuattion language snippets, described by configuration.ccl, interface.ccl, param.ccl, and schedule.ccl:\n"
    prompt += f"configuration.ccl:\n ```\n{example['configuration']}```\n"
    prompt += f"interface.ccl:\n ```\n{example['interface']}```\n"
    prompt += f"param.ccl:\n ```\n{example['param']}```\n"
    prompt += f"schedule.ccl:\n ```\n{example['schedule']}```\n"
    prompt += f"Here are the names of other files in the same thorn:\n{example['context_filenames']}\n"
    prompt += f"Here are the contents of the other codes in the same thorn:\n{example_context}\n"
    prompt += f"The file you are writing is \n{example['src_filename']}\n"
    prompt += f"Output only the content of the `{example['src_filename']}` file you write, no other supplementary text or ``` markers.\n"
    return prompt

def test_prompt_strategies(example, target_col):
    """Test different prompt strategies"""
    strategies = {
        "Original": create_prompt,
        "Concise": create_concise_prompt,
        "Structured": create_structured_prompt,
        "Instruction": create_instruction_prompt
    }
    
    results = {}
    
    for name, prompt_func in strategies.items():
        print(f"\n{'='*20} {name} Prompt {'='*20}")
        
        prompt = prompt_func(example)
        inputs = tokenizer(prompt, return_tensors="pt")
        inputs = {k: v.to(device) for k, v in inputs.items()}
        
        print(f"Prompt length: {inputs['input_ids'].shape[1]} tokens")
        print(f"Prompt preview: {prompt[:200]}...")
        
        with torch.no_grad():
            outputs = model.generate(
                **inputs,
                max_new_tokens=300,
                temperature=0.3,  # Lower temperature for more focused code
                do_sample=True,
                pad_token_id=tokenizer.eos_token_id
            )
        
        generated = tokenizer.decode(outputs[0], skip_special_tokens=True)
        generated_code = generated[len(prompt):].strip()
        
        # Clean up structured prompt artifacts
        if name == "Structured" and generated_code.startswith("```cpp"):
            generated_code = generated_code[6:].strip()
        if "```" in generated_code:
            generated_code = generated_code.split("```")[0].strip()
        # also remove the things before the first \n, do not use split
        if "\n" in generated_code:
            first_newline_index = generated_code.find("\n")
            if first_newline_index > 0:
                generated_code = generated_code[first_newline_index+1:]

            
        print(f"Generated ({len(generated_code)} chars):\n{generated_code[:500]}...")
        results[name] = generated_code
        
    return results

# Test on a few examples
for i in [0,2]:
    print(f"\n--- Example {i+1} ---")
    example = train_ds[i]
    target_col = 'src_code'

    print(f"Target file: {example['src_filename']}")
    print(f"Thorn: {example['thorn_name']}")

    # Test all prompt strategies
    results = test_prompt_strategies(example, target_col)

    # Show comparison
    print(f"\n{'='*60}")
    print("STRATEGY COMPARISON:")
    for name, result in results.items():
        print(f"\n{name}: {len(result)} chars")
        print(f"Preview: {result[:100]}...")

    print(f"\nActual target length: {len(example[target_col])} chars")
    print(f"Actual preview: {example[target_col][:100]}...")
