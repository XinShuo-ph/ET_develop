import os
import sys
import json
import time
import logging
import argparse
import threading
import subprocess
from pathlib import Path
from datetime import datetime
from concurrent.futures import ThreadPoolExecutor, as_completed
from typing import Dict, List, Any, Optional, Tuple
import subprocess
import threading
import time
import shutil

# Third-party imports
import openai
from datasets import load_dataset

# Import smart comparison functionality
try:
    from smart_diff_comparison import compare_directories_with_tolerance
except ImportError:
    print("Warning: smart_diff_comparison module not found. Numerical comparison disabled.")
    compare_directories_with_tolerance = None

# Import HuggingFace functionality
try:
    from datasets import Dataset
    HUGGINGFACE_AVAILABLE = True
except ImportError:
    print("Warning: HuggingFace datasets not available. Upload functionality disabled.")
    HUGGINGFACE_AVAILABLE = False


class ConfigManager:
    """Manage configuration loading and validation"""
    
    def __init__(self, config_path: str = "config.json"):
        self.config_path = config_path
        self.config = self._load_config()
        self._validate_config()
    
    def _load_config(self) -> Dict[str, Any]:
        """Load configuration from JSON file"""
        try:
            with open(self.config_path, 'r') as f:
                return json.load(f)
        except FileNotFoundError:
            raise FileNotFoundError(f"Configuration file not found: {self.config_path}")
        except json.JSONDecodeError as e:
            raise ValueError(f"Invalid JSON in configuration file: {e}")
    
    def _validate_config(self):
        """Validate required configuration sections"""
        required_sections = ['api', 'docker', 'dataset', 'prompt', 'evaluation', 'paths']
        for section in required_sections:
            if section not in self.config:
                raise ValueError(f"Missing required configuration section: {section}")
    
    def get(self, key: str, default: Any = None) -> Any:
        """Get configuration value with dot notation (e.g., 'api.base_url')"""
        keys = key.split('.')
        value = self.config
        for k in keys:
            if isinstance(value, dict) and k in value:
                value = value[k]
            else:
                return default
        return value


class PromptManager:
    """Manage prompt template loading and formatting"""
    
    def __init__(self, config: ConfigManager):
        self.config = config
        self.template = self._load_template()
    
    def _load_template(self) -> str:
        """Load prompt template from file"""
        template_file = self.config.get('prompt.template_file', 'prompt.txt')
        try:
            with open(template_file, 'r') as f:
                return f.read()
        except FileNotFoundError:
            raise FileNotFoundError(f"Prompt template file not found: {template_file}")
    
    def create_prompt(self, example: Dict[str, Any]) -> str:
        """Create formatted prompt from example data"""
        context_limit = self.config.get('prompt.variables.context_char_limit', 8000)
        doc_limit = self.config.get('prompt.variables.doc_char_limit', 15000)
        
        # Limit context to avoid token overflow
        context = example['context']
        if len(context) > context_limit:
            context = context[:context_limit]
        
        # Handle documentation context
        doc_context_section = ""
        if 'combined_doc_context' in example and example['combined_doc_context'].strip():
            doc_context = example['combined_doc_context']
            if len(doc_context) > doc_limit:
                doc_context = doc_context[:doc_limit]
            doc_context_section = f"""
## Documentation Context:
{doc_context}"""
        
        # Format the prompt
        return self.template.format(
            src_filename=example['src_filename'],
            thorn_name=example['thorn_name'],
            interface=example['interface'],
            schedule=example['schedule'],
            param=example['param'],
            configuration=example['configuration'],
            doc_context_section=doc_context_section,
            context=context
        )


