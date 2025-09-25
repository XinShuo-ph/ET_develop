#!/usr/bin/env python3

import os
import sys
from collections import defaultdict

def parse_thornlist_for_arrangement(thornlist_file, arrangement_name):
    """Parse ThornList file to get all active thorns in a specific arrangement"""
    
    active_thorns = []
    
    if not os.path.exists(thornlist_file):
        return active_thorns
    
    with open(thornlist_file, 'r') as f:
        for line in f:
            line = line.strip()
            
            # Skip comments and empty lines
            if not line or line.startswith('#') or line.startswith('!'):
                continue
            
            # Look for thorns in the specified arrangement
            if line.startswith(f"{arrangement_name}/"):
                thorn_path = line.strip()
                # Extract just the thorn name (after the arrangement/)
                thorn_name = thorn_path.split('/', 1)[1]
                active_thorns.append(thorn_name)
    
    return active_thorns

def find_actual_thorn(test_path, cactus_base_dir="Cactus"):
    """Find the actual thorn being tested by a test path"""
    
    # Parse the test path: ArrangementName/ThornName/test/TestName
    path_parts = test_path.strip().split('/')
    if len(path_parts) < 4 or path_parts[2] != 'test':
        return None
    
    arrangement = path_parts[0]
    potential_thorn = path_parts[1]
    
    # First try: check if this is a test thorn and the base thorn exists (prioritize base thorn)
    test_suffixes = ['_Test', '_test', 'Test', 'test']
    for suffix in test_suffixes:
        if potential_thorn.endswith(suffix):
            base_thorn = potential_thorn[:-len(suffix)]
            base_thorn_path = f"{cactus_base_dir}/arrangements/{arrangement}/{base_thorn}"
            if os.path.exists(base_thorn_path) and os.path.isdir(base_thorn_path):
                return f"{arrangement}/{base_thorn}"
    
    # Second try: exact match (if no base thorn found)
    potential_thorn_path = f"{cactus_base_dir}/arrangements/{arrangement}/{potential_thorn}"
    if os.path.exists(potential_thorn_path) and os.path.isdir(potential_thorn_path):
        return f"{arrangement}/{potential_thorn}"
    
    # Third try: look for similar thorns in the same arrangement
    arrangement_dir = f"{cactus_base_dir}/arrangements/{arrangement}"
    if os.path.exists(arrangement_dir):
        thorns_in_arrangement = [d for d in os.listdir(arrangement_dir) 
                               if os.path.isdir(os.path.join(arrangement_dir, d))]
        
        # Look for thorns that are prefixes of the test thorn or vice versa
        for thorn in thorns_in_arrangement:
            if (potential_thorn.startswith(thorn) or thorn.startswith(potential_thorn)) and thorn != potential_thorn:
                return f"{arrangement}/{thorn}"
    
    # If no match found, return the original guess
    return f"{arrangement}/{potential_thorn}"

