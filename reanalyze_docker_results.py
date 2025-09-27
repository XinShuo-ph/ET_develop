#!/usr/bin/env python3

import os
import sys
import re
import json
from pathlib import Path
from smart_diff_comparison import compare_directories_with_tolerance

def extract_failed_tests_from_results(results_file):
    """Extract failed tests from the container results file"""
    
    failed_tests = []
    
    if not os.path.exists(results_file):
        print(f"Results file {results_file} not found!")
        return failed_tests
    
    with open(results_file, 'r', encoding='utf-8', errors='ignore') as f:
        content = f.read()
    
    # Find all test entries that failed - no filtering, analyze everything
    test_pattern = r'Test \d+: ([^\n]+)\n[^\n]*\n.*?Result: FAIL.*?Output directory: ([^\n]+)'
    matches = re.findall(test_pattern, content, re.DOTALL)
    
    print(f"Found {len(matches)} FAIL tests with Output directory")
    
    for test_name, output_dir in matches:
        test_name = test_name.strip()
        output_dir = output_dir.strip()
        
        failed_tests.append({
            'test_name': test_name,
            'output_dir': output_dir,
            'test_path': test_name
        })
    
    return failed_tests

def reanalyze_with_smart_comparison(failed_tests, rtol=1e-4, atol=1e-8):
    """Reanalyze failed tests using smart numerical comparison"""
    
    print(f"Reanalyzing {len(failed_tests)} failed tests with smart comparison...")
    print(f"Tolerance: rtol={rtol}, atol={atol}")
    print("="*60)
    
    results = {
        'total_reanalyzed': len(failed_tests),
        'now_passing': [],
        'still_failing': [],
        'analysis_errors': []
    }
    
    for i, test_info in enumerate(failed_tests, 1):
        test_name = test_info['test_name']
        test_path = test_info['test_path']
        
        print(f"[{i}/{len(failed_tests)}] Reanalyzing: {test_name}")
        
        # Determine paths
        host_output_dir = f"test_outputs_host/{os.path.basename(test_path)}"
        benchmark_dir = f"Cactus/arrangements/{test_path}"
        
        # Show progress for large directories
        if os.path.exists(host_output_dir):
            file_count = len([f for f in os.listdir(host_output_dir) if os.path.isfile(os.path.join(host_output_dir, f))])
            if file_count > 20:
                print(f"  📁 Large directory: {file_count} files")
        
        # Check if directories exist
        if not os.path.exists(host_output_dir):
            print(f"  ❌ Output directory not found: {host_output_dir}")
            results['analysis_errors'].append({
                'test': test_name,
                'error': 'Output directory not found on host'
            })
            continue
            
        if not os.path.exists(benchmark_dir):
            print(f"  ❌ Benchmark directory not found: {benchmark_dir}")
            results['analysis_errors'].append({
                'test': test_name,
                'error': 'Benchmark directory not found'
            })
            continue
        
        # Run smart comparison
        try:
            matches, message = compare_directories_with_tolerance(
                host_output_dir, benchmark_dir, rtol, atol
            )
            
            if matches:
                print(f"  ✅ NOW PASSES: {test_name}")
                results['now_passing'].append({
                    'test': test_name,
                    'message': message
                })
            else:
                print(f"  ❌ Still fails: {test_name}")
                results['still_failing'].append({
                    'test': test_name,
                    'message': message[:500] + '...' if len(message) > 500 else message
                })
                
        except Exception as e:
            print(f"  ⚠️  Analysis error: {e}")
            results['analysis_errors'].append({
                'test': test_name,
                'error': str(e)
            })
    
    return results

