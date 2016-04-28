import sys

lines = sys.stdin.readlines()
fl = lines.pop(0)

for line in lines:
    li = int(line)

    if li <= 1:
        print -1
        continue
    elif (li % 3 == 0):
        s = ""
        for x in range(li):
            s += "5"
        print str(s)
        continue
    else:
        s = ""
        c = li
        if li == 3:
            print "555"
        elif li == 5:
            print "33333"
        else:
            cinc = ""
            trois = ""
            never = False

            while c > 0:
                c -= 5

                if c < 0:
                    never = True
                    break

                trois += "33333"
                if c % 3 == 0:
                    for x in range(c):
                        cinc += "5"
                    break

            if never:
                print -1
            else:
                print cinc + trois
