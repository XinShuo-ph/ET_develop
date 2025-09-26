#!/usr/bin/env python3
"""
Analyze Einstein Toolkit evaluation results from JSON files.
Creates a table of results sorted by total score.
"""

import json
import argparse
import os
import sys
from pathlib import Path
from typing import List, Dict, Any

try:
    from datasets import Dataset
    DATASETS_AVAILABLE = True
except ImportError:
    DATASETS_AVAILABLE = False


def load_results(file_path: str) -> List[Dict[str, Any]]:
    """Load results from JSON file."""
    with open(file_path, 'r') as f:
        return json.load(f)


def extract_scores(result: Dict[str, Any]) -> Dict[str, float]:
    """Extract scores from a result entry, handling both old and new formats."""
    score_result = result.get('score_result', {})
    
    # Basic scores always present
    scores = {
        'build_score': score_result.get('build_score', 0.0),
        'overall_score': score_result.get('overall_score', 0.0)
    }
    
    # Check if new format with separate test_run_score and test_accuracy_score
    if 'test_run_score' in score_result and 'test_accuracy_score' in score_result:
        scores['test_run_score'] = score_result.get('test_run_score', 0.0)
        scores['test_accuracy_score'] = score_result.get('test_accuracy_score', 0.0)
        scores['test_score'] = scores['test_run_score'] + scores['test_accuracy_score']
    else:
        # Old format with combined test_score
        scores['test_score'] = score_result.get('test_score', 0.0)
        scores['test_run_score'] = None  # Not available in old format
        scores['test_accuracy_score'] = None  # Not available in old format
    
    return scores


def analyze_results(results: List[Dict[str, Any]]) -> List[Dict[str, Any]]:
    """Analyze and format results for display."""
    analyzed = []
    
    for result in results:
        scores = extract_scores(result)
        
        # Extract basic info
        entry = {
            'thorn_name': result.get('thorn_name', 'Unknown'),
            'src_filename': result.get('src_filename', 'Unknown'),
            'build_score': scores['build_score'],
            'test_score': scores['test_score'],
            'overall_score': scores['overall_score']
        }
        
        # Add detailed test scores if available (new format)
        if scores['test_run_score'] is not None:
            entry['test_run_score'] = scores['test_run_score']
            entry['test_accuracy_score'] = scores['test_accuracy_score']
        
        # Add worker info if present (parallel results)
        if 'worker_id' in result:
            entry['worker_id'] = result.get('worker_id')
        
        # Add index info
        entry['example_index'] = result.get('example_index', 0)
        
        analyzed.append(entry)
    
    # Sort by total score (descending)
    analyzed.sort(key=lambda x: x['overall_score'], reverse=True)
    
    return analyzed


def print_table(results: List[Dict[str, Any]], show_detailed: bool = False):
    """Print results in a formatted table."""
    if not results:
        print("No results to display.")
        return
    
    # Check if any results have detailed test scores
    has_detailed = any('test_run_score' in r for r in results)
    has_worker_id = any('worker_id' in r for r in results)
    
    # Determine table format
    if show_detailed and has_detailed:
        # Detailed format with separate test scores
        header = "Thorn Name".ljust(35) + "Source File".ljust(25) + "Build".ljust(8) + "Test Run".ljust(10) + "Test Acc".ljust(10) + "Total".ljust(8)
        if has_worker_id:
            header = "Worker".ljust(8) + header
        print(header)
        print("=" * len(header))
        
        for result in results:
            thorn = result['thorn_name'][:34]
            src_file = result['src_filename'][:24]
            build = f"{result['build_score']:.1f}"
            test_run = f"{result.get('test_run_score', 0.0):.1f}"
            test_acc = f"{result.get('test_accuracy_score', 0.0):.1f}"
            total = f"{result['overall_score']:.1f}"
            
            line = thorn.ljust(35) + src_file.ljust(25) + build.ljust(8) + test_run.ljust(10) + test_acc.ljust(10) + total.ljust(8)
            if has_worker_id:
                worker = str(result.get('worker_id', '-'))
                line = worker.ljust(8) + line
            print(line)
    else:
        # Simple format with combined test score
        header = "Thorn Name".ljust(35) + "Source File".ljust(25) + "Build".ljust(8) + "Test".ljust(8) + "Total".ljust(8)
        if has_worker_id:
            header = "Worker".ljust(8) + header
        print(header)
        print("=" * len(header))
        
        for result in results:
            thorn = result['thorn_name'][:34]
            src_file = result['src_filename'][:24]
            build = f"{result['build_score']:.1f}"
            test = f"{result['test_score']:.1f}"
            total = f"{result['overall_score']:.1f}"
            
            line = thorn.ljust(35) + src_file.ljust(25) + build.ljust(8) + test.ljust(8) + total.ljust(8)
            if has_worker_id:
                worker = str(result.get('worker_id', '-'))
                line = worker.ljust(8) + line
            print(line)


