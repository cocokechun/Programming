n = 12
l = [0] * (n+1)


for i in xrange(1, n+1):
    for j in xrange(1, n+1):
        if (i + j < n):
            k = n - i - j
            s = min(i, j, k)
            l = max(i, j, k)
            m = n - s - l 
            if (s + m > l):
                print s,m,l



