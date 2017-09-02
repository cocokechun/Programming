import sys
from Queue import *

inputs = sys.stdin.readline().split()
n = int(inputs[0])
ps = sys.stdin.readline().split()
ps = [int(i) for i in ps]
i = 0
tempQ = Queue(n)
for i in xrange(n):
    tempQ.put(ps[i])
total = n
left = n
delete = 0
result = 0
stored_pre = 0
in_order = 0

def printQ(q):
    size = q.qsize()
    for i in xrange(size):
        ele = q.get()
        print ele,
        q.put(ele)
    print


while (True):
    if (total == 1):
        print result
        break
    # start of a cycle
    if (left == total):
        pre = tempQ.get()
        stored_pre = pre
        left -= 1
        tempQ.put(pre)
    cur = tempQ.get()
    if (pre > cur):
        delete += 1
    else:
        if (stored_pre > cur):
            in_order = False
            stored_pre = cur
        tempQ.put(cur)
    left -= 1
    pre = cur
    # one cycle ends
    if (left == 0):
        if (delete == 0):
            print result 
            break
        result += 1
        total = total - delete
        left = total
        delete = 0
        if (in_order == True):
            print result
            break
