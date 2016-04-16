import sys
line = sys.stdin.readline()

ampm = line[len(line) - 2:]
hours = line[:len(line) - 2]

vhours = hours.split(":")

if ampm == "PM" and int(vhours[0]) < 12:
    vhours[0] = str(int(vhours[0]) + 12)
elif ampm == "AM" and int(vhours[0]) == 12:
    vhours[0] = "00"

print ":".join(vhours)
