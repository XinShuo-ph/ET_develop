#!/usr/bin/env python3
"""
EinsteinToolkit Parallel Code Generation and Evaluation Script

This script integrates all components to run evaluations in parallel:
1. Load HuggingFace dataset and filter examples with valid thorns
2. Generate code using API with EinsteinToolkit-specific prompts
3. Deploy generated code to multiple Docker containers in parallel
4. Build and run tests in Docker across multiple workers
5. Score results based on build/test success
6. Generate detailed reports with worker statistics

Usage:
    python3 einstein_toolkit_code_eval_parallel.py [--max-examples N] [--n-workers W] [--api-key KEY]
    
Examples:
    # Run 10 examples across 3 parallel workers
    python3 einstein_toolkit_code_eval_parallel.py --max-examples 10 --n-workers 3
    
    # Run with custom API key and output directory
    python3 einstein_toolkit_code_eval_parallel.py --max-examples 20 --n-workers 4 --output-dir results
"""

import os
import sys
import json
import time
import argparse
import threading
from concurrent.futures import ThreadPoolExecutor, as_completed
from datetime import datetime
from datasets import load_dataset
import openai
from smart_diff_comparison import compare_directories_with_tolerance

# Add the scratch directory to the path so we can import our test modules
sys.path.append(os.path.join(os.path.dirname(__file__), 'scratch'))

class DockerManager:
    """Manage Docker operations for EinsteinToolkit testing"""
    
    def __init__(self, container_name="ET_code_eval_container"):
        self.container_name = container_name
        self.image_name = "rynge/einsteintoolkit"
        self.container_running = False
    
    def run_command(self, command, capture_output=True):
        """Run a shell command and return result"""
        import subprocess
        try:
            if capture_output:
                result = subprocess.run(command, shell=True, capture_output=True, text=True)
                return result.returncode, result.stdout, result.stderr
            else:
                result = subprocess.run(command, shell=True)
                return result.returncode, "", ""
        except Exception as e:
            return -1, "", str(e)
    
    def start_container(self):
        """Start the EinsteinToolkit docker container"""
        print(f"Starting Docker container: {self.container_name}")
        
        # First, remove any existing container with the same name
        print("  - Removing any existing container...")
        self.run_command(f"docker rm -f {self.container_name}")
        
        # Start new container
        print("  - Starting new container...")
        cmd = f"docker run -d --name {self.container_name} {self.image_name} tail -f /dev/null"
        returncode, stdout, stderr = self.run_command(cmd)
        
        if returncode == 0:
            print(f"  - Container {self.container_name} started successfully")
            self.container_running = True
            print("  - Waiting for container to be ready...")
            time.sleep(2)  # Wait for container to be ready
            self.setup_initial_files()
            return True
        else:
            print(f"Failed to start container: {stderr}")
            return False
    
    def setup_initial_files(self):
        """Copy initial required files to container"""
        print("  - Setting up initial files in container...")
        
        base_dir = os.path.dirname(__file__)
        
        files_to_copy = [
            ("Cactus/configs/sim/ThornList", "/opt/Cactus/configs/sim/ThornList"),
            ("run_all_tests.sh", "/opt/Cactus/run_all_tests.sh"),
            ("test_names.txt", "/opt/Cactus/test_names.txt"),
            ("ADMConstraints", "/opt/Cactus/arrangements/EinsteinAnalysis/ADMConstraints")
        ]
        
        for src, dst in files_to_copy:
            src_path = os.path.join(base_dir, src)
            if os.path.exists(src_path):
                print(f"    - Copying {src} to container...")
                self.copy_to_container(src_path, dst)
            else:
                print(f"    - Warning: {src} not found, skipping...")
        
        # Make run_all_tests.sh executable and create directories
        print("    - Setting up permissions and directories...")
        self.execute_in_container("chmod +x /opt/Cactus/run_all_tests.sh")
        self.execute_in_container("mkdir -p /opt/Cactus/log_files")
        print("  - Initial setup complete!")
    
    def copy_to_container(self, src_path, dst_path):
        """Copy file or directory to container"""
        cmd = f"docker cp -L {src_path} {self.container_name}:{dst_path}"
        returncode, stdout, stderr = self.run_command(cmd)
        return returncode == 0
    
    def execute_in_container(self, command, working_dir="/opt/Cactus"):
        """Execute command inside the container"""
        full_cmd = f"docker exec {self.container_name} bash -c 'cd {working_dir} && {command}'"
        return self.run_command(full_cmd)
    
    def stop_container(self):
        """Stop and remove the container"""
        if self.container_running:
            print(f"Stopping container: {self.container_name}")
            self.run_command(f"docker rm -f {self.container_name}")
            self.container_running = False
    
    def __del__(self):
        """Cleanup when object is destroyed"""
        self.stop_container()

