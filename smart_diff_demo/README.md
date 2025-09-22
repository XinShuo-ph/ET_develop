# Smart Diff Comparison Demo

This demo shows how `smart_diff_comparison.py` handles numerical tolerance in Einstein Toolkit testing.

## Problem Demonstrated

**Traditional `diff` fails on tiny numerical differences:**
```bash
$ diff output/data.asc benchmark/data.asc
# Shows differences like:
< 2.40980080543752e-05
> 2.4098008054375e-05
# (Difference: 2.00e-19 - essentially noise)
```

## Solution: Smart Numerical Comparison

**Smart comparison with tolerance succeeds:**
```bash
$ python3 ../smart_diff_comparison.py output benchmark
Directories match within tolerance
```

## Key Test Cases

### 1. Tiny Differences (Should Pass)
Files have differences in last digits of floating-point numbers:
- `2.40980080543752e-05` vs `2.4098008054375e-05`
- Result: ✅ **PASS** with default tolerance (rtol=1e-10)

### 2. Significant Differences (Should Fail)  
Files have meaningful numerical differences:
- `0.00302197459901474` vs `0.00999999999999999`
- Result: ❌ **FAIL** - real physics difference detected

### 3. Tolerance Control
```bash
# Strict tolerance - catches tiny differences
$ python3 ../smart_diff_comparison.py output benchmark 1e-15 1e-20
# Result: FAIL

# Default tolerance - ignores noise, catches real differences  
$ python3 ../smart_diff_comparison.py output benchmark 1e-10 1e-15
# Result: PASS

# Loose tolerance - accepts almost anything
$ python3 ../smart_diff_comparison.py output benchmark_bad 1e-1 1e-2  
# Result: PASS (even significant differences)
```

## Internal Mechanics

**Number extraction and comparison:**
```python
# Extracts: ['0', '1', '1', '1', '0', '-9.5', '-9.5', '-9.5', '2.40980080543752e-05']
# Compares each number with numpy.allclose(rtol=1e-10, atol=1e-15)
# Actual difference: 2.00e-19 (within tolerance)
```

