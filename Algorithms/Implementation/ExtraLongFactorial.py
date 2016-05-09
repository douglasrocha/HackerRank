import sys

n = int(sys.stdin.readline())

print reduce(lambda x, y: x * y, range(1,n+1))
