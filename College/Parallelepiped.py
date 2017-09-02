import sys

inputs = sys.stdin.readline().split()
a = int(inputs[0])
b = int(inputs[1])
c = int(inputs[2])

r_square = 2*a + 2*b + 2*c + (a*b)/c + (b*c)/a + (a*c)/b
print 4 * int(r_square ** 0.5)
