import sys

lines = sys.stdin.readlines()
n = int(lines.pop(0))

d1 = 0
d2 = 0

for i in range(n):
    d1 += int(lines[i].split()[i])
    d2 += int(lines[i].split()[n - i - 1])

print abs(d1 - d2)
