#!/usr/bin/env python3

import os
import re
import json
from pathlib import Path
from collections import defaultdict, Counter

def analyze_test_results(results_file):
    """Analyze the test results file to categorize failures"""
    
    if not os.path.exists(results_file):
        print(f"Results file {results_file} not found!")
        return
    
    print(f"Analyzing test results from: {results_file}")
    print("="*60)
    
    failure_categories = {
        'numerical_precision': [],
        'missing_thorns': [],
        'simulation_failed': [],
        'missing_files': [],
        'other': []
    }
    
    passed_tests = []
    total_tests = 0
    
    with open(results_file, 'r', encoding='utf-8', errors='ignore') as f:
        content = f.read()
    
    # Split by test entries
    test_blocks = re.split(r'Test \d+:', content)[1:]  # Skip header
    
    for block in test_blocks:
        total_tests += 1
        
        # Extract test name
        test_name_match = re.search(r'^([^\n]+)', block.strip())
        if not test_name_match:
            continue
        test_name = test_name_match.group(1).strip()
        
        # Check result
        if 'Result: PASS' in block:
            passed_tests.append(test_name)
        elif 'Result: SIMULATION_FAILED' in block:
            failure_categories['simulation_failed'].append(test_name)
        elif 'Result: MISSING_PARFILE' in block:
            failure_categories['missing_files'].append(test_name)
        elif 'Result: FAIL' in block:
            # Analyze the type of failure
            if is_numerical_precision_failure(block):
                failure_categories['numerical_precision'].append(test_name)
            elif 'Thorn' in block and 'not found' in block:
                failure_categories['missing_thorns'].append(test_name)
            else:
                failure_categories['other'].append(test_name)
        else:
            failure_categories['other'].append(test_name)
    
    # Print summary
    print(f"TOTAL TESTS ANALYZED: {total_tests}")
    print(f"PASSED: {len(passed_tests)}")
    print(f"FAILED: {total_tests - len(passed_tests)}")
    print("")
    
    print("FAILURE BREAKDOWN:")
    print("-" * 40)
    
    for category, tests in failure_categories.items():
        if tests:
            print(f"{category.upper().replace('_', ' ')}: {len(tests)}")
            if len(tests) <= 10:
                for test in tests:
                    print(f"  - {test}")
            else:
                for test in tests[:5]:
                    print(f"  - {test}")
                print(f"  ... and {len(tests) - 5} more")
            print("")
    
    return {
        'total_tests': total_tests,
        'passed_tests': len(passed_tests),
        'failed_tests': total_tests - len(passed_tests),
        'failure_breakdown': {k: len(v) for k, v in failure_categories.items()},
        'failure_details': failure_categories,
        'passed_test_list': passed_tests
    }

def is_numerical_precision_failure(test_block):
    """Determine if a failure is due to numerical precision differences"""
    
    # Look for characteristic patterns of numerical differences
    numerical_patterns = [
        r'\d+\.\d+e[-+]\d+',  # Scientific notation
        r'\d+\.\d{10,}',      # High precision decimals
        r'[<>]\s+\d+\s+\d+\s+\d+\s+\d+\s+[-\d\.\-e\+\s]+',  # Data columns with numbers
    ]
    
    # If there are differences involving many numbers, likely precision issue
    for pattern in numerical_patterns:
        matches = re.findall(pattern, test_block)
        if len(matches) > 5:  # Lots of numerical differences
            return True
    
    # Check for specific precision difference indicators
    precision_indicators = [
        'e-05',  # Scientific notation differences
        'e-06',
        'e-07',
        'e-08',
        'e-09',
        'e-10',
        'e-11',
        'e-12',
        'e-13',
        'e-14',
        'e-15',
    ]
    
    for indicator in precision_indicators:
        if indicator in test_block:
            return True
    
    return False

