import sys

inputs = sys.stdin.readline().split()
n = int(inputs[0])

inputs = sys.stdin.readline().split()
l = [int(i) for i in inputs] 
l.sort()
print l[-1],
for i in xrange(1,n-1,1):
    print l[i],
print l[0]
