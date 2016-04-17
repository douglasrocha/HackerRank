import sys

line = sys.stdin.readlines()[0].lower()
if 0 in map(lambda x: x in line, list("abcdefghijklmnopqrstuvwxyz")):
    print "not pangram"
else:
    print "pangram"
