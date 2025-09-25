#!/bin/bash

# Script to prepare a list of valid tests by checking for missing thorns
# Usage: ./prepare_valid_tests.sh [cactus_exe] [test_list_file]

CACTUS_EXE=${1:-"./exe/cactus_sim"}
TEST_LIST_FILE=${2:-"test_names.txt"}

echo "Einstein Toolkit Test Preparation"
echo "=================================="
echo "Cactus executable: $CACTUS_EXE"
echo "Original test list: $TEST_LIST_FILE"
echo ""

# Check if files exist
if [ ! -f "$CACTUS_EXE" ]; then
    echo "Error: Cactus executable '$CACTUS_EXE' not found!"
    echo "Make sure you have compiled Cactus and are running from the Cactus directory."
    exit 1
fi

if [ ! -f "$TEST_LIST_FILE" ]; then
    echo "Error: Test list file '$TEST_LIST_FILE' not found!"
    echo "Run ET_collect_test_names.py first to generate the test list."
    exit 1
fi

# Make scripts executable
chmod +x smart_diff_comparison.py
chmod +x check_missing_thorns.py

echo "Checking all tests for missing thorns..."
echo "This may take a few minutes..."
echo ""

# Run the missing thorn checker
python3 check_missing_thorns.py "$CACTUS_EXE" "$TEST_LIST_FILE"

if [ $? -eq 0 ]; then
    echo ""
    echo "✅ All tests are valid!"
    echo "You can run: ./run_all_tests.sh $TEST_LIST_FILE"
else
    echo ""
    echo "⚠️  Some tests have missing thorns or other issues."
    echo ""
    echo "Files generated:"
    echo "  📋 valid_tests.txt - Tests that should pass"
    echo "  ❌ invalid_tests.txt - Tests with missing thorns"
    echo "  📊 test_check_summary.json - Detailed analysis"
    echo ""
    echo "Recommended commands:"
    echo "  Run only valid tests: ./run_all_tests.sh valid_tests.txt"
    echo "  Run first 5 valid tests: ./run_all_tests.sh valid_tests.txt 5"
    echo "  Review invalid tests: cat invalid_tests.txt"
    echo ""
    
    # Show summary of what was found
    if [ -f "test_check_summary.json" ]; then
        echo "Quick Summary:"
        if command -v jq >/dev/null 2>&1; then
            echo "  Total tests: $(jq '.total_tests' test_check_summary.json)"
            echo "  Valid tests: $(jq '.valid_tests' test_check_summary.json)"
            echo "  Invalid tests: $(jq '.invalid_tests' test_check_summary.json)"
            echo "  Missing thorns found: $(jq -r '.all_missing_thorns | join(", ")' test_check_summary.json)"
        else
            echo "  (Install 'jq' for detailed summary display)"
        fi
    fi
fi

echo ""
echo "Test preparation completed!"