class DockerManager:
    """Manage Docker container operations"""
    
    def __init__(self, config: ConfigManager, container_id: str = "", worker_id: Optional[int] = None):
        self.config = config
        self.worker_id = worker_id
        self.image_name = config.get('docker.image_name')
        self.container_prefix = config.get('docker.container_prefix')
        self.working_dir = config.get('docker.working_directory')
        self.container_name = f"{self.container_prefix}_{container_id}" if container_id else self.container_prefix
        self.container_running = False
    
    def _log(self, message: str, level: str = "info"):
        """Log message with worker prefix if available"""
        if self.worker_id is not None:
            message = f"[Worker {self.worker_id}] {message}"
        
        if level.lower() == "info":
            logging.info(message)
        elif level.lower() == "warning":
            logging.warning(message)
        elif level.lower() == "error":
            logging.error(message)
    
    def run_command(self, command: str, capture_output: bool = True) -> Tuple[int, str, str]:
        """Run shell command and return result"""
        try:
            if capture_output:
                result = subprocess.run(command, shell=True, capture_output=True, text=True, timeout=300)
                return result.returncode, result.stdout, result.stderr
            else:
                result = subprocess.run(command, shell=True, timeout=300)
                return result.returncode, "", ""
        except subprocess.TimeoutExpired:
            return -1, "", "Command timed out"
        except Exception as e:
            return -1, "", str(e)
    
    def start_container(self) -> bool:
        """Start Docker container"""
        self._log(f"Starting Docker container: {self.container_name}")
        
        # Remove existing container
        self.run_command(f"docker rm -f {self.container_name}")
        
        # Start new container
        cmd = f"docker run -d --name {self.container_name} {self.image_name} tail -f /dev/null"
        returncode, stdout, stderr = self.run_command(cmd)
        
        if returncode == 0:
            self.container_running = True
            time.sleep(2)  # Wait for container to be ready
            self._setup_initial_files()
            return True
        else:
            self._log(f"Failed to start container: {stderr}", "error")
            return False
    
    def _setup_initial_files(self):
        """Copy required files to container according to container_file_changes mapping"""
        self._log("Setting up initial files in container")
        container_file_changes = self.config.get('paths.container_file_changes', [])
        
        for host_path, container_path in container_file_changes:
            if os.path.exists(host_path):
                self._log(f"  - Copying {host_path} to {container_path}")
                self.copy_to_container(host_path, container_path)
            else:
                self._log(f"  - Warning: {host_path} not found, skipping...", "warning")
        
        # Make run_all_tests.sh executable and create directories
        self._log("  - Setting up permissions and directories...")
        self.execute_in_container("chmod +x /opt/Cactus/run_all_tests.sh")
        self.execute_in_container("mkdir -p /opt/Cactus/log_files")
        self._log("  - Initial setup complete!")
    
    def copy_to_container(self, src_path: str, dst_path: str) -> bool:
        """Copy file to container"""
        cmd = f"docker cp -L {src_path} {self.container_name}:{dst_path}"
        returncode, stdout, stderr = self.run_command(cmd)
        return returncode == 0
    
    def execute_in_container(self, command: str, working_dir: Optional[str] = None) -> Tuple[int, str, str]:
        """Execute command in container"""
        work_dir = working_dir or self.working_dir
        full_cmd = f"docker exec {self.container_name} bash -c 'cd {work_dir} && {command}'"
        return self.run_command(full_cmd)
    
    def execute_in_container_streaming(self, command: str, working_dir: Optional[str] = None, progress_interval: float = 2.0) -> Tuple[int, str, str]:
        """Execute command in container with streaming progress output"""

        
        work_dir = working_dir or self.working_dir
        full_cmd = f"docker exec {self.container_name} bash -c 'cd {work_dir} && {command}'"
        
        self._log(f"Executing with streaming: {command}")
        
        # Start the process
        process = subprocess.Popen(
            full_cmd,
            shell=True,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            universal_newlines=True,
            bufsize=1
        )
        
        stdout_lines = []
        stderr_lines = []
        
        def read_stdout():
            for line in iter(process.stdout.readline, ''):
                stdout_lines.append(line.rstrip())
        
        def read_stderr():
            for line in iter(process.stderr.readline, ''):
                stderr_lines.append(line.rstrip())
        
        # Start threads to read stdout and stderr
        stdout_thread = threading.Thread(target=read_stdout)
        stderr_thread = threading.Thread(target=read_stderr)
        stdout_thread.daemon = True
        stderr_thread.daemon = True
        stdout_thread.start()
        stderr_thread.start()
        
        # Monitor progress and show last lines periodically
        last_progress_time = time.time()
        
        while process.poll() is None:
            current_time = time.time()
            if current_time - last_progress_time >= progress_interval:
                if stdout_lines:
                    recent_lines = stdout_lines[-2:] if len(stdout_lines) >= 2 else stdout_lines
                    # Filter out empty lines
                    non_empty_lines = [line for line in recent_lines if line.strip()]
                    if non_empty_lines:
                        self._log("Build Progress: ...")
                        for line in non_empty_lines:
                            self._log(f"Build Progress: {line[:150]}{'...' if len(line) > 150 else ''}")
                        self._log("Build Progress: ...")
                last_progress_time = current_time
            time.sleep(0.5)  # Check every 0.5 seconds
        
        # Wait for threads to finish
        stdout_thread.join(timeout=1)
        stderr_thread.join(timeout=1)
        
        # Get final output
        process.stdout.close()
        process.stderr.close()
        
        returncode = process.returncode
        stdout_text = '\n'.join(stdout_lines)
        stderr_text = '\n'.join(stderr_lines)
        
        return returncode, stdout_text, stderr_text
    
    def stop_container(self):
        """Stop and remove container"""
        if self.container_running:
            self._log(f"Stopping container: {self.container_name}")
            self.run_command(f"docker rm -f {self.container_name}")
            self.container_running = False
    
    def __del__(self):
        """Cleanup when object is destroyed"""
        self.stop_container()


class APIClient:
    """Handle API communication for code generation"""
    
    def __init__(self, config: ConfigManager, worker_id: Optional[int] = None):
        self.config = config
        self.worker_id = worker_id
        self.base_url = config.get('api.base_url')
        self.api_version = config.get('api.api_version')
        self.model_name = config.get('api.model_name')
        self.max_tokens = config.get('api.max_tokens', 4000)
        self.api_key = self._get_api_key()
    
    def _log(self, message: str, level: str = "info"):
        """Log message with worker prefix if available"""
        if self.worker_id is not None:
            message = f"[Worker {self.worker_id}] {message}"
        
        if level.lower() == "info":
            logging.info(message)
        elif level.lower() == "warning":
            logging.warning(message)
        elif level.lower() == "error":
            logging.error(message)
    
    def _get_api_key(self) -> str:
        """Get API key from environment"""
        env_var = self.config.get('api.api_key_env_var')
        api_key = os.environ.get(env_var)
        if not api_key:
            raise ValueError(f"API key not found in environment variable: {env_var}")
        return api_key
    
    def generate_code(self, prompt: str) -> Optional[str]:
        """Generate code using API"""
        try:
            client = openai.AzureOpenAI(
                azure_endpoint=self.base_url,
                api_version=self.api_version,
                api_key=self.api_key,
            )
            
            self._log("Sending API request for code generation")
            response = client.chat.completions.create(
                model=self.model_name,
                messages=[{"role": "user", "content": prompt}],
                max_tokens=self.max_tokens,
                temperature=0.1
            )
            
            self._log("Received API response")
            
            # Show first two lines of response for crosscheck
            response_content = response.choices[0].message.content.strip()
            lines = response_content.split('\n')
            if len(lines) >= 2:
                self._log(f"API Response Preview: Line 1: {lines[0][:100]}{'...' if len(lines[0]) > 100 else ''}")
                self._log(f"API Response Preview: Line 2: {lines[1][:100]}{'...' if len(lines[1]) > 100 else ''}")
            elif len(lines) == 1:
                self._log(f"API Response Preview: {lines[0][:200]}{'...' if len(lines[0]) > 200 else ''}")
            else:
                self._log("API Response Preview: (empty response)")
            
            return response_content
            
        except Exception as e:
            self._log(f"API request failed: {e}", "error")
            return None


