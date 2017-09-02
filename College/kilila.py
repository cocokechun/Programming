import sys

def printList(l):
    for i in l:
        print str(i),
    print

def binary_search(seq, t):
    mini = 0
    maxi = len(seq) - 1
    while 1:
        if maxi < mini:
            return -1
        m = (mini + maxi) / 2
        if seq[m][1] < t:
            mini = m + 1
        elif seq[m][0] > t:
            maxi = m - 1
        else:
            return m         

def linear_search(seq, t):
    length = len(seq)
    for i in xrange(length):
        if t >= seq[i][0] and t <= seq[i][1]:
            return i 

class Envelope:
    def __init__(self):
        self.intervals = []
        self.lines = []

    def add(self, (m2,b2)):
        length = len(self.lines)
        if (length == 0):
            self.lines.append((m2,b2))
            self.intervals.append([-sys.maxint-1, sys.maxint])
        elif (length == 1):
            (m1,b1) = self.lines[-1]
            self.lines.append((m2,b2))
            x = float(b2-b1) / (m1-m2)
            self.intervals[-1] = [0,x]
            self.intervals.append([x, sys.maxint])
        else:
            while (len(self.lines) >= 2):
                (m0,b0) = self.lines[-2]
                (m1,b1) = self.lines[-1]
                m2_m0_intersect = float(b2-b0)/(m0-m2)
                m1_m0_intersect = float(b1-b0)/(m0-m1)
                m2_m1_intersect = float(b2-b1)/(m1-m2)
                if (m2_m0_intersect < m1_m0_intersect):
                    self.lines.pop()
                    self.intervals.pop()
                else:
                    self.intervals[-1][1] = m2_m1_intersect
                    self.lines.append((m2,b2))
                    self.intervals.append([m2_m1_intersect,sys.maxint])
                    break
            else:
                    self.intervals[-1][1] = m2_m1_intersect
                    self.lines.append((m2,b2))
                    self.intervals.append([m2_m1_intersect,sys.maxint])



    def query(self, x):
        index = linear_search(self.intervals, x)
        (m,b) = self.lines[index]
        return m * x + b


def solve():
    inputs = sys.stdin.readline().split()
    n = int(inputs[0])

    A = sys.stdin.readline().split()
    A = [0] + [int(i) for i in A]
    B = sys.stdin.readline().split()
    B = [0] + [int(j) for j in B]
    C = [0] * (n + 1)
  
    E = Envelope()
    E.add((B[1], C[1]))  
    for i in xrange(2, n+1):
        C[i] = E.query(A[i])
        if (i < n):
            E.add((B[i], C[i]))

    print C[n]
    '''
    for i in xrange(2, n+1):
        C[i] = sys.maxint
        for j in xrange(1,i):
            C[i] = min(C[i], C[j] + B[j]*A[i])
        s = "C[%d] is %d" %(i, C[i])
        print s
    print C[n]
    '''
    '''
    C[1] = B[1]
    for i in xrange(2,n+1):
       C[i] = sys.maxint
       for j in xrange(1,i):
        C[i] = min(C[i], B[j]*A[i]-B[j]+B[i]+C[j])
    print C[n]
    '''
    
    '''
    C[1] = B[1]
    for i in xrange(2,n+1):
        C[i] = B[1] * A[i] + B[i]
        tmp_j = 0
        for j in xrange(2,i):
            tmp_cost = C[j] + B[j] * (A[i] - 1) + B[i]
            if (tmp_cost < C[i]):
                C[i] = tmp_cost
                tmp_j = j
        s = "C[%d] is %d tmp_j is %d " %(i, C[i], tmp_j)
        print s
    print C[i]
    '''

solve()
