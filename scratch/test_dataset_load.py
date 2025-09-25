#!/usr/bin/env python3

import os
from datasets import load_dataset

def load_valid_thorns_from_mapping(thorn_mapping_file):
    """Load valid thorns from thorn_to_tests.txt"""
    valid_thorns = set()
    
    if not os.path.exists(thorn_mapping_file):
        print(f"Error: {thorn_mapping_file} not found!")
        return valid_thorns
    
    with open(thorn_mapping_file, 'r') as f:
        for line in f:
            line = line.strip()
            if line and not line.startswith('#'):
                # Look for lines like "CactusExamples/Poisson: 1 tests"
                if ':' in line and 'tests' in line:
                    thorn_path = line.split(':')[0].strip()
                    valid_thorns.add(thorn_path)
    
    return valid_thorns

def test_dataset_loading():
    """Test loading dataset and filtering"""
    print("Loading HuggingFace dataset...")
    try:
        ds = load_dataset("xinshuo/ET_code_with_context")
        train_ds = ds['train']
        print(f"Dataset loaded successfully. Total examples: {len(train_ds)}")
        
        # Load valid thorns
        valid_thorns = load_valid_thorns_from_mapping('../thorn_to_tests.txt')
        print(f"Valid thorns loaded: {len(valid_thorns)}")
        
        # Filter examples
        valid_examples = []
        for i, example in enumerate(train_ds):
            if example['thorn_name'] in valid_thorns:
                valid_examples.append((i, example))
        
        print(f"Valid examples after filtering: {len(valid_examples)}")
        
        # Show first few valid examples
        print("\nFirst 5 valid examples:")
        for i, (idx, example) in enumerate(valid_examples[:5]):
            print(f"  {i+1}. Index {idx}: {example['thorn_name']} - {example['src_filename']}")
        
        return valid_examples
        
    except Exception as e:
        print(f"Error loading dataset: {e}")
        return []

if __name__ == "__main__":
    test_dataset_loading()