class EinsteinToolkitTester:
    """Handle Einstein Toolkit testing operations"""
    
    def __init__(self, config: ConfigManager, docker_manager: DockerManager, worker_id: Optional[int] = None):
        self.config = config
        self.docker_manager = docker_manager
        self.worker_id = worker_id
        self.backed_up_files = {}
        self.thorn_to_tests_mapping = {}
        self._load_thorn_test_mapping()
    
    def _log(self, message: str, level: str = "info"):
        """Log message with worker prefix if available"""
        if self.worker_id is not None:
            message = f"[Worker {self.worker_id}] {message}"
        
        if level.lower() == "info":
            logging.info(message)
        elif level.lower() == "warning":
            logging.warning(message)
        elif level.lower() == "error":
            logging.error(message)
    
    def _filter_log_output(self, log_text: str, context_lines: int = 5) -> str:
        """Filter log output to keep only important parts around key keywords"""
        if not log_text:
            return log_text
        
        # Get buildlog keywords and truncation limit from config
        keywords = self.config.get('logging.buildlog_keywords', ["Done", "All done", "success", "error:"])
        max_line_length = self.config.get('logging.line_truncation_n_char', 200)
        lines = log_text.split('\n')
        important_lines = set()
        
        # Find lines containing keywords and mark surrounding lines (case-insensitive)
        for i, line in enumerate(lines):
            line_lower = line.lower()
            for keyword in keywords:
                if keyword.lower() in line_lower:
                    # Add context lines around the match
                    start = max(0, i - context_lines)
                    end = min(len(lines), i + context_lines + 1)
                    for j in range(start, end):
                        important_lines.add(j)
        
        if not important_lines:
            # If no keywords found, return first and last few lines with truncation
            if len(lines) <= 20:
                # Apply truncation to all lines
                truncated_lines = [self._truncate_line(line, max_line_length, keywords) for line in lines]
                return '\n'.join(truncated_lines)
            else:
                first_lines = [self._truncate_line(line, max_line_length, keywords) for line in lines[:10]]
                last_lines = [self._truncate_line(line, max_line_length, keywords) for line in lines[-10:]]
                return '\n'.join(first_lines + ['...', '(log truncated)', '...'] + last_lines)
        
        # Sort line numbers and group consecutive lines
        sorted_lines = sorted(important_lines)
        filtered_lines = []
        
        i = 0
        while i < len(sorted_lines):
            start = sorted_lines[i]
            end = start
            
            # Find consecutive lines
            while i + 1 < len(sorted_lines) and sorted_lines[i + 1] == sorted_lines[i] + 1:
                i += 1
                end = sorted_lines[i]
            
            # Add the group of lines
            if start > 0 and (not filtered_lines or start > sorted_lines[0]):
                filtered_lines.append(f"... (line {start + 1}) ...")
            
            for line_num in range(start, end + 1):
                if line_num < len(lines):
                    original_line = lines[line_num]
                    truncated_line = self._truncate_line(original_line, max_line_length, keywords)
                    filtered_lines.append(f"{line_num + 1:4d}: {truncated_line}")
            
            i += 1
        
        return '\n'.join(filtered_lines)
    
    def _truncate_line(self, line: str, max_length: int, keywords: list) -> str:
        """Truncate a line, preserving keywords if present"""
        if len(line) <= max_length:
            return line
        
        # Check if line contains any keywords
        line_lower = line.lower()
        keyword_positions = []
        
        for keyword in keywords:
            keyword_lower = keyword.lower()
            pos = line_lower.find(keyword_lower)
            if pos >= 0:
                keyword_positions.append((pos, pos + len(keyword)))
        
        if not keyword_positions:
            # No keywords found, truncate from the beginning
            return line[:max_length - 3] + "..."
        
        # Find the first keyword position
        first_keyword_start, first_keyword_end = keyword_positions[0]
        
        # Calculate how much space we have around the keyword
        available_space = max_length - 6  # Reserve 6 chars for "..." on both sides
        keyword_length = first_keyword_end - first_keyword_start
        
        if keyword_length >= available_space:
            # Keyword itself is too long, just show the keyword
            return "..." + line[first_keyword_start:first_keyword_start + available_space - 3] + "..."
        
        # Try to center the keyword
        remaining_space = available_space - keyword_length
        left_space = remaining_space // 2
        right_space = remaining_space - left_space
        
        # Calculate actual start and end positions
        start_pos = max(0, first_keyword_start - left_space)
        end_pos = min(len(line), first_keyword_end + right_space)
        
        # Build the truncated line
        result = ""
        if start_pos > 0:
            result += "..."
        result += line[start_pos:end_pos]
        if end_pos < len(line):
            result += "..."
        
        return result
    
    def _load_thorn_test_mapping(self):
        """Load the mapping from thorn-to-tests file (configured in paths.thorn_to_tests_file)"""
        mapping_file = self.config.get('paths.thorn_to_tests_file', 'thorn_to_tests.txt')
        current_thorn = None
        
        if not os.path.exists(mapping_file):
            self._log(f"Warning: {mapping_file} not found!", "warning")
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
        
        self._log(f"Loaded test mapping for {len(self.thorn_to_tests_mapping)} thorns")
    
    def backup_source_file(self, thorn_name: str, src_filename: str) -> bool:
        """Backup original source file"""
        src_path = f"/opt/Cactus/arrangements/{thorn_name.replace('/', '/')}/src/{src_filename}"
        backup_path = f"{src_path}.backup_original"
        
        # Check if file exists and backup
        returncode, stdout, stderr = self.docker_manager.execute_in_container(f"test -f {src_path}")
        if returncode == 0:
            backup_cmd = f"cp {src_path} {backup_path}"
            returncode, stdout, stderr = self.docker_manager.execute_in_container(backup_cmd)
            if returncode == 0:
                self.backed_up_files[src_path] = backup_path
                return True
        return False
    
    def restore_source_file(self, src_path: str) -> bool:
        """Restore original source file"""
        if src_path in self.backed_up_files:
            backup_path = self.backed_up_files[src_path]
            restore_cmd = f"cp {backup_path} {src_path}"
            returncode, stdout, stderr = self.docker_manager.execute_in_container(restore_cmd)
            return returncode == 0
        return False
    
    def cleanup_backups(self):
        """Clean up all backup files"""
        for src_path, backup_path in self.backed_up_files.items():
            self.docker_manager.execute_in_container(f"rm -f {backup_path}")
        self.backed_up_files.clear()
    
    def deploy_code(self, thorn_name: str, src_filename: str, code: str) -> bool:
        """Deploy generated code to container"""
        # Backup original file
        self.backup_source_file(thorn_name, src_filename)
        
        # Write generated code to temporary file
        temp_file = f"/tmp/generated_{src_filename}"
        with open(temp_file, 'w') as f:
            f.write(code)
        
        # Copy to container
        thorn_path = thorn_name.replace('/', '/')
        target_path = f"/opt/Cactus/arrangements/{thorn_path}/src/{src_filename}"
        
        success = self.docker_manager.copy_to_container(temp_file, target_path)
        os.remove(temp_file)
        
        return success
    
    def build_thorn(self, thorn_name: str) -> Dict[str, Any]:
        """Build Cactus using simfactory (like original code)"""
        self._log(f"Building Cactus with updated code for thorn: {thorn_name}")
        
        # Use simfactory build command (matches original code exactly)
        build_cmd = "./simfactory/bin/sim build"
        
        # Check if build streaming is enabled
        streaming_enabled = self.config.get('logging.build_streaming_enabled', False)
        
        if streaming_enabled:
            # Execute build with streaming progress (shows last 2 lines every N seconds)
            streaming_interval = self.config.get('logging.build_streaming_interval_sec', 2.0)
            build_ret, build_out, build_err = self.docker_manager.execute_in_container_streaming(build_cmd, progress_interval=streaming_interval)
        else:
            # Execute build normally without streaming
            build_ret, build_out, build_err = self.docker_manager.execute_in_container(build_cmd)
        
        success = build_ret == 0
        
        # Filter log output to keep only important parts
        filtered_stdout = self._filter_log_output(build_out)
        filtered_stderr = self._filter_log_output(build_err)
        
        return {
            'success': success,
            'return_code': build_ret,
            'stdout': filtered_stdout,
            'stderr': filtered_stderr
        }
    
    def run_tests_for_thorn(self, thorn_name: str) -> Dict[str, Any]:
        """Run tests for specific thorn (exactly like original code)"""
        available_tests = self.thorn_to_tests_mapping.get(thorn_name, [])
        if not available_tests:
            return {
                'success': False,
                'message': 'No tests found for thorn',
                'test_results': [],
                'total_tests': 0,
                'passed_tests': 0,
                'failed_tests': 0
            }
        
        rtol = self.config.get('evaluation.tolerances.rtol', 1e-6)
        atol = self.config.get('evaluation.tolerances.atol', 1e-12)
        benchmark_base = self.config.get('paths.benchmark_base', 'Cactus/arrangements')
        
        if self.worker_id is not None:
            logging.info(f"[Worker {self.worker_id}]   - Running {len(available_tests)} tests for thorn {thorn_name}")
            logging.info(f"[Worker {self.worker_id}]   - Using numerical tolerance: rtol={rtol}, atol={atol}")
        else:
            logging.info(f"Running {len(available_tests)} tests for thorn {thorn_name}")
            logging.info(f"  Using numerical tolerance: rtol={rtol}, atol={atol}")
        
        test_results = []
        overall_success = True
        
        # Create host directories for test outputs (worker-specific)
        if self.worker_id is not None:
            host_output_base_dir = f"{self.config.get('paths.test_outputs_base')}_worker_{self.worker_id}"
        else:
            host_output_base_dir = self.config.get('paths.test_outputs_base')
        os.makedirs(host_output_base_dir, exist_ok=True)
        
        for test_path in available_tests:
            test_name = os.path.basename(test_path)
            par_file = f"arrangements/{test_path}.par"  # FIXED: Use correct path format
            
            if self.worker_id is not None:
                logging.info(f"[Worker {self.worker_id}]     - Running test: {test_name}")
            else:
                logging.info(f"  Running test: {test_name}")
            
            # Check if parameter file exists
            check_cmd = f"test -f {par_file} && echo 'EXISTS' || echo 'MISSING'"
            returncode, stdout, stderr = self.docker_manager.execute_in_container(check_cmd)
            
            if 'MISSING' in stdout:
                if self.worker_id is not None:
                    logging.error(f"[Worker {self.worker_id}]       ERROR: Parameter file {par_file} not found!")
                else:
                    logging.error(f"    ERROR: Parameter file {par_file} not found!")
                test_results.append({
                    'test_name': test_name,
                    'test_path': test_path,
                    'success': False,
                    'error': 'Parameter file missing'
                })
                overall_success = False
                continue
            
            # FIXED: Clean up any existing output directory in container BEFORE test
            self.docker_manager.execute_in_container(f"rm -rf {test_name}")
            
            # Run the simulation (this creates an output directory)
            if self.worker_id is not None:
                logging.info(f"[Worker {self.worker_id}]       Running simulation...")
            else:
                logging.info(f"    Running simulation...")
            
            # FIXED: Use correct test command with timeout and exe/cactus_sim
            test_cmd = f"timeout 600 ./exe/cactus_sim {par_file}"
            returncode, stdout, stderr = self.docker_manager.execute_in_container(test_cmd)
            
            if returncode != 0:
                if self.worker_id is not None:
                    logging.error(f"[Worker {self.worker_id}]       ERROR: Simulation failed or timed out!")
                else:
                    logging.error(f"    ERROR: Simulation failed or timed out!")
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
                if self.worker_id is not None:
                    logging.error(f"[Worker {self.worker_id}]       ERROR: No output directory created!")
                else:
                    logging.error(f"    ERROR: No output directory created!")
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
            if self.worker_id is not None:
                logging.info(f"[Worker {self.worker_id}]       Copying results to host: {host_output_dir}")
            else:
                logging.info(f"    Copying results to host: {host_output_dir}")
            
            # Remove existing host output directory if it exists
            if os.path.exists(host_output_dir):
                shutil.rmtree(host_output_dir)
            
            # Copy from container to host
            copy_cmd = f"docker cp {self.docker_manager.container_name}:/opt/Cactus/{test_name} {host_output_dir}"
            copy_returncode, copy_stdout, copy_stderr = self.docker_manager.run_command(copy_cmd)
            
            if copy_returncode != 0:
                if self.worker_id is not None:
                    logging.error(f"[Worker {self.worker_id}]       ERROR: Failed to copy output from container!")
                else:
                    logging.error(f"    ERROR: Failed to copy output from container!")
                test_results.append({
                    'test_name': test_name,
                    'test_path': test_path,
                    'success': False,
                    'error': f'Failed to copy output: {copy_stderr}'
                })
                overall_success = False
                continue
            
            # Compare with benchmark using smart numerical comparison
            benchmark_dir = f"{benchmark_base}/{test_path}"
            if self.worker_id is not None:
                logging.info(f"[Worker {self.worker_id}]       Comparing with benchmark using smart numerical comparison...")
            else:
                logging.info(f"    Comparing with benchmark using smart numerical comparison...")
            
            if not os.path.exists(benchmark_dir):
                if self.worker_id is not None:
                    logging.error(f"[Worker {self.worker_id}]       ERROR: Benchmark directory not found: {benchmark_dir}")
                else:
                    logging.error(f"    ERROR: Benchmark directory not found: {benchmark_dir}")
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
                    if self.worker_id is not None:
                        logging.info(f"[Worker {self.worker_id}]       PASS: Results match benchmark within tolerance")
                    else:
                        logging.info(f"    PASS: Results match benchmark within tolerance")
                    test_results.append({
                        'test_name': test_name,
                        'test_path': test_path,
                        'success': True,
                        'comparison_message': comparison_message,
                        'rtol': rtol,
                        'atol': atol
                    })
                else:
                    if self.worker_id is not None:
                        logging.info(f"[Worker {self.worker_id}]       FAIL: Results do not match benchmark")
                    else:
                        logging.info(f"    FAIL: Results do not match benchmark")
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
                if self.worker_id is not None:
                    logging.error(f"[Worker {self.worker_id}]       ERROR: Comparison failed: {e}")
                else:
                    logging.error(f"    ERROR: Comparison failed: {e}")
                test_results.append({
                    'test_name': test_name,
                    'test_path': test_path,
                    'success': False,
                    'error': f'Comparison error: {str(e)}'
                })
                overall_success = False
            finally:
                # FIXED: Clean up host output directory after each test to prevent contamination
                if os.path.exists(host_output_dir):
                    if self.worker_id is not None:
                        logging.info(f"[Worker {self.worker_id}]       Cleaning up test output: {host_output_dir}")
                    else:
                        logging.info(f"    Cleaning up test output: {host_output_dir}")
                    
                    shutil.rmtree(host_output_dir)
        
        return {
            'success': overall_success,
            'message': f"Ran {len(available_tests)} tests with smart numerical comparison",
            'test_results': test_results,
            'total_tests': len(available_tests),
            'passed_tests': sum(1 for r in test_results if r['success']),
            'failed_tests': sum(1 for r in test_results if not r['success']),
            'rtol': rtol,
            'atol': atol
        }


