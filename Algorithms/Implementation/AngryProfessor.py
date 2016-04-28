import sys

lines = sys.stdin.readlines()
fl = lines.pop(0)

for ix in range(0, len(lines), 2):
    k = int(lines[ix].split()[1])
    iss = map(int, lines[ix + 1].split())
    ks = filter(lambda x: x <= 0, iss)

    if len(ks) >= k:
        print "NO"
    else:
        print "YES"
