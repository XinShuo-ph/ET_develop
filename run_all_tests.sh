#!/bin/bash

# Script to run Einstein Toolkit all tests and check diffs
# Usage: ./run_all_tests.sh [test_list_file] [max_tests]
# Arguments:
#   test_list_file: File containing test names (default: test_names.txt)
#   max_tests: Maximum number of tests to run (default: all tests)

# Show help if requested
if [[ "$1" == "-h" || "$1" == "--help" ]]; then
    echo "Usage: $0 [test_list_file] [max_tests]"
    echo ""
    echo "Arguments:"
    echo "  test_list_file    File containing test names (default: test_names.txt)"
    echo "  max_tests        Maximum number of tests to run (default: run all)"
    echo ""
    echo "Examples:"
    echo "  $0                           # Run all tests from test_names.txt"
    echo "  $0 my_tests.txt              # Run all tests from my_tests.txt"
    echo "  $0 test_names.txt 5          # Run first 5 tests from test_names.txt"
    echo "  $0 my_tests.txt 10           # Run first 10 tests from my_tests.txt"
    echo ""
    echo "Output directories:"
    echo "  log_files/       - Simulation log files"
    echo "  test_outputs/    - Test output directories"
    echo "  test_results.txt - Detailed results summary"
    exit 0
fi

TEST_LIST_FILE=${1:-"test_names.txt"}
MAX_TESTS=${2:-0}  # 0 means run all tests
CACTUS_EXE="./exe/cactus_sim"
RESULTS_FILE="test_results.txt"

# Validate MAX_TESTS parameter
if [[ -n "$2" ]] && ! [[ "$MAX_TESTS" =~ ^[0-9]+$ ]]; then
    echo "Error: max_tests must be a positive integer, got: '$2'"
    echo "Use -h or --help for usage information."
    exit 1
fi

# Check if test list file exists
if [ ! -f "$TEST_LIST_FILE" ]; then
    echo "Error: Test list file '$TEST_LIST_FILE' not found!"
    echo "Run ET_collect_test_names.py first to generate the test list."
    exit 1
fi

# Check if Cactus executable exists
if [ ! -f "$CACTUS_EXE" ]; then
    echo "Error: Cactus executable '$CACTUS_EXE' not found!"
    echo "Make sure you have compiled Cactus and are running from the Cactus directory."
    exit 1
fi

# Create dedicated directories for outputs
LOG_DIR="log_files"
OUTPUT_DIR="test_outputs"

mkdir -p "$LOG_DIR"
mkdir -p "$OUTPUT_DIR"

echo "Created directories:"
echo "  Log files: $LOG_DIR"
echo "  Test outputs: $OUTPUT_DIR"
echo ""

# Display test run information
if [ "$MAX_TESTS" -gt 0 ]; then
    echo "Configuration: Running first $MAX_TESTS tests from $TEST_LIST_FILE"
else
    echo "Configuration: Running all tests from $TEST_LIST_FILE"
fi
echo ""

# Initialize results file
echo "Einstein Toolkit Test Results" > "$RESULTS_FILE"
echo "=============================" >> "$RESULTS_FILE"
echo "Started: $(date)" >> "$RESULTS_FILE"
echo "Log files directory: $LOG_DIR" >> "$RESULTS_FILE"
echo "Test outputs directory: $OUTPUT_DIR" >> "$RESULTS_FILE"
if [ "$MAX_TESTS" -gt 0 ]; then
    echo "Maximum tests to run: $MAX_TESTS" >> "$RESULTS_FILE"
else
    echo "Running all available tests" >> "$RESULTS_FILE"
fi
echo "" >> "$RESULTS_FILE"

# Counters
total_tests=0
passed_tests=0
failed_tests=0

echo "Running Einstein Toolkit tests..."
echo "Results will be saved to $RESULTS_FILE"
echo ""

