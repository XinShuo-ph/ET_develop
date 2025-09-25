#!/usr/bin/env python3
"""
Test script to demonstrate the enhanced prompt with documentation context.
"""

import sys
import os
sys.path.append('..')

from datasets import load_dataset

def create_einstein_toolkit_prompt(example, context_char_limit=8000, doc_char_limit=15000):
    """Create a prompt for EinsteinToolkit code generation with rich documentation context"""
    # Limit context to avoid token overflow while preserving documentation
    context = example['context'][:context_char_limit] if len(example['context']) > context_char_limit else example['context']
    
    # Include documentation context from the enhanced dataset
    doc_context = ""
    if 'combined_doc_context' in example and example['combined_doc_context'].strip():
        doc_context = example['combined_doc_context'][:doc_char_limit] if len(example['combined_doc_context']) > doc_char_limit else example['combined_doc_context']
    
    prompt = f"""You are an expert C/C++ developer working on EinsteinToolkit, a codebase for numerical relativity simulations.

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
```"""

    # Add documentation context if available
    if doc_context:
        prompt += f"""

## Documentation Context:
{doc_context}"""

    prompt += f"""

## Related Code Context:
```
{context}
```

## Instructions:
Generate only the complete C/C++ source code for `{example['src_filename']}`. Include necessary headers, functions, and follow EinsteinToolkit conventions. 

Key EinsteinToolkit patterns to follow:
- Use DECLARE_CCTK_ARGUMENTS and DECLARE_CCTK_PARAMETERS macros
- Access grid variables through existing framework variables (avoid redeclaring existing grid vars like 'r')
- Follow proper CCTK function signatures and conventions
- Use CCTK_GFINDEX3D for array indexing
- Include appropriate error handling with CCTK_WARN

IMPORTANT: Return ONLY the raw C/C++ source code. Do NOT use markdown code blocks (```c or ```). Do NOT include any explanations, comments outside the code, or formatting. Just return the plain C/C++ source code that can be directly saved to a .c file.

Code:"""
    
    return prompt

def main():
    print("Loading enhanced dataset with documentation...")
    
    try:
        ds = load_dataset("xinshuo/ET_code_with_context_doc")
        train_ds = ds['train']
        print(f"Dataset loaded: {len(train_ds)} examples")
    except Exception as e:
        print(f"Error loading dataset: {e}")
        return
    
    # Find a good example to test (CactusExamples/Poisson)
    print("\nLooking for CactusExamples/Poisson examples...")
    poisson_examples = [ex for ex in train_ds if ex['thorn_name'] == 'CactusExamples/Poisson']
    
    if not poisson_examples:
        print("No CactusExamples/Poisson examples found!")
        return
    
    example = poisson_examples[0]  # Take the first one
    print(f"Testing with: {example['thorn_name']} - {example['src_filename']}")
    
    # Show documentation context info
    if example.get('combined_doc_context', '').strip():
        doc_length = len(example['combined_doc_context'])
        print(f"Documentation context available: {doc_length} characters")
        if example.get('readme_filename'):
            print(f"  - README: {example['readme_filename']}")
        if example.get('doc_tex_filenames'):
            print(f"  - .tex files: {example['doc_tex_filenames']}")
    else:
        print("No documentation context available")
    
    # Create the enhanced prompt
    print("\nCreating enhanced prompt...")
    prompt = create_einstein_toolkit_prompt(example)
    print(f"Prompt created: {len(prompt)} characters")
    
    # Save prompt for inspection
    prompt_file = "enhanced_prompt_sample.txt"
    with open(prompt_file, 'w') as f:
        f.write(prompt)
    print(f"Prompt saved to: {prompt_file}")
    
    # Show a preview of the documentation section
    print("\n=== DOCUMENTATION SECTION PREVIEW ===")
    if 'Documentation Context:' in prompt:
        doc_start = prompt.find('## Documentation Context:')
        doc_end = prompt.find('## Related Code Context:', doc_start)
        if doc_start != -1 and doc_end != -1:
            doc_section = prompt[doc_start:doc_end].strip()
            print(doc_section[:1000] + "..." if len(doc_section) > 1000 else doc_section)
        else:
            print("Documentation section not found in expected format")
    else:
        print("No documentation context in this example")

if __name__ == "__main__":
    main()