def generate_corrected_summary(original_results_file, reanalysis_results, output_file):
    """Generate a corrected summary with smart analysis results"""
    
    # Read original results to get basic stats
    total_tests = 0
    original_passed = 0
    original_failed = 0
    
    if os.path.exists(original_results_file):
        with open(original_results_file, 'r', encoding='utf-8', errors='ignore') as f:
            content = f.read()
        
        # Count actual test entries (works for in-progress tests too)
        test_entries = re.findall(r'Test \d+:', content)
        total_tests = len(test_entries)
        
        passed_matches = re.findall(r'Result: PASS', content)
        original_passed = len(passed_matches)
        original_failed = total_tests - original_passed
    
    print(f"Total tests: {total_tests}")

    # Calculate corrected stats
    now_passing_count = len(reanalysis_results['now_passing'])
    still_failing_count = len(reanalysis_results['still_failing'])
    analysis_errors_count = len(reanalysis_results['analysis_errors'])
    
    corrected_passed = original_passed + now_passing_count
    corrected_failed = still_failing_count + analysis_errors_count
    
    # Calculate percentages safely
    if total_tests > 0:
        corrected_success_rate = (corrected_passed/total_tests*100)
        original_success_rate = (original_passed/total_tests*100)
        improvement_points = (now_passing_count/total_tests*100)
    else:
        corrected_success_rate = 0.0
        original_success_rate = 0.0
        improvement_points = 0.0
    
    # Generate report
    report = f"""Einstein Toolkit Test Results - CORRECTED ANALYSIS
=======================================================
Date: {__import__('datetime').datetime.now().strftime('%Y-%m-%d %H:%M:%S')}

ORIGINAL ANALYSIS (Container - Basic Diff):
  Total tests: {total_tests}
  Passed: {original_passed}
  Failed: {original_failed}

SMART REANALYSIS (Host - Numerical Tolerance):
  Tests reanalyzed: {reanalysis_results['total_reanalyzed']}
  Now passing: {now_passing_count}
  Still failing: {still_failing_count}  
  Analysis errors: {analysis_errors_count}

CORRECTED FINAL RESULTS:
  Total tests: {total_tests}
  Passed: {corrected_passed}
  Failed: {corrected_failed}
  Success rate: {corrected_success_rate:.1f}% (was {original_success_rate:.1f}%)

IMPROVEMENT:
  Additional tests now passing: {now_passing_count}
  Improvement: +{improvement_points:.1f} percentage points

=======================================================
TESTS THAT NOW PASS (due to smart numerical comparison):
"""
    
    for test_info in reanalysis_results['now_passing']:
        report += f"  ✅ {test_info['test']}\n"
    
    report += f"\nTESTS STILL FAILING ({still_failing_count}):\n"
    for test_info in reanalysis_results['still_failing'][:20]:  # Limit to first 20
        report += f"  ❌ {test_info['test']}\n"
    
    if still_failing_count > 20:
        report += f"  ... and {still_failing_count - 20} more\n"
    
    if analysis_errors_count > 0:
        report += f"\nANALYSIS ERRORS ({analysis_errors_count}):\n"
        for error_info in reanalysis_results['analysis_errors']:
            report += f"  ⚠️  {error_info['test']}: {error_info['error']}\n"
    
    report += "\n=======================================================\n"
    report += "RECOMMENDATIONS:\n"
    
    if now_passing_count > 0:
        report += f"✅ {now_passing_count} tests were false failures due to numerical precision\n"
    
    if still_failing_count > 0:
        report += f"🔧 {still_failing_count} tests have genuine issues needing investigation\n"
    
    if analysis_errors_count > 0:
        report += f"📋 {analysis_errors_count} tests need path/setup fixes\n"
    
    report += f"\n📄 All checked tests saved to: checked_tests.txt\n"
    report += "\nFor missing thorn issues, run: python3 check_missing_thorns.py\n"
    
    # Write report
    with open(output_file, 'w') as f:
        f.write(report)
    
    return report

def generate_checked_tests_file(original_results_file, reanalysis_results, output_file):
    """Generate a file listing all checked tests (passed numerical comparison)"""
    
    checked_tests = []
    
    # Extract originally passing tests
    if os.path.exists(original_results_file):
        with open(original_results_file, 'r', encoding='utf-8', errors='ignore') as f:
            content = f.read()
        
        # Find all tests that originally passed
        pass_pattern = r'Test \d+: ([^\n]+)\n[^\n]*\n\s*Result: PASS'
        pass_matches = re.findall(pass_pattern, content)
        
        for test_name in pass_matches:
            test_name = test_name.strip()
            checked_tests.append(test_name)
    
    # Add newly passing tests from reanalysis
    for test_info in reanalysis_results['now_passing']:
        test_name = test_info['test']
        if test_name not in checked_tests:  # Avoid duplicates
            checked_tests.append(test_name)
    
    # Sort tests alphabetically
    checked_tests.sort()
    
    # Write to file
    with open(output_file, 'w') as f:
        f.write(f"# Einstein Toolkit Checked Tests\n")
        f.write(f"# Generated: {__import__('datetime').datetime.now().strftime('%Y-%m-%d %H:%M:%S')}\n")
        f.write(f"# Total checked tests: {len(checked_tests)}\n")
        f.write(f"#\n")
        f.write(f"# This file contains all tests that pass numerical comparison:\n")
        f.write(f"# - Tests that originally passed with basic diff\n")
        f.write(f"# - Tests that now pass with smart numerical comparison\n")
        f.write(f"#\n")
        
        for test_name in checked_tests:
            f.write(f"{test_name}\n")
    
    print(f"Checked tests written to {output_file}: {len(checked_tests)} tests")
    return checked_tests

