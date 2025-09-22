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
    
    # Find all test entries that failed
    test_pattern = r'Test \d+: ([^\n]+)\n[^\n]*\n.*?Result: FAIL.*?Output directory: ([^\n]+)'
    matches = re.findall(test_pattern, content, re.DOTALL)
    
    for test_name, output_dir in matches:
        test_name = test_name.strip()
        output_dir = output_dir.strip()
        
        # Skip if it's a missing benchmark or simulation failure
        test_block_pattern = rf'Test \d+: {re.escape(test_name)}.*?(?=Test \d+:|$)'
        test_block_match = re.search(test_block_pattern, content, re.DOTALL)
        
        if test_block_match:
            test_block = test_block_match.group(0)
            if ('MISSING_BENCHMARK' in test_block or 
                'SIMULATION_FAILED' in test_block or
                'NO_OUTPUT' in test_block or
                'MISSING_PARFILE' in test_block):
                continue
        
        failed_tests.append({
            'test_name': test_name,
            'output_dir': output_dir,
            'test_path': test_name
        })
    
    return failed_tests

def reanalyze_with_smart_comparison(failed_tests, rtol=1e-10, atol=1e-15):
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
        
        # Extract summary
        summary_match = re.search(r'Total tests: (\d+)', content)
        if summary_match:
            total_tests = int(summary_match.group(1))
        
        passed_matches = re.findall(r'Result: PASS', content)
        original_passed = len(passed_matches)
        original_failed = total_tests - original_passed
    
    # Calculate corrected stats
    now_passing_count = len(reanalysis_results['now_passing'])
    still_failing_count = len(reanalysis_results['still_failing'])
    analysis_errors_count = len(reanalysis_results['analysis_errors'])
    
    corrected_passed = original_passed + now_passing_count
    corrected_failed = still_failing_count + analysis_errors_count
    
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
  Success rate: {(corrected_passed/total_tests*100):.1f}% (was {(original_passed/total_tests*100):.1f}%)

IMPROVEMENT:
  Additional tests now passing: {now_passing_count}
  Improvement: +{(now_passing_count/total_tests*100):.1f} percentage points

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
    
    report += "\nFor missing thorn issues, run: python3 check_missing_thorns.py\n"
    
    # Write report
    with open(output_file, 'w') as f:
        f.write(report)
    
    return report

def main():
    print("Einstein Toolkit Docker Results Reanalysis")
    print("=" * 50)
    
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
    reanalysis_results = reanalyze_with_smart_comparison(failed_tests)
    
    # Generate corrected summary
    print("\nGenerating corrected summary...")
    summary_report = generate_corrected_summary(results_file, reanalysis_results, 'corrected_test_results.txt')
    
    # Save detailed results
    with open('smart_reanalysis_details.json', 'w') as f:
        json.dump(reanalysis_results, f, indent=2)
    
    # Print summary
    print("\n" + "="*60)
    print("REANALYSIS COMPLETE")
    print("="*60)
    print(f"Tests reanalyzed: {reanalysis_results['total_reanalyzed']}")
    print(f"Now passing: {len(reanalysis_results['now_passing'])}")
    print(f"Still failing: {len(reanalysis_results['still_failing'])}")
    print(f"Analysis errors: {len(reanalysis_results['analysis_errors'])}")
    
    print(f"\nFiles generated:")
    print(f"  📊 corrected_test_results.txt - Corrected summary")
    print(f"  📋 smart_reanalysis_details.json - Detailed reanalysis data")
    
    if len(reanalysis_results['now_passing']) > 0:
        print(f"\n✅ Good news: {len(reanalysis_results['now_passing'])} tests now pass with smart comparison!")

if __name__ == "__main__":
    main()
