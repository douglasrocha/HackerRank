import sys

lines = sys.stdin.readlines()
nl = lines.pop(0)

for line in lines:
    il = int(line)
    height = 1

    for x in range(il):
        if x % 2 == 0:
            height *= 2
        else:
            height += 1

    print height
    height = 1
