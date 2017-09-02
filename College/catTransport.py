import sys

def printList(l):
    for i in l:
        print i,
    print

def solve():
    inputs = sys.stdin.readline().split()
    n = int(inputs[0])
    m = int(inputs[1])
    p = int(inputs[2])

    distances = sys.stdin.readline().split()

    distances = [int(i) for i in distances]

    S = [0,0] + [sum(distances[0:i+1]) for i in xrange(n-1)]

    A = [[0] * (m+1) for i in xrange(p+1)]
   
    cats = [0] * (m + 1)
    for i in xrange(1, m+1):
        hill_trip = sys.stdin.readline().split()
        hill_trip = [int(j) for j in hill_trip]
        hill = hill_trip[0]
        trip = hill_trip[1]
        cats[i] = (-1)*trip + S[hill]
    cats.sort(reverse=True)

    #printList(cats)

    # base case : only one feeder 
    for y in xrange(1, m+1):
        A[1][y] = sum(cats[1:y+1]) + min(0, cats[y]) * (-1) * y

    #printList(A[1])

    for x in xrange(2,p+1):
        for y in xrange(x+1,m+1):
            min_waiting = sys.maxint
            for z in xrange(1,y):
                need_to_wait = min(0, cats[y]) * (-1)
                wait = A[x-1][z] + need_to_wait * (y-z) + sum(cats[:y+1])
                if (wait < min_waiting):
                    min_waiting = wait
                    '''
                    if y == 6:
                        print "z is " + str(z)
                        print "need_to_wait is " + str(need_to_wait)
                        print "wait time is " + str(min_waiting)
                    '''
            A[x][y] = min_waiting
    
    print A[x][y]

  



solve()
