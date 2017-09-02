import sys
from heapq import *

months = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
def convert(m, d):
    r = 0
    if (m == 1):
        return d
    for i in xrange(m-1):
        r += months[i]
    return r+d
    
inputs = sys.stdin.readline()
n = int(inputs[0])
l = [0] * n
for i in xrange(n):
    inputs = sys.stdin.readline().split()
    k = convert(int(inputs[0]), int(inputs[1]))
    p = int(inputs[2])
    d = int(inputs[3])
    l[i] = (k-d, k-1,p)

l = sorted(l, key= lambda e : e[0])
h = []
m = 0
accu = 0
for elem in l:
    if (len(h) == 0):
        heappush(h, (elem[1], elem))
        accu += elem[2]
        if (accu > m):
            m = accu
    else:
        while (len(h) > 0):
            temp = heappop(h)
            if temp[0] < elem[1]:
                accu -= temp[1][2]
                if (accu > m):
                    m = accu
            else:
                heappush(h, temp)
                heappush(h, (elem[1], elem))
                accu += elem[2]
                if (accu > m):
                    m = accu
                break
        if (len(h) == 0):
            assert(accu == 0)
            accu = elem[2]
print m

