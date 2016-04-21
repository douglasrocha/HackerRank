import sys

lines = sys.stdin.readlines()
fl = int(lines.pop(0))
sl = int(lines.pop(0))

print map(int, lines[0].split()).index(fl)
