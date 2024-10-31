import subprocess
from .testcases import testset, TestData
import os
COMPILER = "g++"
INTERIOR = "main"
SIMPLEX = "simplex"

def open_process(proc_name: str) -> subprocess.Popen:
    return subprocess.Popen([proc_name], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True) 

def compile_src(path: str):
    os.system(f"{COMPILER} {path} -o {path.split('.')[0]}")

print("Compiling sources...")
try:
    compile_src(f"{INTERIOR}.cpp")
    compile_src(f"{SIMPLEX}.cpp")
except Exception as e:
    print("During compilation there is some errors {e} try to change compiler in tester settings")    

def solve(proc_name: str, data: TestData):
    proc: subprocess.Popen = open_process(f"./{INTERIOR}")
    print("-- Input --\n",data.__repr__(),sep='')

    proc.stdin.write(data.__repr__())
    proc.stdin.flush()
    if (err:= proc.stderr.readlines()):
        print(f"Catch error during solving: {err}")
        return
    output = proc.stdout.readlines()
    proc.kill()
    if output: print("-- Output --\n",*output)
    return output

print("Start testing...")

for index, test in enumerate(testset, 1):
    os.system("clear")
    print(f"Test# {index} Interior Point Algo (alpha = 0.5)")
    interior_data = test.interior
    interior_data.alpha = 0.5
    solve(proc_name=INTERIOR, data= interior_data)

    print(f"Test# {index} Interior Point Algo (alpha = 0.9)")
    interior_data.alpha = 0.9
    solve(proc_name=INTERIOR, data= interior_data)
    
    print(f"Test# {index} Simplex method")
    simplex_data = test.simplex
    solve(proc_name=SIMPLEX, data= simplex_data)
    
    input("Press Enter to display next test...")