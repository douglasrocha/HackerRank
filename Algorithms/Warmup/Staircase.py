import sys

n = int(sys.stdin.readline())

for i in range(1, n + 1):
    line = ""

    for j in range(n - i):
        line += " "

    for j in range(i):
        line += "#"

    print line
