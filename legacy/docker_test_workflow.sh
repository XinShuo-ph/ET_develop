#!/bin/bash

# Einstein Toolkit Docker Testing Workflow
# This script orchestrates the complete testing process for Docker-based setup

DOCKER_CONTAINER="ET_docker_1"
TEST_LIST_FILE="test_names.txt"
CACTUS_BASE_DIR="Cactus"

echo "Einstein Toolkit Docker Testing Workflow"
echo "========================================"
echo "Docker container: $DOCKER_CONTAINER"
echo "Test list file: $TEST_LIST_FILE"
echo "Cactus base directory: $CACTUS_BASE_DIR"
echo ""

# Function to check if container is running
check_container() {
    if ! docker ps --filter "name=$DOCKER_CONTAINER" --format '{{.Names}}' | grep -q "$DOCKER_CONTAINER"; then
        echo "❌ Error: Docker container '$DOCKER_CONTAINER' is not running!"
        echo "Start it with: docker run -it --name $DOCKER_CONTAINER rynge/einsteintoolkit /bin/bash"
        exit 1
    fi
    echo "✅ Docker container '$DOCKER_CONTAINER' is running"
}

# Function to copy scripts to container
copy_scripts_to_container() {
    echo ""
    echo "📋 Copying test scripts to container..."
    
    if [ ! -f "$TEST_LIST_FILE" ]; then
        echo "❌ Error: $TEST_LIST_FILE not found!"
        echo "Run: python3 ET_collect_test_names.py to generate it"
        exit 1
    fi
    
    if [ ! -f "run_all_tests.sh" ]; then
        echo "❌ Error: run_all_tests.sh not found!"
        exit 1
    fi
    
    # Copy test list and runner script
    docker cp "$TEST_LIST_FILE" "$DOCKER_CONTAINER:/opt/Cactus/"
    docker cp "run_all_tests.sh" "$DOCKER_CONTAINER:/opt/Cactus/"
    
    # Make script executable in container
    docker exec "$DOCKER_CONTAINER" chmod +x "/opt/Cactus/run_all_tests.sh"
    
    echo "✅ Scripts copied to container"
}

# Function to start monitoring in background
start_monitoring() {
    echo ""
    echo "📊 Starting result monitoring..."
    echo "Files will be copied from container every 3 seconds"
    echo "Press Ctrl+C to stop monitoring after tests complete"
    echo ""
    
    # Create monitoring directories
    mkdir -p log_files_host test_outputs_host
    
    # Start monitoring loop in background
    while true; do
        docker cp -L "$DOCKER_CONTAINER:/opt/Cactus/test_results.txt" ./ 2>/dev/null
        docker cp -L "$DOCKER_CONTAINER:/opt/Cactus/log_files" ./log_files_host/ 2>/dev/null
        docker cp -L "$DOCKER_CONTAINER:/opt/Cactus/test_outputs" ./test_outputs_host/ 2>/dev/null
        sleep 3
    done &
    
    MONITOR_PID=$!
    echo "Monitoring started (PID: $MONITOR_PID)"
}

# Function to run tests in container
run_tests_in_container() {
    local max_tests=${1:-0}
    
    echo ""
    echo "🚀 Starting tests in container..."
    
    if [ "$max_tests" -gt 0 ]; then
        echo "Running first $max_tests tests"
        docker exec -it "$DOCKER_CONTAINER" /bin/bash -c "cd /opt/Cactus && ./run_all_tests.sh $TEST_LIST_FILE $max_tests"
    else
        echo "Running all tests"
        docker exec -it "$DOCKER_CONTAINER" /bin/bash -c "cd /opt/Cactus && ./run_all_tests.sh $TEST_LIST_FILE"
    fi
    
    echo "Tests completed in container"
}

# Function to stop monitoring
stop_monitoring() {
    if [ ! -z "$MONITOR_PID" ]; then
        echo ""
        echo "🛑 Stopping monitoring..."
        kill $MONITOR_PID 2>/dev/null
        wait $MONITOR_PID 2>/dev/null
        echo "Monitoring stopped"
    fi
}

# Function to final sync results
final_sync() {
    echo ""
    echo "📥 Final sync of results from container..."
    
    docker cp -L "$DOCKER_CONTAINER:/opt/Cactus/test_results.txt" ./
    docker cp -L "$DOCKER_CONTAINER:/opt/Cactus/log_files" ./log_files_host/ 2>/dev/null
    docker cp -L "$DOCKER_CONTAINER:/opt/Cactus/test_outputs" ./test_outputs_host/ 2>/dev/null
    
    echo "✅ Final sync completed"
}

