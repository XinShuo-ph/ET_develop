#!/usr/bin/env python3

def create_einstein_toolkit_prompt(example, context_char_limit=10000):
    """
    Create a prompt for EinsteinToolkit code generation
    Adapted from load_infer.py but for API usage without custom system prompt
    """
    
    context = example['context'][:context_char_limit] if len(example['context']) > context_char_limit else example['context']
    
    # Since we can't use custom system prompts, include everything in user message
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
```

## Related Code Context:
```
{context}
```

## Instructions:
Generate only the complete C/C++ source code for `{example['src_filename']}`. Include necessary headers, functions, and follow EinsteinToolkit conventions. Do not include any explanations or markdown formatting, just return the raw C/C++ code.

Code:"""
    
    return prompt

def test_prompt_creation():
    """Test prompt creation with mock data"""
    
    # Create mock example data (similar to what we get from the dataset)
    mock_example = {
        'thorn_name': 'CactusExamples/Poisson',
        'src_filename': 'uniform_charge.c',
        'interface': 'IMPLEMENTS: Poisson\nINHERITS: grid\n\nPUBLIC:\nCCTK_REAL phi TYPE=GF\nCCTK_REAL source TYPE=GF',
        'schedule': 'SCHEDULE poisson_uniform_charge AT CCTK_INITIAL\n{\n  LANG: C\n  READS: grid::coordinates\n  WRITES: Poisson::source\n} "Set up uniform charge distribution"',
        'param': 'SHARES: IO\nUSES CCTK_STRING out_dir\n\nRESTRICTED:\nCCTK_REAL charge_density "Charge density"\n{\n  *:* :: "Any value"\n} 1.0',
        'configuration': 'REQUIRES HDF5\nOPTIONAL GSL',
        'context': '#include "cctk.h"\n#include "cctk_Arguments.h"\n#include "cctk_Parameters.h"\n\n// Sample context code for reference\nvoid some_function() {\n  // existing implementation\n}'
    }
    
    print("Testing prompt creation...")
    prompt = create_einstein_toolkit_prompt(mock_example)
    
    print(f"Generated prompt ({len(prompt)} characters):")
    print("=" * 80)
    print(prompt)
    print("=" * 80)
    
    return prompt

if __name__ == "__main__":
    test_prompt_creation()
