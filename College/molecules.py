import sys

inputs = sys.stdin.readline().split()
a = int(inputs[0])
b = int(inputs[1])
c = int(inputs[2])

x = (b - c + a) / 2.0
y = (c - a + b) / 2.0
z = (a - b + c) / 2.0
if (x >= 0 and y >= 0 and z >= 0 and int(x) == x and int(y) == y and int(z) == z):
    print int(x), int(y), int(z)
else:
    print "Impossible"
