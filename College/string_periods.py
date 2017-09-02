import sys
from bisect import *

inputs = sys.stdin.readline().split()
b = int(inputs[0])
d = int(inputs[1])

a = sys.stdin.readline().split()[0]
len_a = len(a)
c = sys.stdin.readline().split()[0]
len_c = len(c)

#print len_a
#print len_c
def find_g(a, key):
    i = bisect_right(a, key)
    if i == len(a):
        return -1
    return a[i]

def printD(myDic):
    for key in myDic.keys():
        print key
        print myDic[key]
    print
    
def solve():
    starts = dict()
    start_round = dict()
    rounds_so_far = 0
    i = 0

    for char in c:
        if char not in a:
            print 0
            return

    if (len_c == 1):
        print a.count(c) * b / d
        return 

    for j in xrange(len_a*b):
        if a[j%len_a] == c[i%len_c]:
            if ((i+1) % len_c == 0):
                rounds_so_far += 1
            if (i % len_c == 0):
                if (starts.get(j%len_a) == None):
                    starts[j%len_a] = j
                    start_round[j] = rounds_so_far
                else:
                    break
            i += 1
    else:
        print rounds_so_far / d
        return 
    
    cycle_start = starts[j%len_a]
    #print cycle_start 
    cycle_end = j
    cycle_char = cycle_end - cycle_start
    #print "cycle_end is " + str(cycle_end)
    rounds_one_cycle = rounds_so_far - start_round[cycle_start]
    cycles = (len_a*b - cycle_start) / cycle_char
    rounds_between = rounds_one_cycle * cycles
    #print "rounds_between is " + str(rounds_between)
    rounds_before = start_round[cycle_start] 
    #print "rounds_before is " + str(rounds_before)
    rounds_after = 0
   
    p = 0 
    for k in xrange(cycle_start+cycles*cycle_char, len_a*b):
        if a[k%len_a] == c[p%len_c]:
            if ((p+1) % len_c) == 0:
                rounds_after += 1
            p += 1
    #print "end" 
    #print rounds_after
    print (rounds_before+rounds_between+rounds_after) / d
         
solve()
