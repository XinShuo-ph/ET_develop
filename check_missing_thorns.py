#!/usr/bin/env python3

import os
import sys
import re
import subprocess
import json
from pathlib import Path

def extract_thorns_from_parfile(parfile_path):
    """Extract required thorns from a parameter file"""
    thorns = set()
    
    try:
        with open(parfile_path, 'r', encoding='utf-8', errors='ignore') as f:
            content = f.read()
            
        # Look for ActiveThorns parameter
        # Pattern matches: ActiveThorns = "thorn1 thorn2" or ActiveThorns = "thorn1
        #                                                                    thorn2"
        pattern = r'ActiveThorns\s*=\s*["\']([^"\']+)["\']'
        matches = re.findall(pattern, content, re.IGNORECASE | re.MULTILINE)
        
        for match in matches:
            # Split on whitespace and filter out empty strings
            thorn_list = [t.strip() for t in match.split() if t.strip()]
            thorns.update(thorn_list)
            
        # Also look for multiline ActiveThorns definitions
        multiline_pattern = r'ActiveThorns\s*=\s*["\']([^"\']*(?:\n[^"\']*)*)["\']'
        multiline_matches = re.findall(multiline_pattern, content, re.IGNORECASE | re.MULTILINE | re.DOTALL)
        
        for match in multiline_matches:
            # Remove comments and split on whitespace
            lines = match.split('\n')
            for line in lines:
                # Remove comments (everything after #)
                line = line.split('#')[0].strip()
                thorn_list = [t.strip() for t in line.split() if t.strip()]
                thorns.update(thorn_list)
    
    except Exception as e:
        print(f"Error reading {parfile_path}: {e}")
    
    return thorns

def check_thorns_with_cactus(cactus_exe, parfile_path):
    """Use Cactus to check parameter file and identify missing thorns"""
    missing_thorns = set()
    
    try:
        # Run cactus with -P flag to check parameters
        result = subprocess.run(
            [cactus_exe, '-P', parfile_path],
            capture_output=True,
            text=True,
            timeout=30
        )
        
        # Parse output for missing thorn errors
        output = result.stderr + result.stdout
        
        # Look for "Error: Thorn X not found" patterns
        error_pattern = r'Error:\s+Thorn\s+(\w+)\s+not\s+found'
        matches = re.findall(error_pattern, output, re.IGNORECASE)
        missing_thorns.update(matches)
        
        # Also look for "Thorn X not found" without "Error:" prefix
        error_pattern2 = r'Thorn\s+(\w+)\s+not\s+found'
        matches2 = re.findall(error_pattern2, output, re.IGNORECASE)
        missing_thorns.update(matches2)
        
        # Look for activation failures
        if "Activation failed" in output:
            # This indicates parameter file has issues
            return missing_thorns, False, output
        
        return missing_thorns, True, output
        
    except subprocess.TimeoutExpired:
        return set(), False, "Timeout while checking parameter file"
    except Exception as e:
        return set(), False, f"Error running Cactus: {e}"

