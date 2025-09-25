# Tolerance Testing

Simple script to test different numerical tolerance combinations for Einstein Toolkit reanalysis.

## Usage

at the root of this repository:
```bash
./tol_test/test_tolerances.sh
```

## Output

- `checked_tests_rtol*_atol*.txt` - List of tests that pass for each tolerance combination
- `tolerance_summary.txt` - Simple table with rtol, atol, and number of passed tests

## Requirements

- `../test_results.txt` - Test results from container
- `../test_outputs_host/` - Test outputs from container
- `../reanalyze_docker_results.py` - Modified reanalysis script