def main():
    checked_tests_file = 'checked_tests.txt'
    cactus_base_dir = 'Cactus'
    thornlist_file = f'{cactus_base_dir}/configs/sim/ThornList'
    
    if not os.path.exists(checked_tests_file):
        print(f"Error: {checked_tests_file} not found!")
        sys.exit(1)
    
    if not os.path.exists(cactus_base_dir):
        print(f"Error: {cactus_base_dir} directory not found!")
        sys.exit(1)
    
    # Read checked tests
    tests = []
    with open(checked_tests_file, 'r') as f:
        for line in f:
            line = line.strip()
            if line and not line.startswith('#'):
                tests.append(line)
    
    print(f"Processing {len(tests)} checked tests...")
    
    # Get active EinsteinExact thorns for special handling
    einstein_exact_thorns = parse_thornlist_for_arrangement(thornlist_file, "EinsteinExact")
    # Remove test thorns, keep only the actual physics thorns
    einstein_exact_physics_thorns = [t for t in einstein_exact_thorns if not t.endswith('_Test')]
    
    print(f"Found {len(einstein_exact_physics_thorns)} EinsteinExact physics thorns: {einstein_exact_physics_thorns}")
    
    # Map tests to thorns (note: test_to_thorns can have multiple thorns per test)
    test_to_thorns = defaultdict(list)  # test_path -> [list of thorns]
    thorn_to_tests = defaultdict(list)  # thorn -> [list of tests]
    
    unresolved_tests = []
    
    for test_path in tests:
        # Special case: EinsteinExact_Test tests all EinsteinExact physics thorns
        if test_path.startswith("EinsteinExact/EinsteinExact_Test/test/"):
            print(f"  Special case: {test_path} -> maps to all EinsteinExact physics thorns")
            
            # Map this test to all EinsteinExact physics thorns
            for thorn_name in einstein_exact_physics_thorns:
                thorn = f"EinsteinExact/{thorn_name}"
                test_to_thorns[test_path].append(thorn)
                thorn_to_tests[thorn].append(test_path)
            
        else:
            # Normal case: find single thorn
            thorn = find_actual_thorn(test_path, cactus_base_dir)
            
            if thorn:
                test_to_thorns[test_path].append(thorn)
                thorn_to_tests[thorn].append(test_path)
                
                # Check if the thorn directory actually exists
                thorn_dir = f"{cactus_base_dir}/arrangements/{thorn}"
                if not os.path.exists(thorn_dir):
                    unresolved_tests.append((test_path, thorn, "thorn directory not found"))
            else:
                unresolved_tests.append((test_path, "unknown", "could not parse test path"))
    
    # Write test-to-thorns mapping  
    with open('test_to_thorns.txt', 'w') as f:
        f.write("# Test to Thorns Mapping\n")
        f.write(f"# Generated from {checked_tests_file}\n")
        f.write(f"# Total tests: {len(tests)}\n")
        f.write(f"# Format: test_path: thorn1, thorn2, ...\n")
        f.write("#\n")
        f.write("# SPECIAL CASE: EinsteinExact/EinsteinExact_Test/test/* maps to ALL EinsteinExact physics thorns\n")
        f.write(f"# EinsteinExact physics thorns: {einstein_exact_physics_thorns}\n")
        f.write("#\n")
        
        for test_path in sorted(test_to_thorns.keys()):
            thorns_list = test_to_thorns[test_path]
            f.write(f"{test_path}: {len(thorns_list)} thorn{'s' if len(thorns_list) != 1 else ''}\n")
            for thorn in sorted(thorns_list):
                f.write(f"  {thorn}\n")
            f.write("\n")
    
    # Write thorn-to-tests mapping
    with open('thorn_to_tests.txt', 'w') as f:
        f.write("# Thorn to Tests Mapping\n")
        f.write(f"# Generated from {checked_tests_file}\n")
        f.write(f"# Total thorns: {len(thorn_to_tests)}\n")
        f.write(f"# Format: thorn_path: test1, test2, ...\n")
        f.write("#\n")
        f.write("# NOTE: EinsteinExact/EinsteinExact_Test/test/* tests appear under ALL EinsteinExact physics thorns\n")
        f.write(f"# EinsteinExact physics thorns: {einstein_exact_physics_thorns}\n")
        f.write("#\n")
        
        for thorn in sorted(thorn_to_tests.keys()):
            tests_list = thorn_to_tests[thorn]
            f.write(f"{thorn}: {len(tests_list)} tests\n")
            for test in sorted(tests_list):
                f.write(f"  {test}\n")
            f.write("\n")
    
    # Print summary
    print(f"\n📊 SUMMARY:")
    print(f"  Total tests processed: {len(tests)}")
    print(f"  Unique thorns found: {len(thorn_to_tests)}")
    print(f"  Successfully mapped: {len(test_to_thorns)}")
    print(f"  Unresolved: {len(unresolved_tests)}")
    print(f"  EinsteinExact physics thorns: {len(einstein_exact_physics_thorns)}")
    
    # Show some statistics
    if thorn_to_tests:
        test_counts = [len(tests) for tests in thorn_to_tests.values()]
        max_tests = max(test_counts)
        avg_tests = sum(test_counts) / len(test_counts)
        
        # Statistics for tests mapping to multiple thorns
        thorn_counts = [len(thorns) for thorns in test_to_thorns.values()]
        multi_thorn_tests = [test for test, thorns in test_to_thorns.items() if len(thorns) > 1]
        
        print(f"\n📈 STATISTICS:")
        print(f"  Max tests per thorn: {max_tests}")
        print(f"  Average tests per thorn: {avg_tests:.1f}")
        print(f"  Tests mapping to multiple thorns: {len(multi_thorn_tests)}")
        print(f"  Max thorns per test: {max(thorn_counts)}")
        
        # Find thorns with most tests
        top_thorns = sorted(thorn_to_tests.items(), key=lambda x: len(x[1]), reverse=True)[:5]
        print(f"\n🏆 TOP THORNS BY TEST COUNT:")
        for thorn, test_list in top_thorns:
            print(f"  {thorn}: {len(test_list)} tests")
    
    # Show EinsteinExact special case info
    einstein_exact_tests = [test for test in tests if test.startswith("EinsteinExact/EinsteinExact_Test/test/")]
    if einstein_exact_tests:
        print(f"\n🌟 SPECIAL CASE - EinsteinExact_Test:")
        print(f"  Tests found: {len(einstein_exact_tests)}")
        print(f"  These tests map to ALL {len(einstein_exact_physics_thorns)} EinsteinExact physics thorns:")
        for thorn_name in einstein_exact_physics_thorns:
            print(f"    EinsteinExact/{thorn_name}")
        print(f"  Test list:")
        for test in einstein_exact_tests:
            print(f"    {test}")
    
    # Show unresolved tests if any
    if unresolved_tests:
        print(f"\n⚠️  UNRESOLVED TESTS:")
        for test, thorn, reason in unresolved_tests[:10]:  # Show first 10
            print(f"  {test} -> {thorn} ({reason})")
        if len(unresolved_tests) > 10:
            print(f"  ... and {len(unresolved_tests) - 10} more")
    
    print(f"\n📁 Files generated:")
    print(f"  test_to_thorns.txt - Test to thorns mapping")
    print(f"  thorn_to_tests.txt - Thorn to tests mapping")

if __name__ == "__main__":
    main()