class EinsteinToolkitTester:
    """Handle building and testing specific thorns in EinsteinToolkit"""
    
    def __init__(self, docker_manager):
        self.docker_manager = docker_manager
        self.thorn_to_tests_mapping = {}
        self.backed_up_files = {}  # Store backup information
        self.load_thorn_test_mapping()
    
    def load_thorn_test_mapping(self):
        """Load the mapping from thorn_to_tests.txt"""
        mapping_file = os.path.join(os.path.dirname(__file__), "thorn_to_tests.txt")
        current_thorn = None
        
        if not os.path.exists(mapping_file):
            print(f"Warning: {mapping_file} not found!")
            return
        
        with open(mapping_file, 'r') as f:
            for line in f:
                original_line = line
                line = line.strip()
                
                if not line or line.startswith('#'):
                    continue
                
                if ':' in line and 'tests' in line:
                    current_thorn = line.split(':')[0].strip()
                    self.thorn_to_tests_mapping[current_thorn] = []
                
                elif original_line.startswith('  ') and current_thorn:
                    test_path = line
                    if test_path and not test_path.startswith('#'):
                        self.thorn_to_tests_mapping[current_thorn].append(test_path)
        
        print(f"Loaded test mapping for {len(self.thorn_to_tests_mapping)} thorns")
    
    def backup_source_file(self, thorn_name, src_filename, worker_id=None):
        """Backup the original source file before deploying generated code"""
        thorn_path = f"/opt/Cactus/arrangements/{thorn_name}"
        src_dir = f"{thorn_path}/src"
        source_file = f"{src_dir}/{src_filename}"
        backup_file = f"{source_file}.backup"
        
        # Create backup in container
        returncode, stdout, stderr = self.docker_manager.execute_in_container(
            f"cp {source_file} {backup_file}"
        )
        
        if returncode == 0:
            backup_key = f"{thorn_name}/{src_filename}"
            self.backed_up_files[backup_key] = backup_file
            if worker_id is not None:
                print(f"[Worker {worker_id}]     - Backed up original file: {source_file} -> {backup_file}")
            else:
                print(f"  - Backed up original file: {source_file} -> {backup_file}")
            return True
        else:
            if worker_id is not None:
                print(f"[Worker {worker_id}]     - Warning: Could not backup {source_file}: {stderr}")
            else:
                print(f"  - Warning: Could not backup {source_file}: {stderr}")
            return False
    
    def restore_source_file(self, thorn_name, src_filename, worker_id=None):
        """Restore the original source file after testing"""
        backup_key = f"{thorn_name}/{src_filename}"
        
        if backup_key not in self.backed_up_files:
            if worker_id is not None:
                print(f"[Worker {worker_id}]     - No backup found for {thorn_name}/{src_filename}")
            else:
                print(f"  - No backup found for {thorn_name}/{src_filename}")
            return False
        
        backup_file = self.backed_up_files[backup_key]
        thorn_path = f"/opt/Cactus/arrangements/{thorn_name}"
        src_dir = f"{thorn_path}/src"
        source_file = f"{src_dir}/{src_filename}"
        
        # Restore backup in container
        returncode, stdout, stderr = self.docker_manager.execute_in_container(
            f"cp {backup_file} {source_file}"
        )
        
        if returncode == 0:
            # Clean up backup file
            self.docker_manager.execute_in_container(f"rm {backup_file}")
            del self.backed_up_files[backup_key]
            if worker_id is not None:
                print(f"[Worker {worker_id}]     - Restored original file: {backup_file} -> {source_file}")
            else:
                print(f"  - Restored original file: {backup_file} -> {source_file}")
            return True
        else:
            if worker_id is not None:
                print(f"[Worker {worker_id}]     - Error: Could not restore {source_file}: {stderr}")
            else:
                print(f"  - Error: Could not restore {source_file}: {stderr}")
            return False
    
    def cleanup_backups(self, worker_id=None):
        """Restore all remaining backed up files and clean up"""
        if not self.backed_up_files:
            return
        
        if worker_id is not None:
            print(f"[Worker {worker_id}] Cleaning up {len(self.backed_up_files)} remaining backup files...")
        else:
            print(f"Cleaning up {len(self.backed_up_files)} remaining backup files...")
        for backup_key, backup_file in list(self.backed_up_files.items()):
            thorn_name, src_filename = backup_key.split('/', 1)
            self.restore_source_file(thorn_name, src_filename, worker_id)
    
    def get_tests_for_thorn(self, thorn_name):
        """Get list of tests for a specific thorn"""
        return self.thorn_to_tests_mapping.get(thorn_name, [])
    
    def deploy_generated_code(self, thorn_name, src_filename, generated_code, worker_id=None):
        """Deploy generated code to the appropriate location in the docker container"""
        thorn_path = f"/opt/Cactus/arrangements/{thorn_name}"
        src_dir = f"{thorn_path}/src"
        target_file = f"{src_dir}/{src_filename}"
        
        if worker_id is not None:
            print(f"[Worker {worker_id}]   - Deploying generated code to {target_file}")
        else:
            print(f"Deploying generated code to {target_file}")
        
        # Write to temporary file and copy to container
        temp_file = f"/tmp/generated_{src_filename.replace('/', '_')}"
        with open(temp_file, 'w') as f:
            f.write(generated_code)
        
        success = self.docker_manager.copy_to_container(temp_file, target_file)
        
        if os.path.exists(temp_file):
            os.remove(temp_file)
        
        return success
    
    def build_cactus(self, worker_id=None):
        """Build Cactus in the container"""
        if worker_id is not None:
            print(f"[Worker {worker_id}]   - Building Cactus with updated code...")
        else:
            print("Building Cactus with updated code...")
        
        returncode, stdout, stderr = self.docker_manager.execute_in_container(
            "./simfactory/bin/sim build"
        )
        
        build_success = (returncode == 0)
        
        return {
            'success': build_success,
            'returncode': returncode,
            'stdout': stdout,
            'stderr': stderr
        }
    
    def run_tests_for_thorn(self, thorn_name, rtol=1e-6, atol=1e-12, worker_id=None):
        """Run all tests associated with a specific thorn with smart numerical comparison"""
        tests = self.get_tests_for_thorn(thorn_name)
        if not tests:
            return {
                'success': False,
                'message': 'No tests found for thorn',
                'test_results': [],
                'total_tests': 0,
                'passed_tests': 0,
                'failed_tests': 0
            }
        
        if worker_id is not None:
            print(f"[Worker {worker_id}]   - Running {len(tests)} tests for thorn {thorn_name}")
            print(f"[Worker {worker_id}]   - Using numerical tolerance: rtol={rtol}, atol={atol}")
        else:
            print(f"Running {len(tests)} tests for thorn {thorn_name}")
            print(f"  Using numerical tolerance: rtol={rtol}, atol={atol}")
        
        test_results = []
        overall_success = True
        
        # Create host directories for test outputs (worker-specific)
        if worker_id is not None:
            host_output_base_dir = f"test_outputs_host_worker_{worker_id}"
        else:
            host_output_base_dir = "test_outputs_host"
        os.makedirs(host_output_base_dir, exist_ok=True)
        
        for test_path in tests:
            test_name = os.path.basename(test_path)
            par_file = f"arrangements/{test_path}.par"
            
            if worker_id is not None:
                print(f"[Worker {worker_id}]     - Running test: {test_name}")
            else:
                print(f"  Running test: {test_name}")
            
            # Check if parameter file exists
            check_cmd = f"test -f {par_file} && echo 'EXISTS' || echo 'MISSING'"
            returncode, stdout, stderr = self.docker_manager.execute_in_container(check_cmd)
            
            if 'MISSING' in stdout:
                if worker_id is not None:
                    print(f"[Worker {worker_id}]       ERROR: Parameter file {par_file} not found!")
                else:
                    print(f"    ERROR: Parameter file {par_file} not found!")
                test_results.append({
                    'test_name': test_name,
                    'test_path': test_path,
                    'success': False,
                    'error': 'Parameter file missing'
                })
                overall_success = False
                continue
            
            # Clean up any existing output directory in container
            self.docker_manager.execute_in_container(f"rm -rf {test_name}")
            
            # Run the simulation (this creates an output directory)
            if worker_id is not None:
                print(f"[Worker {worker_id}]       Running simulation...")
            else:
                print(f"    Running simulation...")
            test_cmd = f"timeout 600 ./exe/cactus_sim {par_file}"
            returncode, stdout, stderr = self.docker_manager.execute_in_container(test_cmd)
            
            if returncode != 0:
                if worker_id is not None:
                    print(f"[Worker {worker_id}]       ERROR: Simulation failed or timed out!")
                else:
                    print(f"    ERROR: Simulation failed or timed out!")
                test_results.append({
                    'test_name': test_name,
                    'test_path': test_path,
                    'success': False,
                    'error': f'Simulation failed with code {returncode}'
                })
                overall_success = False
                continue
            
            # Check if output directory was created
            check_output_cmd = f"test -d {test_name} && echo 'EXISTS' || echo 'MISSING'"
            returncode, stdout, stderr = self.docker_manager.execute_in_container(check_output_cmd)
            
            if 'MISSING' in stdout:
                if worker_id is not None:
                    print(f"[Worker {worker_id}]       ERROR: No output directory created!")
                else:
                    print(f"    ERROR: No output directory created!")
                test_results.append({
                    'test_name': test_name,
                    'test_path': test_path,
                    'success': False,
                    'error': 'No output directory created'
                })
                overall_success = False
                continue
            
            # Copy output directory from container to host
            host_output_dir = os.path.join(host_output_base_dir, test_name)
            if worker_id is not None:
                print(f"[Worker {worker_id}]       Copying results to host: {host_output_dir}")
            else:
                print(f"    Copying results to host: {host_output_dir}")
            
            # Remove existing host output directory if it exists
            if os.path.exists(host_output_dir):
                import shutil
                shutil.rmtree(host_output_dir)
            
            # Copy from container to host
            copy_cmd = f"docker cp {self.docker_manager.container_name}:/opt/Cactus/{test_name} {host_output_dir}"
            copy_returncode, copy_stdout, copy_stderr = self.docker_manager.run_command(copy_cmd)
            
            if copy_returncode != 0:
                if worker_id is not None:
                    print(f"[Worker {worker_id}]       ERROR: Failed to copy output from container!")
                else:
                    print(f"    ERROR: Failed to copy output from container!")
                test_results.append({
                    'test_name': test_name,
                    'test_path': test_path,
                    'success': False,
                    'error': f'Failed to copy output: {copy_stderr}'
                })
                overall_success = False
                continue
            
            # Compare with benchmark using smart numerical comparison
            benchmark_dir = f"Cactus/arrangements/{test_path}"
            if worker_id is not None:
                print(f"[Worker {worker_id}]       Comparing with benchmark using smart numerical comparison...")
            else:
                print(f"    Comparing with benchmark using smart numerical comparison...")
            
            if not os.path.exists(benchmark_dir):
                if worker_id is not None:
                    print(f"[Worker {worker_id}]       ERROR: Benchmark directory not found: {benchmark_dir}")
                else:
                    print(f"    ERROR: Benchmark directory not found: {benchmark_dir}")
                test_results.append({
                    'test_name': test_name,
                    'test_path': test_path,
                    'success': False,
                    'error': 'Benchmark directory not found'
                })
                overall_success = False
                continue
            
            try:
                # Use smart comparison with specified tolerances
                matches, comparison_message = compare_directories_with_tolerance(
                    host_output_dir, benchmark_dir, rtol=rtol, atol=atol
                )
                
                if matches:
                    if worker_id is not None:
                        print(f"[Worker {worker_id}]       PASS: Results match benchmark within tolerance")
                    else:
                        print(f"    PASS: Results match benchmark within tolerance")
                    test_results.append({
                        'test_name': test_name,
                        'test_path': test_path,
                        'success': True,
                        'comparison_message': comparison_message,
                        'rtol': rtol,
                        'atol': atol
                    })
                else:
                    if worker_id is not None:
                        print(f"[Worker {worker_id}]       FAIL: Results do not match benchmark")
                    else:
                        print(f"    FAIL: Results do not match benchmark")
                    test_results.append({
                        'test_name': test_name,
                        'test_path': test_path,
                        'success': False,
                        'comparison_message': comparison_message[:500] + '...' if len(comparison_message) > 500 else comparison_message,
                        'rtol': rtol,
                        'atol': atol
                    })
                    overall_success = False
                
            except Exception as e:
                if worker_id is not None:
                    print(f"[Worker {worker_id}]       ERROR: Comparison failed: {e}")
                else:
                    print(f"    ERROR: Comparison failed: {e}")
                test_results.append({
                    'test_name': test_name,
                    'test_path': test_path,
                    'success': False,
                    'error': f'Comparison error: {str(e)}'
                })
                overall_success = False
            finally:
                # Clean up host output directory after each test to prevent contamination
                if os.path.exists(host_output_dir):
                    if worker_id is not None:
                        print(f"[Worker {worker_id}]       Cleaning up test output: {host_output_dir}")
                    else:
                        print(f"    Cleaning up test output: {host_output_dir}")
                    import shutil
                    shutil.rmtree(host_output_dir)
        
        return {
            'success': overall_success,
            'message': f"Ran {len(tests)} tests with smart numerical comparison",
            'test_results': test_results,
            'total_tests': len(tests),
            'passed_tests': sum(1 for r in test_results if r['success']),
            'failed_tests': sum(1 for r in test_results if not r['success']),
            'rtol': rtol,
            'atol': atol
        }

