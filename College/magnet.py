import sys

inputs = sys.stdin.readline().split()
n = int(inputs[0])

pre_b = '2'
counter = 0
for i in xrange(n):
    inputs = sys.stdin.readline().split()
    s = inputs[0]
    a = s[0]
    b = s[1]
    if (i == 0 or a == pre_b):
        counter += 1
    pre_b = b

print counter


