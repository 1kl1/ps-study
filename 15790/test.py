import os
import subprocess
import sys

def run_tests():
    # Compile the C++ solution
    compile_cmd = ["g++", "-std=c++17", "-O2", "main.cpp", "-o", "main"]
    print(f"Compiling: {' '.join(compile_cmd)}")
    result = subprocess.run(compile_cmd, capture_output=True, text=True)
    
    if result.returncode != 0:
        print("Compilation Error:")
        print(result.stderr)
        return

    print("Compilation Successful.")
    
    # Get all .in files in the data directory
    data_dir = "data"
    if not os.path.exists(data_dir):
        print("Data directory not found.")
        return

    input_files = [f for f in os.listdir(data_dir) if f.endswith(".in")]
    input_files.sort()

    passed = 0
    total = 0

    for in_file in input_files:
        test_case_name = in_file[:-3] # remove .in
        out_file = f"{test_case_name}.out"
        
        in_path = os.path.join(data_dir, in_file)
        out_path = os.path.join(data_dir, out_file)
        
        if not os.path.exists(out_path):
            print(f"Skipping {test_case_name}: Output file not found.")
            continue

        total += 1
        
        print(f"Running Test {test_case_name}...", end=" ")
        
        try:
            with open(in_path, 'r') as f_in:
                # Run the compiled executable
                proc = subprocess.run(["./main"], stdin=f_in, capture_output=True, text=True, timeout=2)
                
                with open(out_path, 'r') as f_out:
                    expected_output = f_out.read().strip()
                    actual_output = proc.stdout.strip()
                    
                    if expected_output == actual_output:
                        print("PASSED")
                        passed += 1
                    else:
                        print("FAILED")
                        print("Expected:")
                        print(expected_output)
                        print("Actual:")
                        print(actual_output)
                        if proc.stderr:
                             print("Stderr:")
                             print(proc.stderr)

        except subprocess.TimeoutExpired:
            print("TLE (Time Limit Exceeded)")
        except Exception as e:
            print(f"Error: {e}")

    print(f"\nResult: {passed}/{total} passed.")

if __name__ == "__main__":
    run_tests()