class EinsteinToolkitScorer:
    """Score generated code based on build and test results"""
    
    def __init__(self):
        # Scoring: 40 points for build + 10 points for test run + 50 points for test accuracy = 100 points
        self.build_points = 40
        self.test_run_points = 10
        self.test_accuracy_points = 50
    
    def calculate_score(self, build_result, test_result):
        """Calculate overall score: 40 points for build + 10 points for test run + 50 points for test accuracy = 100 total"""
        
        # Build score: 40 points if successful, 0 if failed
        build_score = self.build_points if build_result.get('success', False) else 0.0
        
        # Test run score: 10 points if tests were attempted (regardless of outcome)
        test_run_score = 0.0
        test_accuracy_score = 0.0
        test_success_rate = 0.0
        
        if test_result.get('total_tests', 0) > 0:
            # 10 points for successfully running tests
            test_run_score = self.test_run_points
            
            # 50 points * (passed_tests / total_tests) for test accuracy
            test_success_rate = test_result.get('passed_tests', 0) / test_result.get('total_tests', 1)
            test_accuracy_score = self.test_accuracy_points * test_success_rate
        
        # Overall score is build + test run + test accuracy
        overall_score = build_score + test_run_score + test_accuracy_score
        
        return {
            'overall_score': overall_score,
            'build_score': build_score,
            'test_run_score': test_run_score,
            'test_accuracy_score': test_accuracy_score,
            'breakdown': {
                'build_success': build_result.get('success', False),
                'total_tests': test_result.get('total_tests', 0),
                'passed_tests': test_result.get('passed_tests', 0),
                'failed_tests': test_result.get('failed_tests', 0),
                'test_success_rate': test_success_rate,
                'tests_attempted': test_result.get('total_tests', 0) > 0
            },
            'grade': self._get_letter_grade(overall_score)
        }
    
    def _get_letter_grade(self, score):
        """Convert numerical score to letter grade"""
        if score >= 90:
            return 'A'
        elif score >= 80:
            return 'B'
        elif score >= 70:
            return 'C'
        elif score >= 60:
            return 'D'
        else:
            return 'F'

