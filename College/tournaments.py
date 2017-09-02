import sys
import math

inputs = sys.stdin.readline().split()
n = int(inputs[0])
results = []

def isInt(x):
    return int(x) == x

def isOddInt(x):
    return int(x) == x and x % 2 == 1

def plugIn(y):
    a = 1.0
    b = (2**(y+1) -3) 
    c = -2*n
    if y == 54:
        print "la"
        print (-b*1.0 + math.sqrt(b**2 - 4*a*c)) / 2
    return (-b + (b**2 - 4.0*a*c)**0.5) / 2


max_y = int(round(math.log(n+1, 2)))
if 2**max_y == n+1:
    results.append(2**max_y)

for y in xrange(max_y+1):
    x = int(round(plugIn(y)))
    if (y == 54):
        print "y = 54"
        print x
    if x%2 == 1 and (x*(x-1)/2  + (2**y-1) * x == n):
        results.append(x*(2**y))

if (results == []):
    print -1
else:
    results.sort()
    for result in results:
        print int(result)

