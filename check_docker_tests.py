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
            
        # Look for ActiveThorns parameter (case insensitive)
        pattern = r'ActiveThorns\s*=\s*["\']([^"\']*(?:\n[^"\']*)*)["\']'
        matches = re.findall(pattern, content, re.IGNORECASE | re.MULTILINE | re.DOTALL)
        
        for match in matches:
            # Split on whitespace and filter out empty strings and comments
            lines = match.split('\n')
            for line in lines:
                # Remove comments (everything after #)
                line = line.split('#')[0].strip()
                thorn_list = [t.strip() for t in line.split() if t.strip()]
                thorns.update(thorn_list)
    
    except Exception as e:
        print(f"Error reading {parfile_path}: {e}")
    
    return thorns

def create_par_check_directory(docker_container):
    """Create the par_check directory in the Docker container"""
    try:
        result = subprocess.run(
            ['docker', 'exec', docker_container, 'mkdir', '-p', '/opt/Cactus/par_check'],
            capture_output=True,
            text=True,
            timeout=10
        )
        return result.returncode == 0
    except Exception as e:
        print(f"Error creating par_check directory: {e}")
        return False

def check_thorns_with_docker(docker_container, parfile_path):
    """Use Docker to run Cactus and check parameter file"""
    missing_thorns = set()
    
    try:
        # Run cactus with -P flag inside docker container from par_check directory
        docker_parfile_path = f"/opt/Cactus/{parfile_path}"
        
        result = subprocess.run(
            ['docker', 'exec', '-w', '/opt/Cactus/par_check', docker_container, '/opt/Cactus/exe/cactus_sim', '-P', docker_parfile_path],
            capture_output=True,
            text=True,
            timeout=30
        )
        
        # Parse output for missing thorn errors
        output = result.stderr + result.stdout
        
        # Look for "Error: Thorn X not found" patterns
        error_patterns = [
            r'Error:\s+Thorn\s+(\w+)\s+not\s+found',
            r'Thorn\s+(\w+)\s+not\s+found'
        ]
        
        for pattern in error_patterns:
            matches = re.findall(pattern, output, re.IGNORECASE)
            missing_thorns.update(matches)
        
        # Check for activation failures
        is_valid = "Activation failed" not in output and result.returncode != 1
        
        return missing_thorns, is_valid, output
        
    except subprocess.TimeoutExpired:
        return set(), False, "Timeout while checking parameter file"
    except Exception as e:
        return set(), False, f"Error running Docker command: {e}"

def check_docker_tests(docker_container, test_list_file, cactus_base_dir):
    """Check tests for missing thorns using Docker container"""
    
    if not os.path.exists(test_list_file):
        print(f"Error: Test list file {test_list_file} not found!")
        return False
    
    # Check if docker container is running
    try:
        result = subprocess.run(['docker', 'ps', '--filter', f'name={docker_container}', '--format', '{{.Names}}'], 
                              capture_output=True, text=True)
        if docker_container not in result.stdout:
            print(f"Error: Docker container '{docker_container}' is not running!")
            print("Start it with: docker exec -it {docker_container} /bin/bash")
            return False
    except Exception as e:
        print(f"Error checking Docker container: {e}")
        return False
    
    # Create par_check directory in the container
    print(f"Creating /opt/Cactus/par_check directory in container...")
    if not create_par_check_directory(docker_container):
        print("Warning: Failed to create par_check directory")
    else:
        print("Successfully created par_check directory")
    
    print(f"Checking tests for missing thorns using Docker container: {docker_container}")
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
        
        # Construct parameter file path in local copy
        local_parfile_path = f"{cactus_base_dir}/arrangements/{test_path}.par"
        docker_parfile_path = f"arrangements/{test_path}.par"
        
        if not os.path.exists(local_parfile_path):
            print(f"  ❌ Parameter file not found locally: {local_parfile_path}")
            invalid_tests.append({
                'test_path': test_path,
                'reason': 'Parameter file not found locally',
                'missing_thorns': [],
                'parfile_path': local_parfile_path
            })
            continue
        
        # Check with Docker
        missing_thorns, is_valid, docker_output = check_thorns_with_docker(docker_container, docker_parfile_path)
        
        if missing_thorns:
            print(f"  ❌ Missing thorns: {sorted(missing_thorns)}")
            invalid_tests.append({
                'test_path': test_path,
                'reason': 'Missing thorns',
                'missing_thorns': sorted(missing_thorns),
                'parfile_path': local_parfile_path
            })
            all_missing_thorns.update(missing_thorns)
        elif not is_valid:
            print(f"  ❌ Invalid parameter file")
            invalid_tests.append({
                'test_path': test_path,
                'reason': 'Invalid parameter file',
                'missing_thorns': [],
                'parfile_path': local_parfile_path
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
    with open('docker_invalid_tests.txt', 'w') as f:
        f.write("# Invalid Einstein Toolkit Tests (Docker Analysis)\n")
        f.write("# Generated by check_docker_tests.py\n")
        f.write(f"# Docker container: {docker_container}\n")
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
    with open('docker_valid_tests.txt', 'w') as f:
        f.write("# Valid Einstein Toolkit Tests (Docker Analysis)\n")
        f.write("# Generated by check_docker_tests.py\n")
        f.write(f"# Docker container: {docker_container}\n")
        f.write(f"# Total valid tests: {len(valid_tests)}\n")
        f.write("\n")
        
        for test_path in valid_tests:
            f.write(f"{test_path}\n")
    
    # Write JSON summary
    summary = {
        'docker_container': docker_container,
        'total_tests': total_tests,
        'valid_tests': len(valid_tests),
        'invalid_tests': len(invalid_tests),
        'all_missing_thorns': sorted(all_missing_thorns),
        'invalid_test_details': invalid_tests,
        'valid_test_list': valid_tests
    }
    
    with open('docker_test_check_summary.json', 'w') as f:
        json.dump(summary, f, indent=2)
    
    print(f"\nResults written to:")
    print(f"  Invalid tests: docker_invalid_tests.txt")
    print(f"  Valid tests: docker_valid_tests.txt") 
    print(f"  JSON summary: docker_test_check_summary.json")
    
    return len(invalid_tests) == 0

def main():
    if len(sys.argv) < 2:
        print("Usage: python3 check_docker_tests.py <docker_container> [test_list_file] [cactus_base_dir]")
        print("  docker_container: Name of running Docker container (e.g., ET_docker_1)")
        print("  test_list_file: File containing test names (default: test_names.txt)")
        print("  cactus_base_dir: Base directory with Cactus copy (default: Cactus)")
        print("")
        print("Example: python3 check_docker_tests.py ET_docker_1 test_names.txt Cactus")
        sys.exit(1)
    
    docker_container = sys.argv[1]
    test_list_file = sys.argv[2] if len(sys.argv) > 2 else "test_names.txt"
    cactus_base_dir = sys.argv[3] if len(sys.argv) > 3 else "Cactus"
    
    all_valid = check_docker_tests(docker_container, test_list_file, cactus_base_dir)
    
    # Exit with appropriate code
    sys.exit(0 if all_valid else 1)

if __name__ == "__main__":
    main()
