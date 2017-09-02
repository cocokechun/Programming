from Queue import *
def printl(l):
    for i in l:
        s = "%2d" %(i)
        print s,
    print

def find(n):
    l = [i+1 for i in xrange(n)]
    #print l
    templ = l
    count = 0
    while (count == 0 or templ != l):
        templ = f(templ)
        count += 1
    print count


def f(l):
    q = Queue()
    newl = []
    for i in l:
        q.put(i)
    j = 0
    while (not q.empty()):
        if j%2 == 0:
            temp = q.get()
            q.put(temp)
        else:
            temp = q.get()
            newl.append(temp)
        j += 1
    printl(newl)
    return newl



    