def check_test_validity(cactus_exe, test_list_file, output_file="invalid_tests.txt"):
    """Check all tests in the list and identify those with missing thorns"""
    
    if not os.path.exists(test_list_file):
        print(f"Error: Test list file {test_list_file} not found!")
        return
    
    if not os.path.exists(cactus_exe):
        print(f"Error: Cactus executable {cactus_exe} not found!")
        return
    
    print(f"Checking tests for missing thorns using {cactus_exe}")
    print(f"Reading tests from {test_list_file}")
    print("")
    
    invalid_tests = []
    valid_tests = []
    all_missing_thorns = set()
    
    with open(test_list_file, 'r') as f:
        test_paths = [line.strip() for line in f if line.strip() and not line.strip().startswith('#')]
    
    total_tests = len(test_paths)
    
    for i, test_path in enumerate(test_paths, 1):
        print(f"Checking test {i}/{total_tests}: {test_path}")
        
        # Construct parameter file path
        parfile_path = f"arrangements/{test_path}.par"
        
        if not os.path.exists(parfile_path):
            print(f"  ❌ Parameter file not found: {parfile_path}")
            invalid_tests.append({
                'test_path': test_path,
                'reason': 'Parameter file not found',
                'missing_thorns': [],
                'parfile_path': parfile_path
            })
            continue
        
        # Check with Cactus
        missing_thorns, is_valid, cactus_output = check_thorns_with_cactus(cactus_exe, parfile_path)
        
        if missing_thorns:
            print(f"  ❌ Missing thorns: {sorted(missing_thorns)}")
            invalid_tests.append({
                'test_path': test_path,
                'reason': 'Missing thorns',
                'missing_thorns': sorted(missing_thorns),
                'parfile_path': parfile_path
            })
            all_missing_thorns.update(missing_thorns)
        elif not is_valid:
            print(f"  ❌ Invalid parameter file")
            invalid_tests.append({
                'test_path': test_path,
                'reason': 'Invalid parameter file',
                'missing_thorns': [],
                'parfile_path': parfile_path
            })
        else:
            print(f"  ✅ Valid")
            valid_tests.append(test_path)
    
    # Write results
    print(f"\n" + "="*60)
    print("SUMMARY")
    print("="*60)
    print(f"Total tests checked: {total_tests}")
    print(f"Valid tests: {len(valid_tests)}")
    print(f"Invalid tests: {len(invalid_tests)}")
    print(f"All missing thorns: {sorted(all_missing_thorns)}")
    
    # Write invalid tests to file
    with open(output_file, 'w') as f:
        f.write("# Invalid Einstein Toolkit Tests\n")
        f.write("# Generated by check_missing_thorns.py\n")
        f.write(f"# Total tests checked: {total_tests}\n")
        f.write(f"# Valid tests: {len(valid_tests)}\n")
        f.write(f"# Invalid tests: {len(invalid_tests)}\n")
        f.write(f"# All missing thorns: {sorted(all_missing_thorns)}\n")
        f.write("\n")
        
        for test_info in invalid_tests:
            f.write(f"# INVALID: {test_info['test_path']}\n")
            f.write(f"# Reason: {test_info['reason']}\n")
            if test_info['missing_thorns']:
                f.write(f"# Missing thorns: {test_info['missing_thorns']}\n")
            f.write(f"{test_info['test_path']}\n")
            f.write("\n")
    
    # Write valid tests to separate file
    valid_tests_file = "valid_tests.txt"
    with open(valid_tests_file, 'w') as f:
        f.write("# Valid Einstein Toolkit Tests\n")
        f.write("# Generated by check_missing_thorns.py\n")
        f.write(f"# Total valid tests: {len(valid_tests)}\n")
        f.write("\n")
        
        for test_path in valid_tests:
            f.write(f"{test_path}\n")
    
    # Write JSON summary for programmatic use
    summary = {
        'total_tests': total_tests,
        'valid_tests': len(valid_tests),
        'invalid_tests': len(invalid_tests),
        'all_missing_thorns': sorted(all_missing_thorns),
        'invalid_test_details': invalid_tests,
        'valid_test_list': valid_tests
    }
    
    with open('test_check_summary.json', 'w') as f:
        json.dump(summary, f, indent=2)
    
    print(f"\nResults written to:")
    print(f"  Invalid tests: {output_file}")
    print(f"  Valid tests: {valid_tests_file}")
    print(f"  JSON summary: test_check_summary.json")
    
    return len(invalid_tests) == 0

def main():
    if len(sys.argv) < 3:
        print("Usage: python3 check_missing_thorns.py <cactus_exe> <test_list_file> [output_file]")
        print("  cactus_exe: Path to Cactus executable (e.g., ./exe/cactus_sim)")
        print("  test_list_file: File containing test names (e.g., test_names.txt)")
        print("  output_file: Output file for invalid tests (default: invalid_tests.txt)")
        sys.exit(1)
    
    cactus_exe = sys.argv[1]
    test_list_file = sys.argv[2]
    output_file = sys.argv[3] if len(sys.argv) > 3 else "invalid_tests.txt"
    
    all_valid = check_test_validity(cactus_exe, test_list_file, output_file)
    
    # Exit with appropriate code
    sys.exit(0 if all_valid else 1)

if __name__ == "__main__":
    main()
