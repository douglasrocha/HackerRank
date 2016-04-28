import sys

lines = sys.stdin.readlines()
ln = lines.pop(0)

for line in lines:
    il = int(line)
    cc = 0

    for c in str(il):
        if int(c) == 0:
            continue

        if il % int(c) == 0:
            cc += 1

    print cc
