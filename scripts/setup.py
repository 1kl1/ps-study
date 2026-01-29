import argparse
import os
import requests
import shutil
from bs4 import BeautifulSoup

def setup_problem(problem_id):
    url = f"https://www.acmicpc.net/problem/{problem_id}"
    headers = {
        "User-Agent": "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.114 Safari/537.36"
    }

    print(f"Fetching problem {problem_id} from {url}...")
    try:
        response = requests.get(url, headers=headers)
        response.raise_for_status()
    except requests.exceptions.RequestException as e:
        print(f"Error fetching problem: {e}")
        return

    soup = BeautifulSoup(response.text, 'html.parser')

    # Create directory structure
    base_dir = os.path.dirname(os.path.dirname(os.path.abspath(__file__))) # Parent of scripts/
    problem_dir = os.path.join(base_dir, str(problem_id))
    data_dir = os.path.join(problem_dir, "data")

    if os.path.exists(problem_dir):
        print(f"Directory {problem_dir} already exists.")
        # Optional: Ask to overwrite? For now, we'll just proceed or maybe exit.
        # Let's proceed but warn.
    else:
        os.makedirs(problem_dir)
        os.makedirs(data_dir)
        print(f"Created directory {problem_dir}")

    # Copy templates
    templates_dir = os.path.join(base_dir, "scripts", "templates")
    template_cpp = os.path.join(templates_dir, "template.cpp")
    template_test = os.path.join(templates_dir, "test_runner.py")
    
    target_cpp = os.path.join(problem_dir, "main.cpp")
    target_test = os.path.join(problem_dir, "test.py")

    if not os.path.exists(target_cpp):
        shutil.copy(template_cpp, target_cpp)
        print("Created main.cpp")
    
    if not os.path.exists(target_test):
        shutil.copy(template_test, target_test)
        print("Created test.py")

    # Extract samples
    sample_index = 1
    while True:
        input_tag = soup.find("pre", id=f"sample-input-{sample_index}")
        output_tag = soup.find("pre", id=f"sample-output-{sample_index}")

        if not input_tag or not output_tag:
            break

        input_text = input_tag.text.strip()
        output_text = output_tag.text.strip()
        
        # Write to files
        in_file = os.path.join(data_dir, f"{sample_index}.in")
        out_file = os.path.join(data_dir, f"{sample_index}.out")
        
        with open(in_file, "w") as f:
            f.write(input_text)
        
        with open(out_file, "w") as f:
            f.write(output_text)
            
        print(f"Saved Sample {sample_index}")
        sample_index += 1

    print(f"Setup complete for problem {problem_id}")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Setup Baekjoon problem environment.")
    parser.add_argument("problem_id", type=int, help="The ID of the problem")
    args = parser.parse_args()
    
    setup_problem(args.problem_id)