def analyze_log_failures(log_dir):
    """Analyze log files to find missing thorn patterns"""
    
    print(f"\nAnalyzing log files in: {log_dir}")
    print("="*60)
    
    missing_thorns = Counter()
    simulation_errors = []
    
    log_path = Path(log_dir)
    if not log_path.exists():
        print(f"Log directory {log_dir} not found!")
        return
    
    log_files = list(log_path.rglob('*.log'))
    print(f"Found {len(log_files)} log files")
    
    for log_file in log_files:
        try:
            with open(log_file, 'r', encoding='utf-8', errors='ignore') as f:
                content = f.read()
            
            # Find missing thorns
            thorn_errors = re.findall(r'Error:\s+Thorn\s+(\w+)\s+not\s+found', content, re.IGNORECASE)
            for thorn in thorn_errors:
                missing_thorns[thorn] += 1
            
            # Find other simulation errors
            if 'MPI_ABORT was invoked' in content:
                simulation_errors.append(log_file.name)
            elif 'Activation failed' in content:
                simulation_errors.append(log_file.name)
        
        except Exception as e:
            print(f"Error reading {log_file}: {e}")
    
    print("\nMISSING THORNS (by frequency):")
    print("-" * 40)
    for thorn, count in missing_thorns.most_common():
        print(f"  {thorn}: {count} tests")
    
    print(f"\nSIMULATION ERRORS: {len(simulation_errors)}")
    if simulation_errors:
        print("Files with simulation errors:")
        for error_file in simulation_errors[:10]:
            print(f"  - {error_file}")
        if len(simulation_errors) > 10:
            print(f"  ... and {len(simulation_errors) - 10} more")
    
    return {
        'missing_thorns': dict(missing_thorns),
        'simulation_errors': simulation_errors
    }

def main():
    print("Einstein Toolkit Test Failure Analysis")
    print("=" * 50)
    
    # Analyze test results
    results_analysis = analyze_test_results('test_results.txt')
    
    # Analyze log files
    log_analysis = analyze_log_failures('log_files_host')
    
    # Combine and save analysis
    complete_analysis = {
        'test_results_analysis': results_analysis,
        'log_analysis': log_analysis,
        'summary': {
            'total_tests': results_analysis.get('total_tests', 0),
            'passed_tests': results_analysis.get('passed_tests', 0),
            'major_failure_causes': {
                'numerical_precision': results_analysis['failure_breakdown'].get('numerical_precision', 0),
                'missing_thorns': results_analysis['failure_breakdown'].get('missing_thorns', 0),
                'simulation_failed': results_analysis['failure_breakdown'].get('simulation_failed', 0)
            },
            'most_problematic_thorns': list(log_analysis['missing_thorns'].keys())[:10]
        }
    }
    
    # Save detailed analysis
    with open('failure_analysis.json', 'w') as f:
        json.dump(complete_analysis, f, indent=2)
    
    print("\n" + "="*60)
    print("ANALYSIS COMPLETE")
    print("="*60)
    print(f"Total tests: {complete_analysis['summary']['total_tests']}")
    print(f"Passed: {complete_analysis['summary']['passed_tests']}")
    print(f"Failed: {complete_analysis['summary']['total_tests'] - complete_analysis['summary']['passed_tests']}")
    print("")
    print("Major failure causes:")
    for cause, count in complete_analysis['summary']['major_failure_causes'].items():
        if count > 0:
            print(f"  {cause.replace('_', ' ').title()}: {count}")
    print("")
    print("Most problematic missing thorns:")
    for thorn in complete_analysis['summary']['most_problematic_thorns'][:5]:
        count = log_analysis['missing_thorns'][thorn]
        print(f"  {thorn}: {count} tests")
    
    print(f"\nDetailed analysis saved to: failure_analysis.json")
    print("\nRecommendations:")
    
    if complete_analysis['summary']['major_failure_causes']['numerical_precision'] > 0:
        print("  ✅ Use smart_diff_comparison.py (already implemented in run_all_tests.sh)")
    
    if complete_analysis['summary']['major_failure_causes']['missing_thorns'] > 0:
        print("  🔧 Run: python3 check_missing_thorns.py ./exe/cactus_sim test_names.txt")
        print("  🔧 Then use: ./run_all_tests.sh valid_tests.txt")
    
    if complete_analysis['summary']['major_failure_causes']['simulation_failed'] > 0:
        print("  📋 Review parameter files for tests that fail to run")

if __name__ == "__main__":
    main()

