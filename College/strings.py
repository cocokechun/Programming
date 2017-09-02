import sys
from bisect import *

inputs = sys.stdin.readline().split()
b = int(inputs[0])
d = int(inputs[1])

a = sys.stdin.readline().split()[0]
len_a = len(a)
c = sys.stdin.readline().split()[0]
len_c = len(c)
s = a * b
k = 0
times = 0

for i in xrange(len_a * b):
    if s[i] == c[k]:
        k += 1
        if (k == len_c):
            times += 1
            k = 0
#print "len_a " + str(len_a)
#print "len_c " + str(len_c)
#print times
print times / d 

  

        

