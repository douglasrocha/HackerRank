import sys

line = sys.stdin.readline()
integers = map(int, line.split())

a = integers[0]
b = integers[1]
n = integers[2]
result = b

for x in range(3, n+1):
    result = b * b + a
    a = b
    b = result

print result
