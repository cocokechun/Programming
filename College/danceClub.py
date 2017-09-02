import sys
import math

inputs = sys.stdin.readline().split()
x = inputs[0]
n = len(x)

total = 0
for i in xrange(n):
    if x[i] == '1':
        total += (2**i) * ((2**(n-1-i)) **2)

print total % (10**9+7)

