import subprocess
import os
import sys

def run_cmd(cmd, cwd=None):
    res = subprocess.run(cmd, shell=True, capture_output=True, text=True, cwd=cwd)
    return res.returncode, res.stdout, res.stderr

def test_problem(prob_dir, src_file, test_cases):
    print(f"\n==========================================")
    print(f" Testing: {prob_dir}")
    print(f"==========================================")
    
    full_dir = os.path.join(os.path.dirname(__file__), prob_dir)
    exe_path = os.path.join(full_dir, "solution.exe")
    src_path = os.path.join(full_dir, src_file)

    # Try gcc/clang
    ret, out, err = run_cmd(f"gcc -O2 -std=c99 \"{src_path}\" -o \"{exe_path}\"")
    if ret != 0:
        # Fallback to cl (MSVC)
        ret, out, err = run_cmd(f"cl /nologo /O2 \"{src_path}\" /Fe:\"{exe_path}\"", cwd=full_dir)

    if ret != 0:
        print(f"[FAIL] Compilation failed for {prob_dir}:\n{err}")
        return False
    
    print(f"[OK] Compilation successful: {src_file}")

    all_passed = True
    for idx, (inp, expected) in enumerate(test_cases, 1):
        p = subprocess.Popen([exe_path], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        stdout, stderr = p.communicate(input=inp)
        actual = stdout.strip()
        expected_clean = expected.strip()
        
        if actual == expected_clean:
            print(f"  [PASS] Test Case {idx}: PASSED")
        else:
            print(f"  [FAIL] Test Case {idx}: FAILED")
            print(f"     Expected: {expected_clean}")
            print(f"     Actual:   {actual}")
            all_passed = False
            
    # Cleanup binary
    if os.path.exists(exe_path):
        try:
            os.remove(exe_path)
        except Exception:
            pass
            
    return all_passed

def main():
    base_dir = os.path.dirname(__file__)
    
    # 1. Diagonal Difference
    dd_tc = [
        ("3\n11 2 4\n4 5 6\n10 8 -12\n", "15")
    ]
    
    # 2. Dynamic Array
    da_tc = [
        ("2 5\n1 0 5\n1 1 7\n1 0 3\n2 1 0\n2 1 1\n", "7\n3")
    ]
    
    # 3. Time Conversion
    tc_tc = [
        ("07:05:45PM", "19:05:45"),
        ("12:00:00AM", "00:00:00"),
        ("12:00:00PM", "12:00:00")
    ]
    
    # 4. Compare Triplets
    ct_tc = [
        ("5 6 7\n3 6 10", "1 1"),
        ("17 28 30\n99 16 8", "2 1")
    ]
    
    # 5. Sparse Arrays
    sa_tc = [
        ("4\naba\nbaba\naba\nxzxb\n3\naba\nxzxb\nab", "2\n1\n0")
    ]
    
    results = [
        test_problem("01_diagonal_difference", "solution.c", dd_tc),
        test_problem("02_dynamic_array", "solution.c", da_tc),
        test_problem("03_time_conversion", "solution.c", tc_tc),
        test_problem("04_compare_triplets", "solution.c", ct_tc),
        test_problem("05_sparse_arrays", "solution.c", sa_tc)
    ]
    
    print("\n==========================================")
    if all(results):
        print("ALL 5 MANDATORY PROBLEMS PASSED SUCCESSFULLY!")
    else:
        print("SOME TEST CASES FAILED. PLEASE REVIEW LOGS ABOVE.")
    print("==========================================\n")

if __name__ == "__main__":
    main()