# Function to run host-side analysis
run_host_analysis() {
    echo ""
    echo "🔬 Running host-side smart analysis..."
    
    # Make analysis scripts executable
    chmod +x reanalyze_docker_results.py check_docker_tests.py smart_diff_comparison.py
    
    # Run reanalysis of results with smart numerical comparison
    if [ -f "test_results.txt" ]; then
        echo "Reanalyzing test results with smart numerical comparison..."
        python3 reanalyze_docker_results.py
    else
        echo "⚠️  test_results.txt not found - skipping reanalysis"
    fi
    
    echo "✅ Host-side analysis completed"
}

# Function to check for missing thorns
check_missing_thorns() {
    echo ""
    echo "🔍 Checking for missing thorns..."
    
    if [ -f "$TEST_LIST_FILE" ] && [ -d "$CACTUS_BASE_DIR" ]; then
        python3 check_docker_tests.py "$DOCKER_CONTAINER" "$TEST_LIST_FILE" "$CACTUS_BASE_DIR"
    else
        echo "⚠️  Skipping missing thorn check - files not available"
    fi
}

# Function to show final summary
show_summary() {
    echo ""
    echo "📊 WORKFLOW SUMMARY"
    echo "==================="
    
    if [ -f "corrected_test_results.txt" ]; then
        echo "Smart reanalysis completed:"
        grep -E "(Total tests|Passed|Failed|Success rate)" corrected_test_results.txt | head -10
    fi
    
    echo ""
    echo "Generated files:"
    [ -f "test_results.txt" ] && echo "  📋 test_results.txt - Container test results"
    [ -f "corrected_test_results.txt" ] && echo "  ✅ corrected_test_results.txt - Smart reanalysis results"
    [ -f "smart_reanalysis_details.json" ] && echo "  📊 smart_reanalysis_details.json - Detailed reanalysis data"
    [ -f "docker_valid_tests.txt" ] && echo "  🟢 docker_valid_tests.txt - Tests that should pass"
    [ -f "docker_invalid_tests.txt" ] && echo "  🔴 docker_invalid_tests.txt - Tests with missing thorns"
    [ -d "log_files_host" ] && echo "  📁 log_files_host/ - Test log files"
    [ -d "test_outputs_host" ] && echo "  📁 test_outputs_host/ - Test output files"
    
    echo ""
    echo "Recommended next steps:"
    
    if [ -f "docker_valid_tests.txt" ]; then
        valid_count=$(grep -v "^#" docker_valid_tests.txt | wc -l)
        echo "  🚀 Run only valid tests: docker exec -it $DOCKER_CONTAINER /bin/bash -c 'cd /opt/Cactus && ./run_all_tests.sh docker_valid_tests.txt'"
    fi
    
    if [ -f "corrected_test_results.txt" ]; then
        echo "  📖 Review smart analysis: cat corrected_test_results.txt"
    fi
}

# Trap to cleanup on exit
cleanup() {
    stop_monitoring
    exit 0
}
trap cleanup INT TERM

# Main workflow
main() {
    local command=${1:-"full"}
    local max_tests=${2:-0}
    
    case $command in
        "check")
            check_container
            check_missing_thorns
            ;;
        "test")
            check_container
            copy_scripts_to_container
            start_monitoring
            run_tests_in_container "$max_tests"
            stop_monitoring
            final_sync
            ;;
        "analyze") 
            run_host_analysis
            show_summary
            ;;
        "full"|*)
            check_container
            copy_scripts_to_container
            start_monitoring
            run_tests_in_container "$max_tests"
            stop_monitoring
            final_sync
            run_host_analysis
            show_summary
            ;;
    esac
}

# Show help
if [[ "$1" == "-h" || "$1" == "--help" ]]; then
    echo "Usage: $0 [command] [max_tests]"
    echo ""
    echo "Commands:"
    echo "  full     - Complete workflow: test + analyze (default)"
    echo "  test     - Only run tests in container"
    echo "  analyze  - Only run host-side analysis"
    echo "  check    - Only check for missing thorns"
    echo ""
    echo "Arguments:"
    echo "  max_tests - Limit number of tests to run (default: all)"
    echo ""
    echo "Examples:"
    echo "  $0                    # Run all tests with full analysis"
    echo "  $0 test 10           # Run only first 10 tests"
    echo "  $0 analyze           # Only reanalyze existing results"
    echo "  $0 check             # Only check for missing thorns"
    exit 0
fi

main "$@"

