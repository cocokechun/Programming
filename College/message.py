import sys

inputs = sys.stdin.readline().split()
s = inputs[0]
n = len(s)

inputs = sys.stdin.readline().split()
t = inputs[0]
m = len(t)

s = "0"*m + s + "0"*m
n += 2*m

def helper(a,b):
    a_len = len(a)
    temp = 0
    for i in xrange(a_len):
        if (a[i] != b[i]):
            temp += 1
    return temp

result = m
for i in xrange(n):
    if (i >= m):
        k = helper(t, s[i-m:i])
        if (k < result):
            result = k
print result
