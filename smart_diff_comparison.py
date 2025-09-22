#!/usr/bin/env python3

import os
import sys
import re
import numpy as np
from pathlib import Path

def parse_number(text):
    """Extract numbers from text, handling scientific notation"""
    # Find all numeric patterns including scientific notation
    number_pattern = r'[-+]?[0-9]*\.?[0-9]+(?:[eE][-+]?[0-9]+)?'
    return re.findall(number_pattern, text)

def compare_numbers(num1_str, num2_str, relative_tolerance=1e-10, absolute_tolerance=1e-15):
    """Compare two numbers with tolerance"""
    try:
        num1 = float(num1_str)
        num2 = float(num2_str)
        
        # Use numpy's allclose for robust comparison
        return np.allclose([num1], [num2], rtol=relative_tolerance, atol=absolute_tolerance)
    except (ValueError, TypeError):
        # If can't convert to float, do string comparison
        return num1_str.strip() == num2_str.strip()

def compare_lines_with_tolerance(line1, line2, rtol=1e-10, atol=1e-15):
    """Compare two lines, replacing numbers with tolerance-based comparison"""
    
    # Skip comment lines (they're already filtered out by shell script, but double-check)
    if line1.strip().startswith('#') or line2.strip().startswith('#'):
        return True
        
    # Extract numbers from both lines
    numbers1 = parse_number(line1)
    numbers2 = parse_number(line2)
    
    # If different number of numbers, lines are different
    if len(numbers1) != len(numbers2):
        return False
    
    # If no numbers, do direct string comparison
    if len(numbers1) == 0:
        return line1.strip() == line2.strip()
    
    # Compare each number pair
    for num1, num2 in zip(numbers1, numbers2):
        if not compare_numbers(num1, num2, rtol, atol):
            return False
    
    # Check if non-numeric parts match by replacing numbers with placeholders
    line1_clean = line1
    line2_clean = line2
    
    for num in numbers1:
        line1_clean = line1_clean.replace(num, 'NUM', 1)
    for num in numbers2:
        line2_clean = line2_clean.replace(num, 'NUM', 1)
    
    return line1_clean.strip() == line2_clean.strip()

def compare_files_with_tolerance(file1_path, file2_path, rtol=1e-10, atol=1e-15):
    """Compare two files with numerical tolerance"""
    
    if not os.path.exists(file1_path) or not os.path.exists(file2_path):
        return False, f"File missing: {file1_path} or {file2_path}"
    
    try:
        with open(file1_path, 'r', encoding='utf-8', errors='ignore') as f1, \
             open(file2_path, 'r', encoding='utf-8', errors='ignore') as f2:
            
            lines1 = f1.readlines()
            lines2 = f2.readlines()
            
            if len(lines1) != len(lines2):
                return False, f"Different number of lines: {len(lines1)} vs {len(lines2)}"
            
            differences = []
            for i, (line1, line2) in enumerate(zip(lines1, lines2), 1):
                if not compare_lines_with_tolerance(line1, line2, rtol, atol):
                    differences.append(f"Line {i}: '{line1.strip()}' != '{line2.strip()}'")
                    
                    # Limit reported differences to avoid huge output
                    if len(differences) > 10:
                        differences.append("... (more differences found)")
                        break
            
            if differences:
                return False, "\n".join(differences)
            else:
                return True, "Files match within tolerance"
                
    except Exception as e:
        return False, f"Error comparing files: {e}"

def compare_directories_with_tolerance(dir1, dir2, rtol=1e-10, atol=1e-15):
    """Compare two directories with numerical tolerance"""
    
    dir1_path = Path(dir1)
    dir2_path = Path(dir2)
    
    if not dir1_path.exists() or not dir2_path.exists():
        return False, f"Directory missing: {dir1} or {dir2}"
    
    # Get all files in both directories
    files1 = set()
    files2 = set()
    
    for file_path in dir1_path.rglob('*'):
        if file_path.is_file():
            rel_path = file_path.relative_to(dir1_path)
            files1.add(rel_path)
    
    for file_path in dir2_path.rglob('*'):
        if file_path.is_file():
            rel_path = file_path.relative_to(dir2_path)
            files2.add(rel_path)
    
    # Check for missing files
    missing_in_dir2 = files1 - files2
    missing_in_dir1 = files2 - files1
    
    differences = []
    
    if missing_in_dir1:
        differences.append(f"Files only in {dir2}: {sorted(missing_in_dir1)}")
    if missing_in_dir2:
        differences.append(f"Files only in {dir1}: {sorted(missing_in_dir2)}")
    
    # Compare common files
    common_files = files1 & files2
    
    for rel_path in sorted(common_files):
        file1_path = dir1_path / rel_path
        file2_path = dir2_path / rel_path
        
        # Skip binary files or very large files
        try:
            if file1_path.stat().st_size > 100 * 1024 * 1024:  # Skip files > 100MB
                continue
                
            # Try to determine if it's a text file
            with open(file1_path, 'rb') as f:
                sample = f.read(1024)
                if b'\0' in sample:  # Binary file
                    continue
        except:
            continue
        
        matches, diff_msg = compare_files_with_tolerance(file1_path, file2_path, rtol, atol)
        if not matches:
            differences.append(f"File {rel_path}:\n{diff_msg}")
            
            # Limit number of file differences reported
            if len(differences) > 20:
                differences.append("... (more file differences found)")
                break
    
    if differences:
        return False, "\n".join(differences)
    else:
        return True, "Directories match within tolerance"

def main():
    if len(sys.argv) < 3:
        print("Usage: python3 smart_diff_comparison.py <output_dir> <benchmark_dir> [rtol] [atol]")
        print("  rtol: relative tolerance (default: 1e-10)")
        print("  atol: absolute tolerance (default: 1e-15)")
        sys.exit(1)
    
    output_dir = sys.argv[1]
    benchmark_dir = sys.argv[2]
    
    # Parse tolerance parameters
    rtol = float(sys.argv[3]) if len(sys.argv) > 3 else 1e-10
    atol = float(sys.argv[4]) if len(sys.argv) > 4 else 1e-15
    
    matches, message = compare_directories_with_tolerance(output_dir, benchmark_dir, rtol, atol)
    
    print(message)
    
    # Exit with appropriate code
    sys.exit(0 if matches else 1)

if __name__ == "__main__":
    main()
