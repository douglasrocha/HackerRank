# Enter your code here. Read input from STDIN. Print output to STDOUT
import sys

lines = sys.stdin.readlines()

un = ["adas", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]
dc = ["twenty", "thirty"]

str_hm = ""
hour = int(lines[0])
minutes = int(lines[1])

if minutes == 0:
    str_hm = un[hour] + " o' clock"
elif minutes == 30:
    str_hm = "half past " + un[hour]
elif minutes == 15:
    str_hm = "quarter past " + un[hour]
elif minutes == 45:
    str_hm = "quarter to " + un[hour + 1]

    if hour + 1 == 13:
        str_hm = "quarter to one"

elif minutes < 30:
    f = ""
    past = " past " + un[hour]

    woot = ""
    if minutes != 1:
        woot = "s"

    if minutes >= 20 and minutes < 30:
        f += "twenty "
        minutes -= 20
    elif minutes >= 30:
        f += "thirty "
        minutes -= 30

    if minutes > 0:
        f += un[minutes]

    str_hm = f + " minute" + woot + past
else:
    minutes = 60 - minutes
    f = ""
    tos = " to " + un[hour + 1]

    if hour + 1 == 13:
        tos = " to " + un[1]

    woot = ""
    if minutes != 1:
        woot = "s"

    if minutes >= 20 and minutes < 30:
        f += "twenty "
        minutes -= 20
    elif minutes > 30:
        f += "thirty "
        minutes -= 30

    if minutes > 0:
        f += un[minutes]

    str_hm = f + " minute" + woot + tos

print str_hm
