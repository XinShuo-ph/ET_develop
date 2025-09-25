#!/usr/bin/env python3

import subprocess
import os
import time

class DockerManager:
    """Manage Docker operations for EinsteinToolkit testing"""
    
    def __init__(self, container_name="ET_test_container"):
        self.container_name = container_name
        self.image_name = "rynge/einsteintoolkit"
        self.container_running = False
    
    def run_command(self, command, capture_output=True):
        """Run a shell command and return result"""
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
        self.run_command(f"docker rm -f {self.container_name}")
        
        # Start new container
        cmd = f"docker run -d --name {self.container_name} {self.image_name} tail -f /dev/null"
        returncode, stdout, stderr = self.run_command(cmd)
        
        if returncode == 0:
            print(f"Container {self.container_name} started successfully")
            self.container_running = True
            
            # Wait a moment for container to be ready
            time.sleep(2)
            
            # Setup initial files based on container_files_change.md
            self.setup_initial_files()
            return True
        else:
            print(f"Failed to start container: {stderr}")
            return False
    
    def setup_initial_files(self):
        """Copy initial required files to container as specified in container_files_change.md"""
        print("Setting up initial files in container...")
        
        base_dir = "/Users/bytedance/ET_develop"  # Adjust as needed
        
        files_to_copy = [
            ("Cactus/configs/sim/ThornList", "/opt/Cactus/configs/sim/ThornList"),
            ("run_all_tests.sh", "/opt/Cactus/run_all_tests.sh"),
            ("test_names.txt", "/opt/Cactus/test_names.txt"),
            ("ADMConstraints", "/opt/Cactus/arrangements/EinsteinAnalysis/ADMConstraints")
        ]
        
        for src, dst in files_to_copy:
            src_path = os.path.join(base_dir, src)
            if os.path.exists(src_path):
                self.copy_to_container(src_path, dst)
            else:
                print(f"Warning: {src_path} not found, skipping")
        
        # Make run_all_tests.sh executable
        self.execute_in_container("chmod +x /opt/Cactus/run_all_tests.sh")
        
        # Create log_files directory
        self.execute_in_container("mkdir -p /opt/Cactus/log_files")
    
    def copy_to_container(self, src_path, dst_path):
        """Copy file or directory to container"""
        cmd = f"docker cp -L {src_path} {self.container_name}:{dst_path}"
        returncode, stdout, stderr = self.run_command(cmd)
        
        if returncode == 0:
            print(f"Copied {src_path} to {dst_path}")
            return True
        else:
            print(f"Failed to copy {src_path}: {stderr}")
            return False
    
    def copy_from_container(self, src_path, dst_path):
        """Copy file or directory from container"""
        cmd = f"docker cp -L {self.container_name}:{src_path} {dst_path}"
        returncode, stdout, stderr = self.run_command(cmd)
        
        if returncode == 0:
            print(f"Copied {src_path} from container to {dst_path}")
            return True
        else:
            print(f"Failed to copy from container: {stderr}")
            return False
    
    def execute_in_container(self, command, working_dir="/opt/Cactus"):
        """Execute command inside the container"""
        full_cmd = f"docker exec {self.container_name} bash -c 'cd {working_dir} && {command}'"
        returncode, stdout, stderr = self.run_command(full_cmd)
        
        return returncode, stdout, stderr
    
    def build_cactus(self):
        """Build Cactus in the container"""
        print("Building Cactus...")
        returncode, stdout, stderr = self.execute_in_container(
            "./simfactory/bin/sim build > ./log_files/build_log.txt 2>&1"
        )
        
        if returncode == 0:
            print("Cactus build completed successfully")
            return True
        else:
            print(f"Cactus build failed: {stderr}")
            return False
    
    def stop_container(self):
        """Stop and remove the container"""
        if self.container_running:
            print(f"Stopping container: {self.container_name}")
            self.run_command(f"docker rm -f {self.container_name}")
            self.container_running = False
    
    def __del__(self):
        """Cleanup when object is destroyed"""
        self.stop_container()

def test_docker_management():
    """Test docker management functions"""
    
    print("Testing Docker management...")
    
    # Check if docker is available
    returncode, stdout, stderr = subprocess.run("docker --version", shell=True, capture_output=True, text=True).returncode, "", ""
    
    if returncode != 0:
        print("Docker not available, creating mock test")
        return False
    
    docker_mgr = DockerManager("test_et_container")
    
    # Test starting container (this will likely fail if image not present)
    success = docker_mgr.start_container()
    
    if success:
        print("Docker container started successfully")
        
        # Test executing a simple command
        returncode, stdout, stderr = docker_mgr.execute_in_container("ls -la")
        print(f"Test command result: {returncode}")
        if stdout:
            print(f"Output: {stdout[:200]}...")
        
        # Stop container
        docker_mgr.stop_container()
    else:
        print("Failed to start Docker container (this is expected if image is not pulled)")
    
    return success

if __name__ == "__main__":
    test_docker_management()