class EvaluationWorker:
    """Worker class that handles evaluation of a subset of examples using its own Docker container"""
    
    def __init__(self, worker_id, api_key, output_dir, rtol=1e-6, atol=1e-12):
        self.worker_id = worker_id
        self.api_key = api_key
        self.output_dir = output_dir
        self.rtol = rtol
        self.atol = atol
        self.container_name = f"ET_code_eval_worker_{worker_id}"
        self.docker_mgr = DockerManager(self.container_name)
        self.tester = None
        self.scorer = EinsteinToolkitScorer()
        self.results = []
        
    def setup(self):
        """Initialize Docker container and components for this worker"""
        print(f"[Worker {self.worker_id}] Starting Docker container...")
        if not self.docker_mgr.start_container():
            raise Exception(f"Failed to start Docker container for worker {self.worker_id}")
        
        self.tester = EinsteinToolkitTester(self.docker_mgr)
        print(f"[Worker {self.worker_id}] Ready to process examples")
        return True
    
    def process_examples(self, examples):
        """Process a list of examples assigned to this worker"""
        worker_results = []
        
        for local_idx, (global_idx, example) in enumerate(examples):
            example_num = local_idx + 1
            total_examples = len(examples)
            
            print(f"\n[Worker {self.worker_id}] Processing example {example_num}/{total_examples}")
            print(f"[Worker {self.worker_id}] Global index: {global_idx}")
            print(f"[Worker {self.worker_id}] Thorn: {example['thorn_name']} - {example['src_filename']}")
            
            try:
                result = self._process_single_example(global_idx, example, local_idx)
                if result:
                    worker_results.append(result)
                    print(f"[Worker {self.worker_id}] Example {example_num} completed with score: {result['score_result']['overall_score']:.1f}")
                else:
                    print(f"[Worker {self.worker_id}] Example {example_num} failed to process")
            except Exception as e:
                print(f"[Worker {self.worker_id}] Error processing example {example_num}: {e}")
                continue
        
        self.results = worker_results
        return worker_results
    
    def _process_single_example(self, global_idx, example, local_idx):
        """Process a single example (similar to main loop in original script)"""
        
        # Generate code
        prompt = create_einstein_toolkit_prompt(example)
        print(f"[Worker {self.worker_id}] Creating prompt for code generation...")
        print(f"[Worker {self.worker_id}]   - Prompt created ({len(prompt)} characters)")
        
        # Show documentation context info
        if 'combined_doc_context' in example and example['combined_doc_context'].strip():
            doc_length = len(example['combined_doc_context'])
            print(f"[Worker {self.worker_id}]   - Documentation context included ({doc_length} characters)")
            if example.get('readme_filename'):
                print(f"[Worker {self.worker_id}]     - README: {example['readme_filename']}")
            if example.get('doc_tex_filenames'):
                print(f"[Worker {self.worker_id}]     - .tex files: {example['doc_tex_filenames']}")
        else:
            print(f"[Worker {self.worker_id}]   - No documentation context available for this example")
        
        if self.api_key:
            print(f"[Worker {self.worker_id}] Generating code using API...")
            print(f"[Worker {self.worker_id}]   - Sending request to API...")
            generated_code = generate_code_with_api(prompt, self.api_key)
            if generated_code:
                print(f"[Worker {self.worker_id}]   - API response received ({len(generated_code)} characters)")
                # Clean up markdown code blocks
                if generated_code.startswith("```"):
                    print(f"[Worker {self.worker_id}]   - Removing markdown code block wrappers...")
                    lines = generated_code.split('\n')
                    if lines[0].startswith("```"):
                        lines = lines[1:]
                    if lines and lines[-1].strip() == "```":
                        lines = lines[:-1]
                    generated_code = '\n'.join(lines)
                    print(f"[Worker {self.worker_id}]   - Code cleaned, new length: {len(generated_code)} characters")
            else:
                print(f"[Worker {self.worker_id}]   - API request failed!")
                return None
        else:
            print(f"[Worker {self.worker_id}] Using mock generated code...")
            # Mock code for testing
            generated_code = f"""#include "cctk.h"
#include "cctk_Arguments.h"
#include "cctk_Parameters.h"

/* Mock generated code for {example['src_filename']} */
void mock_function(CCTK_ARGUMENTS) {{
  DECLARE_CCTK_ARGUMENTS;
  DECLARE_CCTK_PARAMETERS;
  
  // Mock implementation
  CCTK_INFO("Mock function called");
}}"""
        
        if not generated_code:
            print(f"[Worker {self.worker_id}] Failed to generate code!")
            return None
        
        # Save generated code with worker ID
        code_file = os.path.join(self.output_dir, f"worker_{self.worker_id}_example_{local_idx+1}_{example['src_filename'].replace('/', '_')}")
        with open(code_file, 'w') as f:
            f.write(generated_code)
        print(f"[Worker {self.worker_id}] Generated code saved to: {code_file}")
        
        # Deploy and test
        print(f"[Worker {self.worker_id}] Deploying generated code to Docker container...")
        
        # Backup original source file
        print(f"[Worker {self.worker_id}]   - Backing up original source file...")
        backup_success = self.tester.backup_source_file(example['thorn_name'], example['src_filename'], self.worker_id)
        
        if self.tester.deploy_generated_code(example['thorn_name'], example['src_filename'], generated_code, self.worker_id):
            print(f"[Worker {self.worker_id}]   - Code deployed successfully")
            
            # Build
            print(f"[Worker {self.worker_id}] Building Cactus with generated code...")
            print(f"[Worker {self.worker_id}]   - This may take several minutes...")
            build_result = self.tester.build_cactus(self.worker_id)
            print(f"[Worker {self.worker_id}]   - Build {'SUCCEEDED' if build_result['success'] else 'FAILED'}")
            
            if not build_result['success']:
                print(f"[Worker {self.worker_id}]   - Build errors detected, saving to logs...")
                # Save build errors with worker ID
                build_log_file = os.path.join(self.output_dir, f"worker_{self.worker_id}_build_errors_{local_idx+1}.txt")
                with open(build_log_file, 'w') as f:
                    f.write("BUILD STDOUT:\n")
                    f.write(build_result.get('stdout', ''))
                    f.write("\n\nBUILD STDERR:\n")
                    f.write(build_result.get('stderr', ''))
                print(f"[Worker {self.worker_id}]   - Build errors saved to: {build_log_file}")
            
            # Test if build succeeded
            if build_result['success']:
                print(f"[Worker {self.worker_id}] Running tests for generated code...")
                test_result = self.tester.run_tests_for_thorn(example['thorn_name'], rtol=self.rtol, atol=self.atol, worker_id=self.worker_id)
                print(f"[Worker {self.worker_id}]   - Tests: {test_result['passed_tests']}/{test_result['total_tests']} passed (rtol={self.rtol}, atol={self.atol})")
            else:
                print(f"[Worker {self.worker_id}] Skipping tests due to build failure...")
                test_result = {
                    'success': False,
                    'total_tests': 0,
                    'passed_tests': 0,
                    'failed_tests': 0,
                    'test_results': []
                }
            
            # Calculate score
            score_result = self.scorer.calculate_score(build_result, test_result)
            print(f"[Worker {self.worker_id}] Overall Score: {score_result['overall_score']:.1f}/100 (Grade: {score_result['grade']})")
            print(f"[Worker {self.worker_id}]   Build: {score_result['build_score']:.1f}/40, Test Run: {score_result['test_run_score']:.1f}/10, Test Accuracy: {score_result['test_accuracy_score']:.1f}/50")
            
            # Restore original source file
            print(f"[Worker {self.worker_id}] Restoring original source file...")
            self.tester.restore_source_file(example['thorn_name'], example['src_filename'], self.worker_id)
            
            # Return result
            return {
                'worker_id': self.worker_id,
                'example_index': global_idx,
                'local_index': local_idx,
                'thorn_name': example['thorn_name'],
                'src_filename': example['src_filename'],
                'generated_code_file': code_file,
                'build_result': build_result,
                'test_result': test_result,
                'score_result': score_result,
                'timestamp': datetime.now().isoformat()
            }
        else:
            print(f"[Worker {self.worker_id}] Failed to deploy code!")
            # Restore backup if deployment failed
            if backup_success:
                print(f"[Worker {self.worker_id}] Restoring original source file...")
                self.tester.restore_source_file(example['thorn_name'], example['src_filename'], self.worker_id)
            return None
    
    def cleanup(self):
        """Clean up this worker's resources"""
        if self.tester:
            self.tester.cleanup_backups(self.worker_id)
        if self.docker_mgr:
            self.docker_mgr.stop_container()
        
        # Clean up worker-specific test output directory
        worker_output_dir = f"test_outputs_host_worker_{self.worker_id}"
        if os.path.exists(worker_output_dir):
            print(f"[Worker {self.worker_id}] Cleaning up worker test outputs: {worker_output_dir}")
            import shutil
            shutil.rmtree(worker_output_dir)
            print(f"[Worker {self.worker_id}] Worker test outputs cleaned up")
        
        print(f"[Worker {self.worker_id}] Cleanup completed")

