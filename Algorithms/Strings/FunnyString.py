import sys
from math import fabs

lines = sys.stdin.readlines()
first_line = lines.pop(0)

for line in lines:
    is_funny = True
    f_line = list(line.replace("\n","").replace("\r",""))
    r_line = list(line[::-1].replace("\n","").replace("\r",""))

    while len(f_line) > 2:
        f = f_line.pop(0)
        r = r_line.pop(0)
        f0 = ord(f_line[0])
        r0 = ord(r_line[0])

        if fabs(ord(f) - f0) != fabs(ord(r) - r0):
            is_funny = False
            break

    if is_funny:
        print "Funny"
    else:
        print "Not Funny"
