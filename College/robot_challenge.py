import sys

def dis(v, w):
    return ((v[0] - w[0]) ** 2 + (v[1] - w[1]) ** 2) ** 0.5

def solve(): 
    inputs = sys.stdin.readline().split()
    n = int(inputs[0])
    if (n == 0):
        return -1
    pen = [0] * n
    p = [0] * (n + 1)
    p[n] = (100, 100)
    l = [0] * (n + 1)

    for i in xrange(n):
        inputs = sys.stdin.readline().split()
        p[i] = (int(inputs[0]), int(inputs[1]))
        pen[i] = int(inputs[2])


    l[0] = dis((0,0), p[0]) + 1 
    for i in xrange(1,n+1):
        total_p = sum(pen[:i])
        min_so_far = total_p + 1 + dis((0,0), p[i])
        for j in xrange(0, i):
            total_p -= pen[j]
            tmp = l[j] + total_p + dis(p[j], p[i]) + 1  
            if (tmp < min_so_far):
                min_so_far = tmp
        l[i] = min_so_far

    s = "%0.3f" %l[-1]
    print s

while (solve() != -1):
    continue
