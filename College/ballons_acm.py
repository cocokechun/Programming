import sys

def solve():
    inputs = sys.stdin.readline().split()
    n = int(inputs[0])
    a = int(inputs[1])
    b = int(inputs[2])

    if (n,a,b) == (0, 0, 0):
        return -1
    diffs = [0] * n
    data =[0] * n

    for i in xrange(n):
        inputs = sys.stdin.readline().split()
        l = int(inputs[0])
        m = int(inputs[1])
        n = int(inputs[2])
        data[i] = (l,m,n)
        diffs[i] = (i, abs(m-n))

    diffs = sorted(diffs, key=lambda diff : diff[1], reverse = True)
    r = 0
    for diff in diffs:
        i = diff[0]
        datum = data[i]
        l = datum[0]
        m = datum[1]
        n = datum[2]
        if (m > n):
            if (b >= l):
                b -= l
                r += l*n
            else:
                r += b*n
                r += (l-b)*m
                a = a - (l-b)
                b = 0
        elif (m < n):
            if (a >= l):
                a -= l
                r += l*m
            else:
                r += a*m
                r += (l-a)*n
                b = b - (l-a)
                a = 0
        else:
            r += l*m
    return r

while (True):
    result = solve()
    if (result == -1):
        break
    else:
        print result
 
