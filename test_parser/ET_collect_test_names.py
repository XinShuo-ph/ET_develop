#!/usr/bin/env python3

import os
import re

def parse_thornlist(thornlist_path):
    """Parse the thornlist file to extract thorn information."""
    thorns = []
    
    with open(thornlist_path, 'r') as f:
        lines = f.readlines()
    
    current_url = None
    in_checkout_section = False
    
    for line in lines:
        line = line.strip()
        
        # Skip empty lines and comments
        if not line or line.startswith('#'):
            continue
        
        # Look for URL definition
        if line.startswith('!URL'):
            current_url = line.split('=')[1].strip()
        
        # Check if we're entering a checkout section
        elif line.startswith('!CHECKOUT'):
            in_checkout_section = True
            continue
        
        # If we're in a checkout section and have a URL, process thorn names
        elif in_checkout_section and current_url and not line.startswith('!'):
            # Skip disabled thorns
            if line.startswith('#DISABLED'):
                continue
                
            # Split by whitespace and take the first part as the thorn path
            parts = line.split()
            if parts and '/' in parts[0]:
                thorn_name = parts[0]
                thorns.append({
                    'thorn_name': thorn_name,
                    'url': current_url
                })
        
        # If we encounter a new target or type, we're no longer in the checkout section
        elif line.startswith('!TARGET') or line.startswith('!TYPE'):
            in_checkout_section = False
    
    return thorns

def find_benchmark_tests(base_dir):
    """Find all tests that have benchmark result folders."""
    benchmark_tests = []
    
    # Parse the thornlist
    thornlist_path = os.path.join(base_dir, "thornlists/einsteintoolkit.th")
    if not os.path.exists(thornlist_path):
        print(f"Thornlist not found at {thornlist_path}")
        return benchmark_tests
    
    thorns = parse_thornlist(thornlist_path)
    print(f"Found {len(thorns)} thorns in the thornlist.")
    
    arrangements_dir = os.path.join(base_dir, "arrangements")
    
    for thorn_info in thorns:
        thorn_name = thorn_info['thorn_name']
        thorn_path = os.path.join(arrangements_dir, thorn_name)
        
        if not os.path.exists(thorn_path):
            continue
        
        # Look for test directory
        test_dir = os.path.join(thorn_path, 'test')
        if not os.path.exists(test_dir):
            continue
        
        # Find .par files and check if they have corresponding benchmark folders
        for file in os.listdir(test_dir):
            if file.endswith('.par'):
                test_name = file[:-4]  # Remove .par extension
                
                # Check if there's a corresponding benchmark folder
                benchmark_folder = os.path.join(test_dir, test_name)
                if os.path.isdir(benchmark_folder):
                    full_test_path = f"{thorn_name}/test/{test_name}"
                    benchmark_tests.append(full_test_path)
                    print(f"Found benchmark test: {full_test_path}")
    
    return benchmark_tests

def main():
    # Use the current Cactus directory
    base_dir = "./Cactus"
    
    # Find all benchmark tests
    test_names = find_benchmark_tests(base_dir)
    
    # Write to file
    output_file = "test_names.txt"
    with open(output_file, 'w') as f:
        for test in test_names:
            f.write(f"{test}\n")
    
    print(f"\nFound {len(test_names)} test names")
    print(f"Test names written to {output_file}")

if __name__ == "__main__":
    main()
