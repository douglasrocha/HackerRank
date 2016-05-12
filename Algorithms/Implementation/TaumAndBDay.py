import sys

lines = sys.stdin.readlines()
t = int(lines.pop(0))

for _ in xrange(t):
    b, w = map(int, lines.pop(0).split())
    x,y,z = map(int, lines.pop(0).split())
    value = 0

    if x > y+z:
        value = b*(y+z) + w*y
    elif y > x+z:
        value = b*x + w*(x+z)
    else:
        value = b*x + w*y

    print value
