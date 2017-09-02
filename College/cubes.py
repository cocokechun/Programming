import sys

def solve():
    k = int(sys.stdin.readline().split()[0])
    if (k % 2 == 1):
        print -1
        return
    mid = float(k-1)/2
    c1 = 'w'
    c2 = 'b'
    for layer in xrange(k):
        for row in xrange(k):
            l = []
            for col in xrange(k):
                which = int(max(abs(row-mid), abs(col-mid)) / 0.5) / 2
                if (which % 2):
                    sys.stdout.write(c1)
                else:
                    sys.stdout.write(c2)
            print
        print
        tmp = c1
        c1 = c2
        c2 = tmp
        print

solve()
