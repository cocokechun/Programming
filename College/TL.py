import sys

inputs = sys.stdin.readline().split()
n = int(inputs[0])
m = int(inputs[1])

co = sys.stdin.readline().split()
co = [int(i) for i in co]
max_co = max(co)
min_co = min(co)

inc = sys.stdin.readline().split()
inc = [int(j) for j in inc]
min_inc = min(inc)

for i in xrange(max_co, min_inc):
    if i >= 2 * min_co:
        print i
        exit()
    
    
print -1 




