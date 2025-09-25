#!/usr/bin/env python3

import os

def debug_thorn_parsing():
    """Debug the thorn parsing to see what's happening"""
    
    mapping_file = "/Users/bytedance/ET_develop/thorn_to_tests.txt"
    thorn_mapping = {}
    current_thorn = None
    
    if not os.path.exists(mapping_file):
        print(f"File not found: {mapping_file}")
        return
    
    with open(mapping_file, 'r') as f:
        for line_num, line in enumerate(f, 1):
            original_line = line
            line = line.strip()
            
            # Skip empty lines and comments
            if not line or line.startswith('#'):
                continue
            
            # Debug output for first 20 lines
            if line_num <= 20:
                print(f"Line {line_num}: '{original_line.rstrip()}'")
                print(f"  Stripped: '{line}'")
                print(f"  Starts with '  ': {original_line.startswith('  ')}")
                print(f"  Contains ':' and 'tests': {':' in line and 'tests' in line}")
            
            # Check if this is a thorn header line
            if ':' in line and 'tests' in line:
                current_thorn = line.split(':')[0].strip()
                thorn_mapping[current_thorn] = []
                if line_num <= 20:
                    print(f"  --> Found thorn: {current_thorn}")
            
            # Check if this is a test line (starts with spaces)
            elif original_line.startswith('  ') and current_thorn:
                test_path = line
                if test_path and not test_path.startswith('#'):
                    thorn_mapping[current_thorn].append(test_path)
                    if line_num <= 20:
                        print(f"  --> Added test: {test_path}")
    
    print(f"\nTotal thorns found: {len(thorn_mapping)}")
    
    # Show first few thorns and their tests
    count = 0
    for thorn, tests in thorn_mapping.items():
        if count >= 3:
            break
        print(f"\n{thorn}: {len(tests)} tests")
        for test in tests:
            print(f"  {test}")
        count += 1

if __name__ == "__main__":
    debug_thorn_parsing()