class EinsteinToolkitScorer:
    """Score evaluation results"""
    
    def __init__(self, config: ConfigManager):
        self.config = config
        self.build_points = config.get('evaluation.scoring.build_points', 40)
        self.test_run_points = config.get('evaluation.scoring.test_run_points', 10)
        self.test_accuracy_points = config.get('evaluation.scoring.test_accuracy_points', 50)
    
    def calculate_score(self, build_result: Dict[str, Any], test_result: Dict[str, Any]) -> Dict[str, Any]:
        """Calculate overall score"""
        # Build score
        build_score = self.build_points if build_result.get('success', False) else 0.0
        
        # Test scores
        test_run_score = 0.0
        test_accuracy_score = 0.0
        test_success_rate = 0.0
        
        if test_result.get('total_tests', 0) > 0:
            test_run_score = self.test_run_points
            test_success_rate = test_result.get('passed_tests', 0) / test_result.get('total_tests', 1)
            test_accuracy_score = self.test_accuracy_points * test_success_rate
        
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
            }
        }
    


class EvaluationWorker:
    """Worker class for parallel evaluation"""
    
    def __init__(self, worker_id: int, config: ConfigManager):
        self.worker_id = worker_id
        self.config = config
        self.docker_mgr = DockerManager(config, f"worker_{worker_id}", worker_id)
        self.api_client = APIClient(config, worker_id)
        self.prompt_manager = PromptManager(config)
        self.tester = None
        self.scorer = EinsteinToolkitScorer(config)
        self.results = []
    
    def setup(self) -> bool:
        """Setup worker environment"""
        logging.info(f"[Worker {self.worker_id}] Setting up worker")
        success = self.docker_mgr.start_container()
        if success:
            self.tester = EinsteinToolkitTester(self.config, self.docker_mgr, self.worker_id)
        return success
    
    def process_example(self, example: Dict[str, Any], example_index: int) -> Dict[str, Any]:
        """Process a single example"""
        logging.info(f"[Worker {self.worker_id}] Processing example {example_index}: {example['thorn_name']}/{example['src_filename']}")
        
        try:
            # Generate code
            prompt = self.prompt_manager.create_prompt(example)
            generated_code = self.api_client.generate_code(prompt)
            
            if not generated_code:
                return self._create_error_result(example, example_index, "Code generation failed")
            
            # Deploy and test
            deploy_success = self.tester.deploy_code(example['thorn_name'], example['src_filename'], generated_code)
            if not deploy_success:
                return self._create_error_result(example, example_index, "Code deployment failed")
            
            # Build
            build_result = self.tester.build_thorn(example['thorn_name'])
            
            # Test (only if build succeeded)
            if build_result['success']:
                test_result = self.tester.run_tests_for_thorn(example['thorn_name'])
            else:
                test_result = {'total_tests': 0, 'passed_tests': 0, 'failed_tests': 0, 'test_results': []}
            
            # Score
            score_result = self.scorer.calculate_score(build_result, test_result)
            
            # Restore original files
            for src_path in list(self.tester.backed_up_files.keys()):
                self.tester.restore_source_file(src_path)
            
            result = {
                'worker_id': self.worker_id,
                'example_index': example_index,
                'thorn_name': example['thorn_name'],
                'src_filename': example['src_filename'],
                'generated_code': generated_code,
                'build_result': build_result,
                'test_result': test_result,
                'score_result': score_result,
                'timestamp': datetime.now().isoformat(),
                'success': True
            }
            
            logging.info(f"[Worker {self.worker_id}] Completed example {example_index}: Score {score_result['overall_score']:.1f}/100")
            return result
            
        except Exception as e:
            logging.error(f"[Worker {self.worker_id}] Error processing example {example_index}: {e}")
            return self._create_error_result(example, example_index, f"Processing error: {e}")
    
    def _create_error_result(self, example: Dict[str, Any], example_index: int, error_msg: str) -> Dict[str, Any]:
        """Create error result"""
        return {
            'worker_id': self.worker_id,
            'example_index': example_index,
            'thorn_name': example['thorn_name'],
            'src_filename': example['src_filename'],
            'error': error_msg,
            'score_result': {'overall_score': 0.0, 'build_score': 0.0, 'test_run_score': 0.0, 'test_accuracy_score': 0.0},
            'timestamp': datetime.now().isoformat(),
            'success': False
        }
    
    def cleanup(self):
        """Cleanup worker resources"""
        logging.info(f"[Worker {self.worker_id}] Cleaning up worker")
        if self.tester:
            self.tester.cleanup_backups()
        self.docker_mgr.stop_container()
        
        # Clean up worker-specific output directory
        worker_output_dir = f"{self.config.get('paths.test_outputs_base')}_worker_{self.worker_id}"
        if os.path.exists(worker_output_dir):
            shutil.rmtree(worker_output_dir)


