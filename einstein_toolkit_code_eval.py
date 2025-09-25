#!/usr/bin/env python3
"""
EinsteinToolkit Code Generation and Evaluation Script

This script integrates all components to:
1. Load HuggingFace dataset and filter examples with valid thorns
2. Generate code using API with EinsteinToolkit-specific prompts
3. Deploy generated code to Docker container
4. Build and run tests in Docker
5. Score results based on build/test success
6. Generate detailed reports

Usage:
    python3 einstein_toolkit_code_eval.py [--max-examples N] [--api-key KEY]
"""

import os
import sys
import json
import time
import argparse
from datetime import datetime
from datasets import load_dataset
import openai

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
    
    def backup_source_file(self, thorn_name, src_filename):
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
            print(f"  - Backed up original file: {source_file} -> {backup_file}")
            return True
        else:
            print(f"  - Warning: Could not backup {source_file}: {stderr}")
            return False
    
    def restore_source_file(self, thorn_name, src_filename):
        """Restore the original source file after testing"""
        backup_key = f"{thorn_name}/{src_filename}"
        
        if backup_key not in self.backed_up_files:
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
            print(f"  - Restored original file: {backup_file} -> {source_file}")
            return True
        else:
            print(f"  - Error: Could not restore {source_file}: {stderr}")
            return False
    
    def cleanup_backups(self):
        """Restore all remaining backed up files and clean up"""
        if not self.backed_up_files:
            return
        
        print(f"Cleaning up {len(self.backed_up_files)} remaining backup files...")
        for backup_key, backup_file in list(self.backed_up_files.items()):
            thorn_name, src_filename = backup_key.split('/', 1)
            self.restore_source_file(thorn_name, src_filename)
    
    def get_tests_for_thorn(self, thorn_name):
        """Get list of tests for a specific thorn"""
        return self.thorn_to_tests_mapping.get(thorn_name, [])
    
    def deploy_generated_code(self, thorn_name, src_filename, generated_code):
        """Deploy generated code to the appropriate location in the docker container"""
        thorn_path = f"/opt/Cactus/arrangements/{thorn_name}"
        src_dir = f"{thorn_path}/src"
        target_file = f"{src_dir}/{src_filename}"
        
        print(f"Deploying generated code to {target_file}")
        
        # Write to temporary file and copy to container
        temp_file = f"/tmp/generated_{src_filename.replace('/', '_')}"
        with open(temp_file, 'w') as f:
            f.write(generated_code)
        
        success = self.docker_manager.copy_to_container(temp_file, target_file)
        
        if os.path.exists(temp_file):
            os.remove(temp_file)
        
        return success
    
    def build_cactus(self):
        """Build Cactus in the container"""
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
    
    def run_tests_for_thorn(self, thorn_name):
        """Run all tests associated with a specific thorn"""
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
        
        print(f"Running {len(tests)} tests for thorn {thorn_name}")
        
        test_results = []
        overall_success = True
        
        for test_path in tests:
            test_name = os.path.basename(test_path)
            par_file = f"arrangements/{test_path}.par"
            
            # Check if parameter file exists
            check_cmd = f"test -f {par_file} && echo 'EXISTS' || echo 'MISSING'"
            returncode, stdout, stderr = self.docker_manager.execute_in_container(check_cmd)
            
            if 'MISSING' in stdout:
                test_results.append({
                    'test_name': test_name,
                    'test_path': test_path,
                    'success': False,
                    'error': 'Parameter file missing'
                })
                overall_success = False
                continue
            
            # Run the test with timeout
            test_cmd = f"timeout 300 ./exe/cactus_sim {par_file} > log_files/{test_name}_test.log 2>&1"
            returncode, stdout, stderr = self.docker_manager.execute_in_container(test_cmd)
            
            test_success = (returncode == 0)
            
            test_results.append({
                'test_name': test_name,
                'test_path': test_path,
                'success': test_success,
                'returncode': returncode
            })
            
            if not test_success:
                overall_success = False
        
        return {
            'success': overall_success,
            'message': f"Ran {len(tests)} tests",
            'test_results': test_results,
            'total_tests': len(tests),
            'passed_tests': sum(1 for r in test_results if r['success']),
            'failed_tests': sum(1 for r in test_results if not r['success'])
        }

