import subprocess

result=subprocess.run(
    ["a.exe","kanchan","baran","hazra"],
    capture_output=True,
    text=True
)

print(result.stdout)