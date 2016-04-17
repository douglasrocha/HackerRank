import sys

lines = sys.stdin.readlines()
f_line = lines.pop(0)

for line in lines:
    lline = list(line.replace("\n", "").replace("\r", ""))
    curr = line[0]
    count = 0

    for i in range(1, len(lline)):
        if lline[i] == curr:
            lline[i] = ""
            count = count + 1
        else:
            curr = lline[i]

    print count