# Read each test from the file
while IFS= read -r test_path; do
    # Skip empty lines and comments
    [[ -z "$test_path" || "$test_path" =~ ^[[:space:]]*# ]] && continue
    
    total_tests=$((total_tests + 1))
    
    # Check if we've reached the maximum number of tests
    if [ "$MAX_TESTS" -gt 0 ] && [ "$total_tests" -gt "$MAX_TESTS" ]; then
        echo "Reached maximum test limit ($MAX_TESTS). Stopping."
        echo "Reached maximum test limit ($MAX_TESTS). Stopping." >> "$RESULTS_FILE"
        break
    fi
    
    # Extract test name from path (e.g., "WVUThorns/IllinoisGRMHD/test/magnetizedTOV" -> "magnetizedTOV")
    test_name=$(basename "$test_path")
    thorn_path=$(dirname "$test_path")
    
    if [ "$MAX_TESTS" -gt 0 ]; then
        echo "Running test $total_tests/$MAX_TESTS: $test_path"
        echo "Test $total_tests/$MAX_TESTS: $test_path" >> "$RESULTS_FILE"
    else
        echo "Running test $total_tests: $test_path"
        echo "Test $total_tests: $test_path" >> "$RESULTS_FILE"
    fi
    echo "----------------------------------------" >> "$RESULTS_FILE"
    
    # Full path to parameter file
    par_file="arrangements/$test_path.par"
    
    # Check if parameter file exists
    if [ ! -f "$par_file" ]; then
        echo "  ERROR: Parameter file $par_file not found!"
        echo "  Result: MISSING_PARFILE" >> "$RESULTS_FILE"
        echo "" >> "$RESULTS_FILE"
        failed_tests=$((failed_tests + 1))
        continue
    fi
    
    # Run the test
    log_file="$LOG_DIR/${test_name}_test.log"
    echo "  Running: $CACTUS_EXE $par_file"
    
    if timeout 600 $CACTUS_EXE "$par_file" > "$log_file" 2>&1; then
        echo "  Simulation completed successfully"
        
        # Check if output directory was created
        if [ -d "$test_name" ]; then
            # Save output to dedicated directory
            output_save_dir="$OUTPUT_DIR/${test_name}"
            mv "$test_name" "$output_save_dir"
            echo "  Output saved to: $output_save_dir"
            
            # Compare with benchmark
            benchmark_dir="arrangements/$test_path"
            
            if [ -d "$benchmark_dir" ]; then
                echo "  Comparing results with benchmark (basic diff - will be reanalyzed on host)..."
                
                # Use basic diff for now - smart analysis will happen on host
                diff_output=$(diff -r "$output_save_dir" "$benchmark_dir" 2>&1)
                diff_exit_code=$?
                
                if [ $diff_exit_code -eq 0 ]; then
                    echo "  Result: PASS (no differences found)"
                    echo "  Result: PASS" >> "$RESULTS_FILE"
                    echo "  Output directory: $output_save_dir" >> "$RESULTS_FILE"
                    echo "  Note: Basic diff used - host analysis pending" >> "$RESULTS_FILE"
                    passed_tests=$((passed_tests + 1))
                else
                    echo "  Result: FAIL (differences found - needs host analysis)"
                    echo "  Result: FAIL" >> "$RESULTS_FILE"
                    echo "  Output directory: $output_save_dir" >> "$RESULTS_FILE"
                    echo "  Note: Basic diff used - may be false positive due to numerical precision" >> "$RESULTS_FILE"
                    echo "  Differences:" >> "$RESULTS_FILE"
                    echo "$diff_output" >> "$RESULTS_FILE"
                    failed_tests=$((failed_tests + 1))
                fi
            else
                echo "  ERROR: Benchmark directory $benchmark_dir not found!"
                echo "  Result: MISSING_BENCHMARK" >> "$RESULTS_FILE"
                echo "  Output directory: $output_save_dir" >> "$RESULTS_FILE"
                failed_tests=$((failed_tests + 1))
            fi
        else
            echo "  ERROR: No output directory created!"
            echo "  Result: NO_OUTPUT" >> "$RESULTS_FILE"
            failed_tests=$((failed_tests + 1))
        fi
    else
        echo "  ERROR: Simulation failed or timed out!"
        echo "  Result: SIMULATION_FAILED" >> "$RESULTS_FILE"
        echo "  Log file: $log_file" >> "$RESULTS_FILE"
        failed_tests=$((failed_tests + 1))
    fi
    
    echo "" >> "$RESULTS_FILE"
    echo ""
    
done < "$TEST_LIST_FILE"

# Summary
echo "========================================="
echo "Test Summary:"
echo "  Total tests: $total_tests"
echo "  Passed: $passed_tests"
echo "  Failed: $failed_tests"
echo "========================================="

# Write summary to results file
echo "" >> "$RESULTS_FILE"
echo "=========================================" >> "$RESULTS_FILE"
echo "SUMMARY" >> "$RESULTS_FILE"
echo "=========================================" >> "$RESULTS_FILE"
echo "Total tests: $total_tests" >> "$RESULTS_FILE"
echo "Passed: $passed_tests" >> "$RESULTS_FILE"
echo "Failed: $failed_tests" >> "$RESULTS_FILE"
echo "Completed: $(date)" >> "$RESULTS_FILE"

echo ""
echo "Files saved to:"
echo "  Detailed results: $RESULTS_FILE"
echo "  Log files: $LOG_DIR/"
echo "  Test outputs: $OUTPUT_DIR/"

# Exit with appropriate code
if [ $failed_tests -eq 0 ]; then
    exit 0
else
    exit 1
fi
