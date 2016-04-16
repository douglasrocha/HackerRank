import sys

lines = sys.stdin.readlines()
n = lines.pop(0)

for line in lines:
    print sum(map(int, line.split()))
