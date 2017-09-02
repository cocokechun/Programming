import sys

inputs = sys.stdin.readline().split()
n = int(inputs[0])
l = [0] * n

inputs = sys.stdin.readline().split()
for i in xrange(n):
    l[i] = int(inputs[i])
l.sort()

d = dict()

maxPos = 30
for i in xrange(maxPos):
    d[i] = set()

def binSave(a):
    oldA = a
    i = 0
    while (a > 0):
        if (a % 2 == 0):
            d[i].add(oldA)
        i += 1
        a /= 2

for i in xrange(n):
    binSave(l[i])

def isValid(i, divisor):
    if (divisor >= n):
        return False
    for j in xrange(i):
        if (len(d[j]) == 0):
            return False
    return True
 
def remove(target, i):
    for k in xrange(i+1):
        d[k].discard(target)
    
def solve():
    result = 0
    divisor = 0
    for i in xrange(maxPos):
        if isValid(i, divisor):
            result = divisor
            for k in xrange(divisor,n):
                if l[k] >= 2**i and l[k] < 2**(i+1):
                    remove(l[k],i)
                    divisor += 1
                    continue
                break
        else:
            print (n-result)
            for k in xrange(result, n):
                print l[k],
            return
            
solve()
        

