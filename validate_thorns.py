#!/usr/bin/env python3

import os
import sys
import re
from datasets import load_dataset

def parse_thornlist_activation(thornlist_file):
    """Parse ThornList file to get all activated (non-commented) thorns"""
    
    activated_thorns = set()
    
    if not os.path.exists(thornlist_file):
        return activated_thorns
    
    with open(thornlist_file, 'r') as f:
        for line in f:
            line = line.strip()
            
            # Skip empty lines and comments
            if not line or line.startswith('#') or line.startswith('!'):
                continue
            
            # Look for thorn paths (contain '/')
            if '/' in line:
                # Take the first part (the thorn path)
                thorn_path = line.split()[0]
                activated_thorns.add(thorn_path)
    
    return activated_thorns

def load_hf_dataset_thorns(dataset_name="xinshuo/ET_code"):
    """Load HuggingFace dataset and extract unique thorn names"""
    
    try:
        print(f"Loading HuggingFace dataset: {dataset_name}")
        dataset = load_dataset(dataset_name)
        
        # Extract unique thorn names from the dataset
        if 'train' in dataset:
            thorn_names = set(dataset['train']['thorn_name'])
        else:
            # If no train split, try to get from the main dataset
            thorn_names = set(dataset['thorn_name'])
        
        print(f"Found {len(thorn_names)} unique thorns in HuggingFace dataset")
        return thorn_names
        
    except Exception as e:
        print(f"Error loading HuggingFace dataset: {e}")
        return set()

