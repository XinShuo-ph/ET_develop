#!/usr/bin/env python3

import os
import re

class EinsteinToolkitTester:
    """Handle building and testing specific thorns in EinsteinToolkit"""
    
    def __init__(self, docker_manager):
        self.docker_manager = docker_manager
        self.thorn_to_tests_mapping = {}
        self.load_thorn_test_mapping()
    
    def load_thorn_test_mapping(self):
        """Load the mapping from thorn_to_tests.txt"""
        mapping_file = "/Users/bytedance/ET_develop/thorn_to_tests.txt"
        current_thorn = None
        
        if not os.path.exists(mapping_file):
            print(f"Warning: {mapping_file} not found!")
            return
        
        with open(mapping_file, 'r') as f:
            for line in f:
                original_line = line
                line = line.strip()
                
                # Skip empty lines and comments
                if not line or line.startswith('#'):
                    continue
                
                # Check if this is a thorn header line
                if ':' in line and 'tests' in line:
                    current_thorn = line.split(':')[0].strip()
                    self.thorn_to_tests_mapping[current_thorn] = []
                
                # Check if this is a test line (starts with spaces in original line)
                elif original_line.startswith('  ') and current_thorn:
                    test_path = line
                    if test_path and not test_path.startswith('#'):
                        self.thorn_to_tests_mapping[current_thorn].append(test_path)
        
        print(f"Loaded test mapping for {len(self.thorn_to_tests_mapping)} thorns")
    
    def get_tests_for_thorn(self, thorn_name):
        """Get list of tests for a specific thorn"""
        return self.thorn_to_tests_mapping.get(thorn_name, [])
    
    def deploy_generated_code(self, thorn_name, src_filename, generated_code):
        """Deploy generated code to the appropriate location in the docker container"""
        
        # Determine the target path in the container
        thorn_path = f"/opt/Cactus/arrangements/{thorn_name}"
        src_dir = f"{thorn_path}/src"
        target_file = f"{src_dir}/{src_filename}"
        
        print(f"Deploying generated code to {target_file}")
        
        # Write the generated code to a temporary file
        temp_file = f"/tmp/generated_{src_filename}"
        with open(temp_file, 'w') as f:
            f.write(generated_code)
        
        # Copy to container
        success = self.docker_manager.copy_to_container(temp_file, target_file)
        
        # Clean up temp file
        if os.path.exists(temp_file):
            os.remove(temp_file)
        
        return success
    
    def build_cactus(self):
        """Build Cactus in the container"""
        print("Building Cactus with updated code...")
        
        # Run the build command
        returncode, stdout, stderr = self.docker_manager.execute_in_container(
            "./simfactory/bin/sim build"
        )
        
        # Also capture build log
        log_returncode, log_stdout, log_stderr = self.docker_manager.execute_in_container(
            "cat ./log_files/build_log.txt 2>/dev/null || echo 'No build log found'"
        )
        
        build_success = (returncode == 0)
        
        result = {
            'success': build_success,
            'returncode': returncode,
            'stdout': stdout,
            'stderr': stderr,
            'build_log': log_stdout if log_returncode == 0 else "Build log not available"
        }
        
        print(f"Build {'SUCCEEDED' if build_success else 'FAILED'}")
        if not build_success:
            print(f"Build error: {stderr}")
        
        return result
    
    def run_tests_for_thorn(self, thorn_name):
        """Run all tests associated with a specific thorn"""
        
        tests = self.get_tests_for_thorn(thorn_name)
        if not tests:
            print(f"No tests found for thorn {thorn_name}")
            return {
                'success': False,
                'message': 'No tests found for thorn',
                'test_results': []
            }
        
        print(f"Running {len(tests)} tests for thorn {thorn_name}")
        
        test_results = []
        overall_success = True
        
        for test_path in tests:
            print(f"  Running test: {test_path}")
            
            # Extract test name from path
            test_name = os.path.basename(test_path)
            
            # Build parameter file path
            par_file = f"arrangements/{test_path}.par"
            
            # Check if parameter file exists
            check_cmd = f"test -f {par_file} && echo 'EXISTS' || echo 'MISSING'"
            returncode, stdout, stderr = self.docker_manager.execute_in_container(check_cmd)
            
            if 'MISSING' in stdout:
                print(f"    Parameter file {par_file} not found!")
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
            
            # Get test log
            log_cmd = f"cat log_files/{test_name}_test.log 2>/dev/null || echo 'No test log'"
            log_returncode, log_stdout, log_stderr = self.docker_manager.execute_in_container(log_cmd)
            
            test_result = {
                'test_name': test_name,
                'test_path': test_path,
                'success': test_success,
                'returncode': returncode,
                'log': log_stdout if log_returncode == 0 else "Log not available"
            }
            
            test_results.append(test_result)
            
            if not test_success:
                overall_success = False
                print(f"    Test FAILED (return code: {returncode})")
            else:
                print(f"    Test PASSED")
        
        return {
            'success': overall_success,
            'message': f"Ran {len(tests)} tests",
            'test_results': test_results,
            'total_tests': len(tests),
            'passed_tests': sum(1 for r in test_results if r['success']),
            'failed_tests': sum(1 for r in test_results if not r['success'])
        }

def test_build_functions():
    """Test the build and test functions"""
    
    print("Testing build and test functions...")
    
    # Create a mock docker manager for testing
    class MockDockerManager:
        def execute_in_container(self, command):
            print(f"Mock executing: {command}")
            return 0, "Mock output", ""
        
        def copy_to_container(self, src, dst):
            print(f"Mock copying {src} to {dst}")
            return True
    
    mock_docker = MockDockerManager()
    tester = EinsteinToolkitTester(mock_docker)
    
    # Test loading thorn mapping
    print(f"Loaded {len(tester.thorn_to_tests_mapping)} thorns")
    
    # Test getting tests for a specific thorn
    test_thorn = "CactusExamples/Poisson"
    tests = tester.get_tests_for_thorn(test_thorn)
    print(f"Tests for {test_thorn}: {tests}")
    
    # Test deploying code (mock)
    mock_code = "#include <stdio.h>\nint main() { return 0; }"
    tester.deploy_generated_code(test_thorn, "test.c", mock_code)
    
    return True

if __name__ == "__main__":
    test_build_functions()
