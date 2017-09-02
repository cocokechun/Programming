import sys

inputs = sys.stdin.readline().split()
n = int(inputs[0])
s = set()
for i in xrange(n):
    s.add(i+1)
inputs = sys.stdin.readline().split()
for i in xrange(n):
    s.discard(int(inputs[i]))
print len(s)

