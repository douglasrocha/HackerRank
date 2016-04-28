import sys

lines = sys.stdin.readlines()
fl = lines.pop(0)

v = map(lambda x: x ** 2, xrange(1,100000))

for line in lines:
    l_array = map(int, line.split())
    print len(filter(lambda x: x >= l_array[0] and x <= l_array[1], v))
