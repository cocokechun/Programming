import sys

def solve():
    inputs = sys.stdin.readline().split()
    n = int(inputs[0])
    m = int(inputs[1])
    if (n == 0 and m == 0):
        return -1
    s = set()

    count = 0
    for i in xrange(n):
        inputs = sys.stdin.readline().split()
        for j in xrange(m):
            elem = int(inputs[j])
            if (elem == 0):
                s.add((i, j))
                count += 1
    if count == m*n:
        return 0

    result = 1

    for i in xrange(n):
        if (result > n-i):
            break
        for j in xrange(m):
            if (result > m-j):
                break
            if ((i,j) not in s):
                md = min(n-i, m-j)
                for e in s:
                    if (e[0] - i > result) and (e[1] - j > result):
                        d = max(e[0]-i, e[1]-j)
                        if (d < md):
                            md = d
                if (md > result):
                    result = md
    return result
while (True):
    r = solve()
    if (r == -1):
        break
    else:
        print r