def generate_code_with_api(prompt_text, api_key, max_tokens=4000):
    """Generate code using the remote API"""
    base_url = "https://genai-sg-og.tiktok-row.org/gpt/openapi/online/v2/crawl/openai/deployments/gpt_openapi"
    api_version = "2024-03-01-preview"
    model_name = "gcp-claude4-sonnet"
    
    client = openai.AzureOpenAI(
        azure_endpoint=base_url,
        api_version=api_version,
        api_key=api_key,
    )

    try:
        completion = client.chat.completions.create(
            model=model_name,
            messages=[
                {
                    "role": "user",
                    "content": [
                        {
                            "type": "text",
                            "text": prompt_text
                        }
                    ]
                }
            ],
            max_tokens=max_tokens,
            extra_headers={"X-TT-LOGID": ""},
        )
        
        response_json = json.loads(completion.model_dump_json())
        
        if 'choices' in response_json and response_json['choices']:
            if 'message' in response_json['choices'][0] and 'content' in response_json['choices'][0]['message']:
                return response_json['choices'][0]['message']['content']
        
        return None
        
    except Exception as e:
        print(f"Error calling API: {e}")
        return None

def create_einstein_toolkit_prompt(example, context_char_limit=8000, doc_char_limit=15000):
    """Create a prompt for EinsteinToolkit code generation with rich documentation context"""
    # Limit context to avoid token overflow while preserving documentation
    context = example['context'][:context_char_limit] if len(example['context']) > context_char_limit else example['context']
    
    # Include documentation context from the enhanced dataset
    doc_context = ""
    if 'combined_doc_context' in example and example['combined_doc_context'].strip():
        doc_context = example['combined_doc_context'][:doc_char_limit] if len(example['combined_doc_context']) > doc_char_limit else example['combined_doc_context']
    
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
```"""

    # Add documentation context if available
    if doc_context:
        prompt += f"""

## Documentation Context:
{doc_context}"""

    prompt += f"""

## Related Code Context:

{context}


## Instructions:
Generate only the complete C/C++ source code for `{example['src_filename']}`. Include necessary headers, functions, and follow EinsteinToolkit conventions. 


IMPORTANT: Return ONLY the raw C/C++ source code. Do NOT use markdown code blocks (```c or ```). Do NOT include any explanations, comments outside the code, or formatting. Just return the plain C/C++ source code that can be directly saved to a .c file.

Code:"""
    
    return prompt

def load_valid_thorns_from_mapping():
    """Load valid thorns from thorn_to_tests.txt"""
    valid_thorns = set()
    mapping_file = os.path.join(os.path.dirname(__file__), "thorn_to_tests.txt")
    
    if not os.path.exists(mapping_file):
        print(f"Error: {mapping_file} not found!")
        return valid_thorns
    
    with open(mapping_file, 'r') as f:
        for line in f:
            line = line.strip()
            if line and not line.startswith('#'):
                if ':' in line and 'tests' in line:
                    thorn_path = line.split(':')[0].strip()
                    valid_thorns.add(thorn_path)
    
    return valid_thorns

def distribute_work(examples, n_workers):
    """Distribute examples evenly among workers"""
    if n_workers <= 0:
        raise ValueError("Number of workers must be positive")
    
    if n_workers >= len(examples):
        # Each worker gets at most 1 example
        worker_assignments = []
        for i in range(len(examples)):
            worker_assignments.append([examples[i]])
        # Fill remaining workers with empty lists
        for i in range(len(examples), n_workers):
            worker_assignments.append([])
        return worker_assignments
    
    # Distribute examples as evenly as possible
    examples_per_worker = len(examples) // n_workers
    remainder = len(examples) % n_workers
    
    worker_assignments = []
    start_idx = 0
    
    for i in range(n_workers):
        # First 'remainder' workers get one extra example
        end_idx = start_idx + examples_per_worker + (1 if i < remainder else 0)
        worker_assignments.append(examples[start_idx:end_idx])
        start_idx = end_idx
    
    return worker_assignments

def run_worker(worker_id, examples, api_key, output_dir, rtol=1e-6, atol=1e-12):
    """Function to run a single worker - designed for threading"""
    worker = EvaluationWorker(worker_id, api_key, output_dir, rtol, atol)
    
    try:
        # Setup worker
        worker.setup()
        
        # Process assigned examples
        results = worker.process_examples(examples)
        
        print(f"[Worker {worker_id}] Completed processing {len(results)} examples")
        return results
        
    except Exception as e:
        print(f"[Worker {worker_id}] Error: {e}")
        return []
    finally:
        # Always cleanup
        worker.cleanup()

def main():
    """Main execution function"""
    parser = argparse.ArgumentParser(description='EinsteinToolkit Parallel Code Generation and Evaluation')
    parser.add_argument('--max-examples', type=int, default=6, help='Maximum number of examples to process')
    parser.add_argument('--n-workers', type=int, default=2, help='Number of parallel workers (Docker containers)')
    parser.add_argument('--api-key', type=str, help='API key for code generation')
    parser.add_argument('--output-dir', type=str, default='scratch', help='Output directory for results')
    parser.add_argument('--rtol', type=float, default=1e-6, help='Relative tolerance for numerical comparison')
    parser.add_argument('--atol', type=float, default=1e-12, help='Absolute tolerance for numerical comparison')
    
    args = parser.parse_args()
    
    # Create output directory
    os.makedirs(args.output_dir, exist_ok=True)
    
    # Get API key
    api_key = args.api_key or os.environ.get("SEED_LLM_API_KEY")
    if not api_key:
        print("Error: No API key provided. Use --api-key or set SEED_LLM_API_KEY environment variable.")
        print("For testing without API, set MOCK_API=1 environment variable.")
        if not os.environ.get("MOCK_API"):
            return 1
    
    print("EinsteinToolkit Parallel Code Generation and Evaluation")
    print("=" * 70)
    print(f"Max examples: {args.max_examples}")
    print(f"Number of workers: {args.n_workers}")
    print(f"Output directory: {args.output_dir}")
    print(f"API available: {'Yes' if api_key else 'No (Mock mode)'}")
    print(f"Numerical tolerance: rtol={args.rtol}, atol={args.atol}")
    print()
    
    # Clean up any existing test outputs from previous runs
    print("Cleaning up previous test outputs...")
    import shutil
    import glob
    
    # Clean up general test outputs directory
    host_output_base_dir = "test_outputs_host"
    cleaned_dirs = []
    
    if os.path.exists(host_output_base_dir):
        print(f"  - Removing: {host_output_base_dir}")
        shutil.rmtree(host_output_base_dir)
        cleaned_dirs.append(host_output_base_dir)
    
    # Clean up any worker-specific test output directories
    worker_output_dirs = glob.glob("test_outputs_host_worker_*")
    for worker_dir in worker_output_dirs:
        if os.path.exists(worker_dir):
            print(f"  - Removing: {worker_dir}")
            shutil.rmtree(worker_dir)
            cleaned_dirs.append(worker_dir)
    
    if cleaned_dirs:
        print("  - Previous test outputs cleaned up")
    else:
        print("  - No previous test outputs found")
    print()
    
    # Load dataset and filter valid examples
    print("Loading HuggingFace dataset...")
    print("  - Downloading dataset files...")
    try:
        ds = load_dataset("xinshuo/ET_code_with_context_doc")
        train_ds = ds['train']
        print(f"  - Enhanced dataset loaded successfully. Total examples: {len(train_ds)}")
        print(f"  - Dataset includes documentation files for richer context")
    except Exception as e:
        print(f"Error loading dataset: {e}")
        return 1
    
    # Load valid thorns
    valid_thorns = load_valid_thorns_from_mapping()
    print(f"Valid thorns loaded: {len(valid_thorns)}")
    
    # Filter examples
    print("Filtering examples by valid thorns...")
    all_valid_examples = []
    for i, example in enumerate(train_ds):
        if example['thorn_name'] in valid_thorns:
            all_valid_examples.append((i, example))
            # if len(all_valid_examples) <= 10:  # Show first 10 examples being found
            #     print(f"  - Found valid example {len(all_valid_examples)}: {example['thorn_name']} - {example['src_filename']}")
            # elif len(all_valid_examples) % 50 == 0:  # Show progress every 50 examples
            #     print(f"  - Found {len(all_valid_examples)} valid examples so far...")
    
    print(f"Total valid examples after filtering: {len(all_valid_examples)}")
    
    # Limit to max_examples for processing
    valid_examples = all_valid_examples[:args.max_examples]
    print(f"Processing {len(valid_examples)} examples (limited by --max-examples {args.max_examples})")
    print()
    
    if not valid_examples:
        print("No valid examples found!")
        return 1
    
    # Validate number of workers
    if args.n_workers <= 0:
        print("Error: Number of workers must be positive!")
        return 1
    
    # Distribute work among workers
    print(f"Distributing {len(valid_examples)} examples among {args.n_workers} workers...")
    worker_assignments = distribute_work(valid_examples, args.n_workers)
    
    for i, assignment in enumerate(worker_assignments):
        print(f"  - Worker {i}: {len(assignment)} examples")
    print()
    
    # Run workers in parallel
    print("Starting parallel execution...")
    all_results = []
    
    # Use ThreadPoolExecutor to manage parallel workers
    with ThreadPoolExecutor(max_workers=args.n_workers) as executor:
        # Submit all worker tasks
        future_to_worker = {}
        for worker_id in range(args.n_workers):
            if worker_assignments[worker_id]:  # Only start workers with work
                future = executor.submit(
                    run_worker, 
                    worker_id, 
                    worker_assignments[worker_id], 
                    api_key, 
                    args.output_dir,
                    args.rtol,
                    args.atol
                )
                future_to_worker[future] = worker_id
        
        print(f"Started {len(future_to_worker)} workers")
        
        # Collect results as they complete
        for future in as_completed(future_to_worker):
            worker_id = future_to_worker[future]
            try:
                worker_results = future.result()
                all_results.extend(worker_results)
                print(f"Worker {worker_id} completed with {len(worker_results)} results")
            except Exception as e:
                print(f"Worker {worker_id} failed with error: {e}")
    
    print(f"\nParallel execution completed. Collected {len(all_results)} results.")
    
    # Final cleanup of test outputs to ensure clean state
    print("Final cleanup of test outputs...")
    import shutil
    import glob
    
    # Clean up general test outputs directory
    host_output_base_dir = "test_outputs_host"
    cleaned_dirs = []
    
    if os.path.exists(host_output_base_dir):
        print(f"  - Removing: {host_output_base_dir}")
        shutil.rmtree(host_output_base_dir)
        cleaned_dirs.append(host_output_base_dir)
    
    # Clean up any remaining worker-specific test output directories
    worker_output_dirs = glob.glob("test_outputs_host_worker_*")
    for worker_dir in worker_output_dirs:
        if os.path.exists(worker_dir):
            print(f"  - Removing: {worker_dir}")
            shutil.rmtree(worker_dir)
            cleaned_dirs.append(worker_dir)
    
    if cleaned_dirs:
        print("  - Final test outputs cleaned up")
    else:
        print("  - No test outputs to clean up")
    
    # Save final results
    results_file = os.path.join(args.output_dir, f"parallel_evaluation_results_{datetime.now().strftime('%Y%m%d_%H%M%S')}.json")
    with open(results_file, 'w') as f:
        json.dump(all_results, f, indent=2)
    
    print(f"\n{'='*80}")
    print("PARALLEL EVALUATION COMPLETE")
    print('='*80)
    print(f"Processed {len(all_results)} examples using {args.n_workers} workers")
    print(f"Results saved to: {results_file}")
    
    if all_results:
        avg_score = sum(r['score_result']['overall_score'] for r in all_results) / len(all_results)
        print(f"Average score: {avg_score:.1f}/100")
        
        grade_counts = {}
        for r in all_results:
            grade = r['score_result']['grade']
            grade_counts[grade] = grade_counts.get(grade, 0) + 1
        
        print("Grade distribution:", grade_counts)
        
        # Show worker-specific statistics
        worker_stats = {}
        for r in all_results:
            worker_id = r['worker_id']
            if worker_id not in worker_stats:
                worker_stats[worker_id] = {'count': 0, 'total_score': 0}
            worker_stats[worker_id]['count'] += 1
            worker_stats[worker_id]['total_score'] += r['score_result']['overall_score']
        
        print("\nWorker Statistics:")
        for worker_id in sorted(worker_stats.keys()):
            stats = worker_stats[worker_id]
            avg_worker_score = stats['total_score'] / stats['count']
            print(f"  - Worker {worker_id}: {stats['count']} examples, avg score: {avg_worker_score:.1f}/100")
    
    return 0

if __name__ == "__main__":
    sys.exit(main())
