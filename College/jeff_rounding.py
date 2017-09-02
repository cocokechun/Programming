import sys
from math import *

inputs = sys.stdin.readline().split()
n = int(inputs[0])
m = 2 * n

nums = sys.stdin.readline().split()
nums = [float(i) for i in nums]

a = [0] * m
b = [0] * m


for i in xrange(m):
    num = nums[i]
    a[i] = num - floor(num)
    b[i] = num - ceil(num)

pairs = [] 
for i in xrange(m):
    for j in xrange(i):
        pos = a[i]
        neg = b[j]
        pairs.append((pos + neg, i, j))


seen = set([])
t = 0
count = 0
for p in pairs:
    if p[1] not in seen and p[2] not in seen:
        t += p[0] 
        seen.add(p[1])
        seen.add(p[2])
        count += 1
        if (count == n):
            break

s = "%.3f" %t
print s