def print_summary(results: List[Dict[str, Any]]):
    """Print summary statistics."""
    if not results:
        return
    
    total_examples = len(results)
    avg_overall = sum(r['overall_score'] for r in results) / total_examples
    avg_build = sum(r['build_score'] for r in results) / total_examples
    avg_test = sum(r['test_score'] for r in results) / total_examples
    
    # Count success rates
    build_success = len([r for r in results if r['build_score'] > 0])
    test_success = len([r for r in results if r['test_score'] > 0])
    
    print(f"\nSUMMARY STATISTICS")
    print("=" * 50)
    print(f"Total examples: {total_examples}")
    print(f"Average overall score: {avg_overall:.1f}/100")
    print(f"Average build score: {avg_build:.1f}")
    print(f"Average test score: {avg_test:.1f}")
    print(f"Build success rate: {build_success}/{total_examples} ({100*build_success/total_examples:.1f}%)")
    print(f"Test success rate: {test_success}/{total_examples} ({100*test_success/total_examples:.1f}%)")
    
    # Score distribution
    score_ranges = [(90, 100), (80, 90), (70, 80), (60, 70), (50, 60), (0, 50)]
    print(f"\nScore Distribution:")
    for low, high in score_ranges:
        count = len([r for r in results if low <= r['overall_score'] < high])
        if high == 100:
            count = len([r for r in results if low <= r['overall_score'] <= high])
        print(f"  {low}-{high}: {count} examples ({100*count/total_examples:.1f}%)")


def upload_to_huggingface(results: List[Dict[str, Any]], dataset_name: str = "xinshuo/ET_evaluated"):
    """Upload the evaluation results to HuggingFace as a dataset."""
    if not DATASETS_AVAILABLE:
        print("Error: datasets library not available. Install with: pip install datasets")
        return False
    
    if not results:
        print("Error: No results to upload.")
        return False
    
    try:
        # Prepare data for HuggingFace dataset
        dataset_data = {
            'thorn_name': [],
            'src_filename': [],
            'build_score': [],
            'test_score': [],
            'overall_score': [],
            'example_index': []
        }
        
        # Check if we have detailed test scores
        has_detailed = any('test_run_score' in r for r in results)
        if has_detailed:
            dataset_data['test_run_score'] = []
            dataset_data['test_accuracy_score'] = []
        
        # Check if we have worker IDs
        has_worker_id = any('worker_id' in r for r in results)
        if has_worker_id:
            dataset_data['worker_id'] = []
        
        # Fill the dataset with results
        for result in results:
            dataset_data['thorn_name'].append(result['thorn_name'])
            dataset_data['src_filename'].append(result['src_filename'])
            dataset_data['build_score'].append(result['build_score'])
            dataset_data['test_score'].append(result['test_score'])
            dataset_data['overall_score'].append(result['overall_score'])
            dataset_data['example_index'].append(result['example_index'])
            
            if has_detailed:
                dataset_data['test_run_score'].append(result.get('test_run_score', 0.0))
                dataset_data['test_accuracy_score'].append(result.get('test_accuracy_score', 0.0))
            
            if has_worker_id:
                dataset_data['worker_id'].append(result.get('worker_id', -1))
        
        # Create HuggingFace dataset
        print(f"Creating HuggingFace dataset with {len(results)} examples...")
        dataset = Dataset.from_dict(dataset_data)
        
        # Add metadata
        dataset_description = f"""
# Einstein Toolkit Evaluation Results

This dataset contains evaluation results from AI-generated Einstein Toolkit C/C++ code.

## Dataset Summary
- **Total examples**: {len(results)}
- **Average overall score**: {sum(r['overall_score'] for r in results) / len(results):.1f}/100
- **Build success rate**: {len([r for r in results if r['build_score'] > 0]) / len(results) * 100:.1f}%
- **Test success rate**: {len([r for r in results if r['test_score'] > 0]) / len(results) * 100:.1f}%

## Columns
- `thorn_name`: Name of the Einstein Toolkit thorn
- `src_filename`: Source code filename
- `build_score`: Score for successful compilation (0-40 points)
- `test_score`: Score for test execution (0-60 points)
- `overall_score`: Total score (0-100 points)
- `example_index`: Index of the example in the evaluation
"""
        
        if has_detailed:
            dataset_description += """- `test_run_score`: Score for test execution (0-10 points)
- `test_accuracy_score`: Score for test accuracy (0-50 points)
"""
        
        if has_worker_id:
            dataset_description += "- `worker_id`: ID of the worker that processed this example (parallel evaluation)\n"
        
        # Upload to HuggingFace Hub
        print(f"Uploading dataset to HuggingFace Hub: {dataset_name}")
        dataset.push_to_hub(dataset_name)
        
        print(f"✅ Successfully uploaded dataset to: https://huggingface.co/datasets/{dataset_name}")
        return True
        
    except Exception as e:
        print(f"Error uploading to HuggingFace: {e}")
        return False


