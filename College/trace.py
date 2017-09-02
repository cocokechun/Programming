import sys
import math

inputs = sys.stdin.readline().split()
n = int(inputs[0])

parity = 0
if n % 2 == 0:
    parity = 1
    
result = 0 
inputs = sys.stdin.readline().split()
l = [int(i) for i in inputs]
l.sort()

for i in xrange(n):
    if i == 0:
        if i % 2 == parity:
            result = result + l[i] ** 2
    elif i % 2 == parity:
        result = result + (l[i] ** 2 - l[i-1] ** 2)

result *= math.pi
print result
    


