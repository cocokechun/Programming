# returns true if m and n contains the same number of each digit except 0
def digitOccurence(m,n):
    ml = list(m)
    ml = [x for x in ml if x != "0"]
    ml.sort()
    nl = list(n)
    nl = [x for x in nl if x != "0"]
    nl.sort()
    return ml == nl

def solve(m,n):
    c = 1
    while (c < 100000):
        if digitOccurence(str(c*m),str(c*n)):
            return c
        c += 1
    return -1

for i in xrange(1,11):
    for j in xrange(1,11):
        print i, j, solve(i,j)
    print