class EinsteinToolkitScorer:
    """Score generated code based on build and test results"""
    
    def __init__(self):
        self.weights = {
            'build_success': 0.4,
            'test_success_rate': 0.5,
            'error_penalty': 0.1
        }
    
    def calculate_score(self, build_result, test_result):
        """Calculate overall score based on build and test results"""
        build_score = 100.0 if build_result.get('success', False) else 0.0
        
        if test_result.get('total_tests', 0) > 0:
            test_success_rate = test_result.get('passed_tests', 0) / test_result.get('total_tests', 1)
            test_score = test_success_rate * 100.0
        else:
            test_success_rate = 0.0
            test_score = 0.0
        
        error_penalty = 0.0
        if not build_result.get('success', False):
            if 'error' in build_result.get('stderr', '').lower():
                error_penalty += 20.0
            if 'fatal' in build_result.get('stderr', '').lower():
                error_penalty += 30.0
        
        error_penalty = min(error_penalty, 50.0)
        
        overall_score = (
            build_score * self.weights['build_success'] +
            test_score * self.weights['test_success_rate'] -
            error_penalty * self.weights['error_penalty']
        )
        
        overall_score = max(0.0, min(100.0, overall_score))
        
        return {
            'overall_score': overall_score,
            'build_score': build_score,
            'test_score': test_score,
            'error_penalty': error_penalty,
            'breakdown': {
                'build_success': build_result.get('success', False),
                'total_tests': test_result.get('total_tests', 0),
                'passed_tests': test_result.get('passed_tests', 0),
                'failed_tests': test_result.get('failed_tests', 0),
                'test_success_rate': test_success_rate
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

def generate_code_with_api(prompt_text, api_key, max_tokens=4000):
    """Generate code using the remote API"""
    base_url = "https://gpt-i18n.byteintl.net/gpt/openapi/online/v2/crawl/openai/deployments/gpt_openapi"
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

def main():
    """Main execution function"""
    parser = argparse.ArgumentParser(description='EinsteinToolkit Code Generation and Evaluation')
    parser.add_argument('--max-examples', type=int, default=3, help='Maximum number of examples to process')
    parser.add_argument('--api-key', type=str, help='API key for code generation')
    parser.add_argument('--output-dir', type=str, default='scratch', help='Output directory for results')
    
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
    
    print("EinsteinToolkit Code Generation and Evaluation")
    print("=" * 60)
    print(f"Max examples: {args.max_examples}")
    print(f"Output directory: {args.output_dir}")
    print(f"API available: {'Yes' if api_key else 'No (Mock mode)'}")
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
    valid_examples = []
    for i, example in enumerate(train_ds):
        if example['thorn_name'] in valid_thorns:
            valid_examples.append((i, example))
            print(f"  - Found valid example {len(valid_examples)}: {example['thorn_name']} - {example['src_filename']}")
            if len(valid_examples) >= args.max_examples:
                break
    
    print(f"Valid examples after filtering: {len(valid_examples)}")
    print()
    
    if not valid_examples:
        print("No valid examples found!")
        return 1
    
    # Start Docker container
    print("Setting up Docker environment...")
    docker_mgr = DockerManager()
    print("  - Initializing Docker manager...")
    if not docker_mgr.start_container():
        print("Failed to start Docker container!")
        return 1
    print("  - Docker container ready!")
    
    # Initialize components
    tester = EinsteinToolkitTester(docker_mgr)
    scorer = EinsteinToolkitScorer()
    
    # Process each example
    results = []
    for i, (idx, example) in enumerate(valid_examples):
        print(f"\n{'='*80}")
        print(f"Processing example {i+1}/{len(valid_examples)}: {example['thorn_name']} - {example['src_filename']}")
        print('='*80)
        
        # Generate code
        print("Creating prompt for code generation...")
        prompt = create_einstein_toolkit_prompt(example)
        print(f"  - Prompt created ({len(prompt)} characters)")
        
        # Show documentation context info
        if 'combined_doc_context' in example and example['combined_doc_context'].strip():
            doc_length = len(example['combined_doc_context'])
            print(f"  - Documentation context included ({doc_length} characters)")
            if example.get('readme_filename'):
                print(f"    - README: {example['readme_filename']}")
            if example.get('doc_tex_filenames'):
                print(f"    - .tex files: {example['doc_tex_filenames']}")
        else:
            print("  - No documentation context available for this example")
        
        if api_key:
            print("Generating code using API...")
            print("  - Sending request to API...")
            generated_code = generate_code_with_api(prompt, api_key)
            if generated_code:
                print(f"  - API response received ({len(generated_code)} characters)")
                # Clean up markdown code blocks
                if generated_code.startswith("```"):
                    print("  - Removing markdown code block wrappers...")
                    lines = generated_code.split('\n')
                    if lines[0].startswith("```"):
                        lines = lines[1:]  # Remove first line with ```c
                    if lines and lines[-1].strip() == "```":
                        lines = lines[:-1]  # Remove last line with ```
                    generated_code = '\n'.join(lines)
                    print(f"  - Code cleaned, new length: {len(generated_code)} characters")
            else:
                print("  - API request failed!")
        else:
            print("Using mock generated code...")
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
            print("Failed to generate code!")
            continue
        
        # Save generated code
        code_file = os.path.join(args.output_dir, f"generated_{i+1}_{example['src_filename'].replace('/', '_')}")
        with open(code_file, 'w') as f:
            f.write(generated_code)
        print(f"Generated code saved to: {code_file}")
        
        # Deploy and test
        print("Deploying generated code to Docker container...")
        
        # Backup original source file before deployment
        print("  - Backing up original source file...")
        backup_success = tester.backup_source_file(example['thorn_name'], example['src_filename'])
        
        if tester.deploy_generated_code(example['thorn_name'], example['src_filename'], generated_code):
            print("  - Code deployed successfully")
            
            # Build
            print("Building Cactus with generated code...")
            print("  - This may take several minutes...")
            build_result = tester.build_cactus()
            print(f"  - Build {'SUCCEEDED' if build_result['success'] else 'FAILED'}")
            
            if not build_result['success']:
                print("  - Build errors detected, saving to logs...")
                # Save build errors to file
                build_log_file = os.path.join(args.output_dir, f"build_errors_{i+1}.txt")
                with open(build_log_file, 'w') as f:
                    f.write("BUILD STDOUT:\n")
                    f.write(build_result.get('stdout', ''))
                    f.write("\n\nBUILD STDERR:\n")
                    f.write(build_result.get('stderr', ''))
                print(f"  - Build errors saved to: {build_log_file}")
            
            # Test if build succeeded
            if build_result['success']:
                print("Running tests for generated code...")
                test_result = tester.run_tests_for_thorn(example['thorn_name'])
                print(f"  - Tests: {test_result['passed_tests']}/{test_result['total_tests']} passed")
            else:
                print("Skipping tests due to build failure...")
                test_result = {
                    'success': False,
                    'total_tests': 0,
                    'passed_tests': 0,
                    'failed_tests': 0,
                    'test_results': []
                }
            
            # Calculate score
            score_result = scorer.calculate_score(build_result, test_result)
            print(f"Overall Score: {score_result['overall_score']:.1f}/100 (Grade: {score_result['grade']})")
            
            # Save results
            result = {
                'example_index': idx,
                'thorn_name': example['thorn_name'],
                'src_filename': example['src_filename'],
                'generated_code_file': code_file,
                'build_result': build_result,
                'test_result': test_result,
                'score_result': score_result,
                'timestamp': datetime.now().isoformat()
            }
            results.append(result)
            
            # Restore original source file after testing
            print("Restoring original source file...")
            tester.restore_source_file(example['thorn_name'], example['src_filename'])
        else:
            print("Failed to deploy code!")
            
            # Still restore original file if backup was created
            if backup_success:
                print("Restoring original source file...")
                tester.restore_source_file(example['thorn_name'], example['src_filename'])
    
    # Clean up any remaining backups
    tester.cleanup_backups()
    
    # Stop Docker container
    docker_mgr.stop_container()
    
    # Save final results
    results_file = os.path.join(args.output_dir, f"evaluation_results_{datetime.now().strftime('%Y%m%d_%H%M%S')}.json")
    with open(results_file, 'w') as f:
        json.dump(results, f, indent=2)
    
    print(f"\n{'='*80}")
    print("EVALUATION COMPLETE")
    print('='*80)
    print(f"Processed {len(results)} examples")
    print(f"Results saved to: {results_file}")
    
    if results:
        avg_score = sum(r['score_result']['overall_score'] for r in results) / len(results)
        print(f"Average score: {avg_score:.1f}/100")
        
        grade_counts = {}
        for r in results:
            grade = r['score_result']['grade']
            grade_counts[grade] = grade_counts.get(grade, 0) + 1
        
        print("Grade distribution:", grade_counts)
    
    return 0

if __name__ == "__main__":
    sys.exit(main())
