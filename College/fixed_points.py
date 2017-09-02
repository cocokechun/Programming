import sys

inputs = sys.stdin.readline().split()
n = int(inputs[0])

inputs = sys.stdin.readline().split()
l = [int(i) for i in inputs] 

fixed = 0
seen = set()
best_fix = False

def make_pair(i,j):
    if (i < j):
        return (i,j)
    else:
        return (j,i)

for i in xrange(n):
    if i == l[i]:
        fixed += 1
    else:
        t = make_pair(i, l[i])
        if (t in seen):
            best_fix = True
        seen.add(t)

if (fixed == n):
    print n
else:
    if best_fix:
        print (fixed + 2)
    else:
        print (fixed + 1)        
