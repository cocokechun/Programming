import sys

inputs = sys.stdin.readline().split()
n = int(inputs[0])
rows = [0] * n
cols = [0] * n
l = [[0] * n for i in xrange(n)]

for i in xrange(n):
    line = sys.stdin.readline().split()
    for j in xrange(n):
        k = int(line[j])
        rows[i] += k
        cols[j] += k
        l[i][j] = k 

result = 0
for i in xrange(n):
    for j in xrange(n):
        if (cols[j] > rows[i]):
            result += 1
print result
             
    
     