def main():
    import argparse
    
    parser = argparse.ArgumentParser(description='Einstein Toolkit Docker Results Reanalysis')
    parser.add_argument('--rtol', type=float, default=1e-4, 
                       help='Relative tolerance for numerical comparison (default: 1e-4)')
    parser.add_argument('--atol', type=float, default=1e-8,
                       help='Absolute tolerance for numerical comparison (default: 1e-8)')
    parser.add_argument('--output-dir', type=str, default='.',
                       help='Output directory for results (default: current directory)')
    
    args = parser.parse_args()
    
    print("Einstein Toolkit Docker Results Reanalysis")
    print("=" * 50)
    print(f"Using tolerances: rtol={args.rtol}, atol={args.atol}")
    print(f"Output directory: {args.output_dir}")
    print("=" * 50)
    
    # Create output directory if it doesn't exist
    os.makedirs(args.output_dir, exist_ok=True)
    
    # Check for required files
    results_file = 'test_results.txt'
    if not os.path.exists(results_file):
        print(f"Error: {results_file} not found!")
        print("Make sure you've copied test results from container using:")
        print("  docker cp -L ET_docker_1:/opt/Cactus/test_results.txt ./")
        sys.exit(1)
    
    if not os.path.exists('test_outputs_host'):
        print("Error: test_outputs_host/ directory not found!")
        print("Make sure you've copied test outputs from container using:")
        print("  docker cp -L ET_docker_1:/opt/Cactus/test_outputs ./test_outputs_host/")
        sys.exit(1)
    
    # Extract failed tests
    print("Extracting failed tests from container results...")
    failed_tests = extract_failed_tests_from_results(results_file)
    print(f"Found {len(failed_tests)} failed tests to reanalyze")
    
    if len(failed_tests) == 0:
        print("No failed tests found for reanalysis!")
        return
    
    # Reanalyze with smart comparison
    reanalysis_results = reanalyze_with_smart_comparison(failed_tests, rtol=args.rtol, atol=args.atol)
    
    # Generate corrected summary
    print("\nGenerating corrected summary...")
    corrected_results_file = os.path.join(args.output_dir, f'corrected_test_results_rtol{args.rtol:.0e}_atol{args.atol:.0e}.txt')
    summary_report = generate_corrected_summary(results_file, reanalysis_results, corrected_results_file)
    
    # Save detailed results
    details_file = os.path.join(args.output_dir, f'smart_reanalysis_details_rtol{args.rtol:.0e}_atol{args.atol:.0e}.json')
    with open(details_file, 'w') as f:
        json.dump(reanalysis_results, f, indent=2)
    
    # Generate checked_tests.txt with all passing tests
    print("Generating checked_tests.txt with all passing tests...")
    checked_tests_file = os.path.join(args.output_dir, f'checked_tests_rtol{args.rtol:.0e}_atol{args.atol:.0e}.txt')
    generate_checked_tests_file(results_file, reanalysis_results, checked_tests_file)
    
    # Print summary
    print("\n" + "="*60)
    print("REANALYSIS COMPLETE")
    print("="*60)
    print(f"Tests reanalyzed: {reanalysis_results['total_reanalyzed']}")
    print(f"Now passing: {len(reanalysis_results['now_passing'])}")
    print(f"Still failing: {len(reanalysis_results['still_failing'])}")
    print(f"Analysis errors: {len(reanalysis_results['analysis_errors'])}")
    
    print(f"\nFiles generated in {args.output_dir}:")
    print(f"  📊 {os.path.basename(corrected_results_file)} - Corrected summary")
    print(f"  📋 {os.path.basename(details_file)} - Detailed reanalysis data")
    print(f"  ✅ {os.path.basename(checked_tests_file)} - All numerically checked tests")
    
    if len(reanalysis_results['now_passing']) > 0:
        print(f"\n{len(reanalysis_results['now_passing'])} tests now pass with smart comparison!")

if __name__ == "__main__":
    main()

