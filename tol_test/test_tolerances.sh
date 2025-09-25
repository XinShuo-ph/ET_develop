#!/bin/bash

# Simple tolerance testing for Einstein Toolkit
# Tests different rtol/atol combinations and keeps only checked_tests files

set -e

echo "Einstein Toolkit Tolerance Testing"
echo "=================================="

# Check required files (should be run from repository root)
if [[ ! -f "reanalyze_docker_results.py" ]] || [[ ! -f "test_results.txt" ]] || [[ ! -d "test_outputs_host" ]]; then
    echo "Error: Required files not found!"
    echo "Please run this script from the repository root where test_results.txt is located."
    exit 1
fi

# Test configurations
declare -a TOLERANCE_CONFIGS=(
    "1e-3,1e-6"
    "1e-4,1e-7"
    "1e-4,1e-8"
    "1e-5,1e-9"
    "1e-5,1e-10"
    "1e-6,1e-11"
    "1e-6,1e-12"
    "1e-8,1e-14"
    "1e-10,1e-15"
)

# Create summary table header
SUMMARY_FILE="tol_test/tolerance_summary.txt"
echo "# rtol atol passed_tests" > $SUMMARY_FILE

# Clean up any existing files from previous runs
# rm -f tol_test/checked_tests_rtol*.txt tol_test/corrected_test_results_rtol*.txt tol_test/smart_reanalysis_details_rtol*.json

echo "Testing ${#TOLERANCE_CONFIGS[@]} tolerance combinations..."

# Test each configuration
for i in "${!TOLERANCE_CONFIGS[@]}"; do
    config="${TOLERANCE_CONFIGS[$i]}"
    IFS=',' read -r rtol atol <<< "$config"
    
    echo "[$((i+1))/${#TOLERANCE_CONFIGS[@]}] Testing rtol=${rtol}, atol=${atol}"
    
    # Run reanalysis and capture only the checked_tests file
    if python3 reanalyze_docker_results.py --rtol "$rtol" --atol "$atol" --output-dir "tol_test"; then
        
        # Convert to scientific notation format to match Python script output
        rtol_sci=$(python3 -c "print(f'{float(\"$rtol\"):.0e}')")
        atol_sci=$(python3 -c "print(f'{float(\"$atol\"):.0e}')")
        
        # Construct exact expected filename
        checked_file="tol_test/checked_tests_rtol${rtol_sci}_atol${atol_sci}.txt"
        
        if [[ -f "$checked_file" ]]; then
            # Extract count from "# Total checked tests: N" line
            passed_tests=$(grep "# Total checked tests:" "$checked_file" | grep -oE '[0-9]+')
            echo "  ✅ $passed_tests tests passed"
            
            # Add to summary
            echo "$rtol $atol $passed_tests" >> $SUMMARY_FILE
        else
            echo "  ❌ checked_tests file not found: $checked_file"
            echo "$rtol $atol ERROR" >> $SUMMARY_FILE
        fi
        
        # Clean up other files from this run, keep only checked_tests
        rm -f "tol_test/corrected_test_results_rtol${rtol_sci}_atol${atol_sci}.txt"
        rm -f "tol_test/smart_reanalysis_details_rtol${rtol_sci}_atol${atol_sci}.json"
    else
        echo "  ❌ Failed to run"
        echo "$rtol $atol FAILED" >> $SUMMARY_FILE
    fi
done

echo ""
echo "Results Summary:"
echo "================"
printf "%-10s %-10s %-15s\n" "rtol" "atol" "passed_tests"
echo "-------------------------------------"

# Display summary table
while read -r line; do
    if [[ ! "$line" =~ ^# ]]; then
        printf "%-10s %-10s %-15s\n" $line
    fi
done < $SUMMARY_FILE

echo ""
echo "✅ Testing complete!"
echo "📁 checked_tests files: tol_test/checked_tests_rtol*_atol*.txt"
echo "📋 Summary table: $SUMMARY_FILE"