class HuggingFaceUploader:
    """Handle HuggingFace dataset uploads"""
    
    def __init__(self, config: ConfigManager):
        self.config = config
    
    def upload_results(self, results: List[Dict[str, Any]], result_dataset_name: Optional[str] = None) -> bool:
        """Upload results to HuggingFace"""
        if not HUGGINGFACE_AVAILABLE:
            logging.error("HuggingFace datasets not available")
            return False
        
        result_dataset_name = result_dataset_name or self.config.get('final_upload.result_dataset_name')
        
        try:
            # Prepare dataset
            dataset_data = self._prepare_dataset(results)
            result_dataset = Dataset.from_dict(dataset_data)
            
            # Upload
            logging.info(f"Uploading {len(results)} results to HuggingFace: {result_dataset_name}")
            result_dataset.push_to_hub(result_dataset_name)
            logging.info(f"Successfully uploaded to: https://huggingface.co/datasets/{result_dataset_name}")
            return True
            
        except Exception as e:
            logging.error(f"HuggingFace upload failed: {e}")
            return False
    
    def _prepare_dataset(self, results: List[Dict[str, Any]]) -> Dict[str, List]:
        """Prepare results for HuggingFace dataset format"""
        dataset_data = {
            'thorn_name': [],
            'src_filename': [],
            'build_score': [],
            'test_run_score': [],
            'test_accuracy_score': [],
            'overall_score': [],
            'example_index': [],
            'worker_id': []
        }
        
        for result in results:
            if not result.get('success', False):
                continue
            
            score_result = result.get('score_result', {})
            dataset_data['thorn_name'].append(result['thorn_name'])
            dataset_data['src_filename'].append(result['src_filename'])
            dataset_data['build_score'].append(score_result.get('build_score', 0.0))
            dataset_data['test_run_score'].append(score_result.get('test_run_score', 0.0))
            dataset_data['test_accuracy_score'].append(score_result.get('test_accuracy_score', 0.0))
            dataset_data['overall_score'].append(score_result.get('overall_score', 0.0))
            dataset_data['example_index'].append(result.get('example_index', 0))
            dataset_data['worker_id'].append(result.get('worker_id', -1))
        
        return dataset_data


