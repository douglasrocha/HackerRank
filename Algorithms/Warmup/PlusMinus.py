import sys

lines = sys.stdin.readlines()
n = float(lines.pop(0))

for line in lines:
    l = map(float, line.split())
    a = filter(lambda x: x > 0, l)
    b = filter(lambda x: x < 0, l)
    c = filter(lambda x: x == 0, l)

    print '%.3f' % round(len(a) / n, 3)
    print '%.3f' % round(len(b) / n, 3)
    print '%.3f' % round(len(c) / n, 3)
