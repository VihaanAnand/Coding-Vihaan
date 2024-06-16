import subprocess
output = subprocess.check_output("pwd", shell = True).decode()
print(output)