class ETEvaluator:
    """Main Einstein Toolkit Evaluator class"""
    
    def __init__(self, config_path: str = "config.json"):
        self.config = ConfigManager(config_path)
    
    def setup_logging(self, output_dir: str = "."):
        """Setup logging configuration"""
        log_level = getattr(logging, self.config.get('logging.level', 'INFO'))
        log_format = self.config.get('logging.format', '%(asctime)s - %(levelname)s - %(message)s')
        
        # Ensure output directory exists
        os.makedirs(output_dir, exist_ok=True)
        
        # Create log file path in output directory
        log_filename = f"ET_evaluator_{datetime.now().strftime('%Y%m%d_%H%M%S')}.log"
        log_filepath = os.path.join(output_dir, log_filename)
        
        logging.basicConfig(
            level=log_level,
            format=log_format,
            handlers=[
                logging.StreamHandler(sys.stdout),
                logging.FileHandler(log_filepath)
            ]
        )
    
    def load_dataset(self, max_examples: Optional[int] = None) -> List[Dict[str, Any]]:
        """Load and filter dataset examples"""
        input_dataset_name = self.config.get('dataset.name')
        split = self.config.get('dataset.split', 'test')
        
        logging.info(f"Loading dataset: {input_dataset_name}")
        input_dataset = load_dataset(input_dataset_name, split=split)
        
        # Load thorn to tests mapping to only include checked thorns with tests
        checked_thorns = self._load_checked_thorns()
        
        # Filter examples to only include thorns that have been checked and have tests
        valid_examples = []
        for example in input_dataset:
            if example['thorn_name'] in checked_thorns:
                valid_examples.append(example)
        
        logging.info(f"Found {len(valid_examples)} valid examples (from {len(input_dataset)} total)")
        
        if max_examples:
            valid_examples = valid_examples[:max_examples]
            logging.info(f"Limited to {len(valid_examples)} examples")
        
        return valid_examples
    
    def _load_checked_thorns(self) -> set:
        """Load checked thorns from thorn-to-tests file (configured in paths.thorn_to_tests_file)"""
        mapping_file = self.config.get('paths.thorn_to_tests_file', 'thorn_to_tests.txt')
        checked_thorns = set()
        
        if not os.path.exists(mapping_file):
            logging.warning(f"Warning: {mapping_file} not found! Using fallback ThornList.")
            # Fallback to ThornList if thorn-to-tests file doesn't exist
            thorns_file = self.config.get('dataset.valid_thorns_file')
            if os.path.exists(thorns_file):
                with open(thorns_file, 'r') as f:
                    for line in f:
                        line = line.strip()
                        if line and not line.startswith('#'):
                            checked_thorns.add(line)
            return checked_thorns
        
        # Parse thorn-to-tests file format
        with open(mapping_file, 'r') as f:
            for line in f:
                line = line.strip()
                if not line or line.startswith('#'):
                    continue
                
                if ':' in line and 'tests' in line:
                    thorn_name = line.split(':')[0].strip()
                    checked_thorns.add(thorn_name)
        
        logging.info(f"Loaded {len(checked_thorns)} checked thorns from {mapping_file}")
        return checked_thorns
    
    def run_evaluation(self, examples: List[Dict[str, Any]], num_workers: int = 1) -> List[Dict[str, Any]]:
        """Run evaluation with specified number of workers"""
        if num_workers == 1:
            return self._run_single_threaded(examples)
        else:
            return self._run_parallel(examples, num_workers)
    
    def _run_single_threaded(self, examples: List[Dict[str, Any]]) -> List[Dict[str, Any]]:
        """Run single-threaded evaluation"""
        logging.info("Starting single-threaded evaluation")
        
        worker = EvaluationWorker(0, self.config)
        if not worker.setup():
            raise RuntimeError("Failed to setup evaluation worker")
        
        results = []
        try:
            for i, example in enumerate(examples):
                result = worker.process_example(example, i)
                results.append(result)
        finally:
            worker.cleanup()
        
        return results
    
    def _run_parallel(self, examples: List[Dict[str, Any]], num_workers: int) -> List[Dict[str, Any]]:
        """Run parallel evaluation"""
        logging.info(f"Starting parallel evaluation with {num_workers} workers")
        
        # Distribute work
        work_chunks = [[] for _ in range(num_workers)]
        for i, example in enumerate(examples):
            work_chunks[i % num_workers].append((example, i))
        
        results = []
        
        def run_worker(worker_id: int, work_items: List) -> List[Dict[str, Any]]:
            worker = EvaluationWorker(worker_id, self.config)
            worker_results = []
            
            try:
                if worker.setup():
                    for example, example_index in work_items:
                        result = worker.process_example(example, example_index)
                        worker_results.append(result)
                else:
                    logging.error(f"[Worker {worker_id}] Failed to setup")
            except Exception as e:
                logging.error(f"[Worker {worker_id}] Worker failed: {e}")
            finally:
                worker.cleanup()
            
            return worker_results
        
        # Run workers in parallel
        with ThreadPoolExecutor(max_workers=num_workers) as executor:
            futures = []
            for worker_id, work_items in enumerate(work_chunks):
                if work_items:  # Only start workers that have work
                    future = executor.submit(run_worker, worker_id, work_items)
                    futures.append(future)
            
            # Collect results
            for future in as_completed(futures):
                try:
                    worker_results = future.result()
                    results.extend(worker_results)
                except Exception as e:
                    logging.error(f"Worker failed: {e}")
        
        # Sort results by example index
        results.sort(key=lambda x: x.get('example_index', 0))
        return results
    
    def save_results(self, results: List[Dict[str, Any]], output_dir: str):
        """Save evaluation results"""
        os.makedirs(output_dir, exist_ok=True)
        
        timestamp = datetime.now().strftime('%Y%m%d_%H%M%S')
        output_file = os.path.join(output_dir, f"evaluation_results_{timestamp}.json")
        
        with open(output_file, 'w') as f:
            json.dump(results, f, indent=2)
        
        logging.info(f"Results saved to: {output_file}")
        return output_file
    
    def print_summary(self, results: List[Dict[str, Any]]):
        """Print evaluation summary"""
        successful_results = [r for r in results if r.get('success', False)]
        
        if not successful_results:
            print("No successful evaluations to summarize.")
            return
        
        total_examples = len(successful_results)
        avg_score = sum(r['score_result']['overall_score'] for r in successful_results) / total_examples
        build_success = len([r for r in successful_results if r['score_result']['build_score'] > 0])
        test_success = len([r for r in successful_results if r['score_result'].get('test_run_score', 0) > 0])
        
        print(f"\n{'='*60}")
        print("EVALUATION SUMMARY")
        print(f"{'='*60}")
        print(f"Total successful evaluations: {total_examples}")
        print(f"Average overall score: {avg_score:.1f}/100")
        print(f"Build success rate: {build_success}/{total_examples} ({100*build_success/total_examples:.1f}%)")
        print(f"Test success rate: {test_success}/{total_examples} ({100*test_success/total_examples:.1f}%)")
        
        # Score distribution
        score_ranges = [(90, 100), (80, 90), (70, 80), (60, 70), (50, 60), (0, 50)]
        print(f"\nScore Distribution:")
        for low, high in score_ranges:
            count = len([r for r in successful_results if low <= r['score_result']['overall_score'] < (high if high < 100 else 101)])
            print(f"  {low}-{high}: {count} examples ({100*count/total_examples:.1f}%)")