def main():
    parser = argparse.ArgumentParser(description='Analyze Einstein Toolkit evaluation results')
    parser.add_argument('files', nargs='+', help='JSON result files to analyze')
    parser.add_argument('--detailed', action='store_true', 
                      help='Show detailed test scores (test run + accuracy) if available')
    parser.add_argument('--top', type=int, 
                      help='Show only top N results')
    parser.add_argument('--min-score', type=float, default=0.0,
                      help='Show only results with score >= this value')
    parser.add_argument('--thorn-filter', type=str,
                      help='Show only results for thorns containing this string')
    parser.add_argument('--summary-only', action='store_true',
                      help='Show only summary statistics')
    parser.add_argument('--upload-hf', action='store_true',
                      help='Upload the results to HuggingFace Hub as dataset "xinshuo/ET_evaluated"')
    parser.add_argument('--dataset-name', type=str, default='xinshuo/ET_evaluated',
                      help='HuggingFace dataset name (default: xinshuo/ET_evaluated)')
    
    args = parser.parse_args()
    
    # Validate files
    for file_path in args.files:
        if not os.path.exists(file_path):
            print(f"Error: File not found: {file_path}")
            sys.exit(1)
    
    # Load and combine results
    all_results = []
    for file_path in args.files:
        try:
            results = load_results(file_path)
            all_results.extend(results)
            print(f"Loaded {len(results)} results from {file_path}")
        except Exception as e:
            print(f"Error loading {file_path}: {e}")
            sys.exit(1)
    
    if not all_results:
        print("No results found in input files.")
        sys.exit(1)
    
    # Analyze results
    analyzed_results = analyze_results(all_results)
    
    # Apply filters
    if args.min_score > 0:
        analyzed_results = [r for r in analyzed_results if r['overall_score'] >= args.min_score]
    
    if args.thorn_filter:
        analyzed_results = [r for r in analyzed_results if args.thorn_filter.lower() in r['thorn_name'].lower()]
    
    if args.top:
        analyzed_results = analyzed_results[:args.top]
    
    print(f"\nShowing {len(analyzed_results)} results (filtered from {len(all_results)} total)")
    
    # Print results
    if not args.summary_only:
        print()
        print_table(analyzed_results, show_detailed=args.detailed)
    
    # Print summary
    print_summary(analyzed_results)
    
    # Upload to HuggingFace if requested
    if args.upload_hf:
        print("\n" + "="*60)
        print("UPLOADING TO HUGGINGFACE HUB")
        print("="*60)
        success = upload_to_huggingface(analyzed_results, args.dataset_name)
        if not success:
            sys.exit(1)


if __name__ == "__main__":
    main()
