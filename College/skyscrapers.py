import sys
from bisect import *

inputs = sys.stdin.readline().split()
t = int(inputs[0])

def neighbors(m, upper):
    if (m == 0):
        return (-1, 1)
    elif (m == upper - 1):
        return (m-1, -1)
    else:
        return (m-1, m+1)

def find_gt(a, x):
    'Find leftmost value greater than x'
    i = bisect_right(a, x)
    if i != len(a):
        return a[i]
    return None

# find the rightmost value greater than x
def find(a, x, so_far, n):
    i = so_far
    res = i
    while (i < n):
        if (a[i] > x):
            res = i
        else:
            return res
        i += 1
    return None

for test in xrange(t):
    inputs = sys.stdin.readline().split()
    n = int(inputs[0])
    k = int(inputs[1])
    seen = set()

    hs = sys.stdin.readline().split()
    ds = sys.stdin.readline().split()
    di = [0] * k

    hi = [(int(hs[i]), i) for i in xrange(n)]

    hi.sort()
    i = 0
    result = 0
    for j in xrange(k):
        d = int(ds[j])
        tmp = find_gt(hi, (d,10**6))
        #print "tmp is " , tmp
        if (tmp == None):
            di[j] = 0
        elif (tmp == hi[0]):
            di[j] = 1
        else :
            while (hi[i] < tmp):
                #print "i is ",i
                n1 = neighbors(hi[i][1], n)[0]
                n2 = neighbors(hi[i][1], n)[1]
                #print "n1 is ", n1, " n2 is ", n2
                seen.add(hi[i][1])
                if (n1 != -1 and n2 != -1):
                    if (n1 in seen and n2 in seen):
                        result -= 1
                    if (n1 not in seen and n2 not in seen):
                        result += 1
                        #seen.add(n1)
                        #seen.add(n2)
                if (n2 == -1):
                    if (n1 not in seen):
                        result += 1
                        #seen.add(n1)
                    else:
                        result -= 1
                if (n1 == -1):
                    if (n2 not in seen):
                        result += 1
                        #seen.add(n2)
                    else:
                        result -= 1
                i += 1
                #print "result is ", result
            di[j] = result
    
    for y in xrange(k):
        print di[y],
    print
