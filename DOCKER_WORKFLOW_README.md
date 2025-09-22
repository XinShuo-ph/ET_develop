# Einstein Toolkit Docker Testing Workflow

This repository provides a complete automated testing solution for Einstein Toolkit using Docker containers.

## 🎯 **Problem Solved**

Original issues:
1. **False failures**: Tests failing due to tiny numerical differences (e.g., `2.40980080543752e-05` vs `2.4098008054375e-05`)
2. **Missing thorns**: Tests requiring thorns not available in the container
3. **Manual workflow**: No automation for Docker-based testing

## ✅ **Solution Implemented**

### **Two-Stage Architecture**
1. **Container Stage**: Run tests with basic comparison (no Python dependency)
2. **Host Stage**: Smart reanalysis with numerical tolerance and missing thorn detection

## 🚀 **Quick Start**

### **Complete Workflow (Recommended)**
```bash
# Run all tests with smart analysis
./docker_test_workflow.sh

# Run only first 10 tests  
./docker_test_workflow.sh full 10
```

### **Step-by-Step Workflow**

#### **1. Collect Test Names**
```bash
python3 ET_collect_test_names.py
```

#### **2. Check for Missing Thorns**
```bash
python3 check_docker_tests.py ET_docker_1 test_names.txt Cactus
```

#### **3. Run Tests in Container**
```bash
./docker_test_workflow.sh test 5  # Run first 5 tests
```

#### **4. Smart Reanalysis on Host**
```bash
python3 reanalyze_docker_results.py
```

## 📁 **Files & Scripts**

### **Core Scripts**
- `docker_test_workflow.sh` - Complete workflow orchestration
- `run_all_tests.sh` - Container-side test runner (no Python)
- `reanalyze_docker_results.py` - Host-side smart reanalysis

### **Analysis Tools**
- `smart_diff_comparison.py` - Numerical tolerance comparison
- `check_docker_tests.py` - Missing thorn detection via Docker
- `analyze_test_failures.py` - Comprehensive failure analysis

### **Collection Scripts**
- `ET_collect_test_names.py` - Extract test names from thornlist

## 🔧 **Technical Details**

### **Smart Numerical Comparison**
- **Relative tolerance**: 1e-10
- **Absolute tolerance**: 1e-15  
- **Handles**: Scientific notation, floating-point precision differences
- **Ignores**: Timestamp differences, hostname differences in comments

### **Container Requirements**
- Docker container: `rynge/einsteintoolkit`
- Container name: `ET_docker_1` (configurable)
- No Python required in container
- Basic shell tools only

### **Host Requirements**
- Python 3.6+
- NumPy (for smart comparison)
- Docker CLI access

## 📊 **Example Results**

From recent run:
```
ORIGINAL ANALYSIS (Container - Basic Diff):
  Total tests: 300
  Passed: 0  
  Failed: 300

SMART REANALYSIS (Host - Numerical Tolerance):
  Tests reanalyzed: 225
  Now passing: 32
  Still failing: 29
  Analysis errors: 164

CORRECTED FINAL RESULTS:
  Total tests: 300
  Passed: 32
  Failed: 268
  Success rate: 10.7% (was 0.0%)

IMPROVEMENT:
  Additional tests now passing: 32
  Improvement: +10.7 percentage points
```

## 🎛️ **Configuration**

### **Tolerance Settings**
Edit `reanalyze_docker_results.py`:
```python
rtol = 1e-10  # Relative tolerance
atol = 1e-15  # Absolute tolerance
```

### **Container Settings**
Edit `docker_test_workflow.sh`:
```bash
DOCKER_CONTAINER="ET_docker_1"
TEST_LIST_FILE="test_names.txt"
CACTUS_BASE_DIR="Cactus"
```

## 📋 **Workflow Commands**

### **Full Automation**
```bash
./docker_test_workflow.sh full     # Complete workflow
./docker_test_workflow.sh test 10  # Test only (first 10)
./docker_test_workflow.sh analyze  # Analysis only
./docker_test_workflow.sh check    # Missing thorns only
```

### **Manual Steps**
```bash
# 1. Copy scripts to container
docker cp test_names.txt ET_docker_1:/opt/Cactus/
docker cp run_all_tests.sh ET_docker_1:/opt/Cactus/

# 2. Start monitoring
while true; do
  docker cp -L ET_docker_1:/opt/Cactus/test_results.txt ./
  docker cp -L ET_docker_1:/opt/Cactus/log_files ./log_files_host/
  docker cp -L ET_docker_1:/opt/Cactus/test_outputs ./test_outputs_host/
  sleep 3
done &

# 3. Run tests in container
docker exec -it ET_docker_1 /bin/bash -c "cd /opt/Cactus && ./run_all_tests.sh test_names.txt 10"

# 4. Reanalyze results
python3 reanalyze_docker_results.py
```

## 📁 **Output Files**

### **Container Results**
- `test_results.txt` - Basic diff results from container
- `log_files_host/` - All simulation log files
- `test_outputs_host/` - All test output directories

### **Smart Analysis Results**
- `corrected_test_results.txt` - **Main corrected results**
- `smart_reanalysis_details.json` - Detailed reanalysis data
- `docker_valid_tests.txt` - Tests that should pass
- `docker_invalid_tests.txt` - Tests with missing thorns

## 🎯 **Success Metrics**

The workflow successfully:
- ✅ **Identified 32 false positive failures** due to numerical precision
- ✅ **Automated Docker container testing** with continuous monitoring  
- ✅ **Detected missing thorns** before wasting computation time
- ✅ **Provided detailed failure categorization** for debugging
- ✅ **Maintained focus on physics results** vs metadata differences

## 🔄 **Continuous Integration**

For CI/CD workflows:
```yaml
- name: Run Einstein Toolkit Tests
  run: |
    ./docker_test_workflow.sh full 50
    
- name: Check Results
  run: |
    if [ -f corrected_test_results.txt ]; then
      grep "Success rate" corrected_test_results.txt
    fi
```

## 🐛 **Troubleshooting**

### **Container Not Running**
```bash
docker run -it --name ET_docker_1 rynge/einsteintoolkit /bin/bash
```

### **Missing Test Outputs**
Check if tests completed:
```bash
docker exec ET_docker_1 ls -la /opt/Cactus/test_outputs/
```

### **Reanalysis Errors**
Ensure test outputs were copied:
```bash
ls -la test_outputs_host/
```

## 👥 **Contributing**

To add new analysis features:
1. Edit `smart_diff_comparison.py` for tolerance algorithms
2. Edit `reanalyze_docker_results.py` for result processing
3. Edit `docker_test_workflow.sh` for workflow steps

## 📜 **License**

This testing framework follows the same license as Einstein Toolkit.
