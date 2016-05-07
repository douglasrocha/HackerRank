import sys
from datetime import date

lines = sys.stdin.readlines()

act = map(int, lines[0].split())
exp = map(int, lines[1].split())

dact = date(act[2], act[1], act[0])
dexp = date(exp[2], exp[1], exp[0])

if dact <= dexp:
    print 0
elif act[1] == exp[1] and act[2] == exp[2]:
    print abs((dexp - dact).days * 15)
elif act[2] == exp[2]:
    print abs(((dexp.year - dact.year) * 12 + (dexp.month - dact.month)) * 500)
else:
    print 10000
    