def validate_thorns_existence(thorn_mapping_file, cactus_base_dir="Cactus"):
    """Validate that all thorns in the mapping file actually exist and are properly configured"""
    
    if not os.path.exists(thorn_mapping_file):
        print(f"Error: {thorn_mapping_file} not found!")
        return False
    
    if not os.path.exists(cactus_base_dir):
        print(f"Error: {cactus_base_dir} directory not found!")
        return False
    
    print(f"Validating thorns from {thorn_mapping_file}")
    print(f"Checking against {cactus_base_dir}/arrangements/")
    print("=" * 80)
    
    # Load additional validation data
    thornlist_file = f"{cactus_base_dir}/configs/sim/ThornList"
    activated_thorns = parse_thornlist_activation(thornlist_file)
    print(f"Found {len(activated_thorns)} activated thorns in ThornList")
    
    hf_dataset_thorns = load_hf_dataset_thorns()
    print("=" * 80)
    
    # Read thorn mapping file and extract thorn names
    thorns = []
    with open(thorn_mapping_file, 'r') as f:
        for line in f:
            line = line.strip()
            if line and not line.startswith('#'):
                # Look for lines like "CactusExamples/Poisson: 1 tests"
                if ':' in line and 'tests' in line:
                    thorn_path = line.split(':')[0].strip()
                    thorns.append(thorn_path)
    
    print(f"Found {len(thorns)} thorns to validate\n")
    
    # Validation results
    results = {
        'directory_exists': [],
        'directory_missing': [],
        'thornlist_activated': [],
        'thornlist_missing': [],
        'hf_dataset_present': [],
        'hf_dataset_missing': []
    }
    
    for i, thorn_path in enumerate(thorns, 1):
        print(f"[{i}/{len(thorns)}] Validating: {thorn_path}")
        
        # Check 1: Directory existence
        full_thorn_path = f"{cactus_base_dir}/arrangements/{thorn_path}"
        dir_exists = os.path.exists(full_thorn_path) and os.path.isdir(full_thorn_path)
        
        if dir_exists:
            print(f"  ✅ DIRECTORY: {full_thorn_path}")
            results['directory_exists'].append(thorn_path)
        else:
            print(f"  ❌ DIRECTORY: {full_thorn_path}")
            results['directory_missing'].append(thorn_path)
        
        # Check 2: ThornList activation
        if thorn_path in activated_thorns:
            print(f"  ✅ THORNLIST: Activated")
            results['thornlist_activated'].append(thorn_path)
        else:
            print(f"  ❌ THORNLIST: Not activated or missing")
            results['thornlist_missing'].append(thorn_path)
        
        # Check 3: HuggingFace dataset presence
        if hf_dataset_thorns and thorn_path in hf_dataset_thorns:
            print(f"  ✅ HF_DATASET: Present")
            results['hf_dataset_present'].append(thorn_path)
        elif hf_dataset_thorns:
            print(f"  ❌ HF_DATASET: Missing")
            results['hf_dataset_missing'].append(thorn_path)
        else:
            print(f"  ⚠️  HF_DATASET: Dataset not loaded")
        
        print()  # Empty line for readability
    
    # Summary
    print("=" * 80)
    print("COMPREHENSIVE VALIDATION SUMMARY")
    print("=" * 80)
    print(f"Total thorns checked: {len(thorns)}")
    print()
    
    # Directory existence summary
    print(f"📁 DIRECTORY EXISTENCE:")
    print(f"  ✅ Exists: {len(results['directory_exists'])}")
    print(f"  ❌ Missing: {len(results['directory_missing'])}")
    
    # ThornList activation summary
    print(f"\n📋 THORNLIST ACTIVATION:")
    print(f"  ✅ Activated: {len(results['thornlist_activated'])}")
    print(f"  ❌ Not activated: {len(results['thornlist_missing'])}")
    
    # HuggingFace dataset summary
    if hf_dataset_thorns:
        print(f"\n🤗 HUGGINGFACE DATASET:")
        print(f"  ✅ Present: {len(results['hf_dataset_present'])}")
        print(f"  ❌ Missing: {len(results['hf_dataset_missing'])}")
    else:
        print(f"\n🤗 HUGGINGFACE DATASET: ⚠️  Dataset not available")
    
    # Detailed issue reporting
    if results['directory_missing']:
        print(f"\n❌ THORNS WITH MISSING DIRECTORIES:")
        for thorn in results['directory_missing']:
            print(f"  {thorn}")
    
    if results['thornlist_missing']:
        print(f"\n❌ THORNS NOT ACTIVATED IN THORNLIST:")
        for thorn in results['thornlist_missing']:
            print(f"  {thorn}")
    
    if hf_dataset_thorns and results['hf_dataset_missing']:
        print(f"\n❌ THORNS MISSING FROM HUGGINGFACE DATASET:")
        for thorn in results['hf_dataset_missing']:
            print(f"  {thorn}")
    
    # Perfect thorns (pass all checks)
    perfect_thorns = []
    for thorn in thorns:
        if (thorn in results['directory_exists'] and 
            thorn in results['thornlist_activated'] and 
            (not hf_dataset_thorns or thorn in results['hf_dataset_present'])):
            perfect_thorns.append(thorn)
    
    print(f"\n✨ PERFECT THORNS (pass all checks): {len(perfect_thorns)}")
    if len(perfect_thorns) <= 10:
        for thorn in perfect_thorns:
            print(f"  {thorn}")
    else:
        for thorn in perfect_thorns[:5]:
            print(f"  {thorn}")
        print(f"  ... and {len(perfect_thorns) - 5} more")
    
    # Overall success rate
    success_rate = len(perfect_thorns) / len(thorns) * 100 if thorns else 0
    print(f"\n📊 OVERALL SUCCESS RATE: {success_rate:.1f}% ({len(perfect_thorns)}/{len(thorns)})")
    
    return len(perfect_thorns) == len(thorns)

def main():
    thorn_mapping_file = 'thorn_to_tests.txt'
    cactus_base_dir = 'Cactus'
    
    if len(sys.argv) > 1:
        thorn_mapping_file = sys.argv[1]
    if len(sys.argv) > 2:
        cactus_base_dir = sys.argv[2]
    
    all_valid = validate_thorns_existence(thorn_mapping_file, cactus_base_dir)
    
    print(f"\n🎯 FINAL RESULT: {'All thorns pass comprehensive validation!' if all_valid else 'Some thorns failed validation checks!'}")
    print("Validation includes: directory existence, ThornList activation, and HuggingFace dataset presence")
    
    # Exit with appropriate code
    sys.exit(0 if all_valid else 1)

if __name__ == "__main__":
    main()