def main():
    """Main function"""
    parser = argparse.ArgumentParser(description='Einstein Toolkit Code Evaluator')
    parser.add_argument('--config', default='config.json', help='Configuration file path')
    parser.add_argument('--max-examples', type=int, help='Maximum number of examples to evaluate')
    parser.add_argument('--workers', type=int, default=1, help='Number of parallel workers')
    parser.add_argument('--output-dir', default='results', help='Output directory for results')
    
    args = parser.parse_args()
    
    try:
        # Initialize evaluator
        evaluator = ETEvaluator(args.config)
        
        # Reconfigure logging to use output directory
        # Clear existing handlers first
        for handler in logging.root.handlers[:]:
            logging.root.removeHandler(handler)
        evaluator.setup_logging(args.output_dir)
        
        logging.info("Einstein Toolkit Evaluator initialized")
        
        # Load dataset
        examples = evaluator.load_dataset(args.max_examples)
        if not examples:
            print("No valid examples found.")
            return 1
        
        # Run evaluation
        results = evaluator.run_evaluation(examples, args.workers)
        
        # Save results
        output_file = evaluator.save_results(results, args.output_dir)
        
        # Print summary
        evaluator.print_summary(results)
        
        # Upload to HuggingFace if enabled in config
        if evaluator.config.get('final_upload.upload_enabled', False):
            uploader = HuggingFaceUploader(evaluator.config)
            uploader.upload_results(results)
        
        print(f"\nEvaluation completed. Results saved to: {output_file}")
        return 0
        
    except Exception as e:
        logging.error(f"Evaluation failed: {e}")
        return 1


if __name__ == "__main__":
    sys.exit(main())
