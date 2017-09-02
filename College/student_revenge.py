import sys
inputs = sys.stdin.readline().split()

total = int(inputs[0])
passto = int(inputs[1])
obey = int(inputs[2])
ignore = passto - obey
l = range(total)

for i in xrange(total):
    line = sys.stdin.readline().split()
    entry = (int(line[0]), int(line[1]), i+1)
    l[i] = entry

def sortByGreyHair(a,b):
    if (a[0] > b[0]):
        return 1
    elif (a[0] == b[0]):
        if (a[1] > b[1]):
            return 1
        else:
            return -1
    else:
        return -1 

def sortByUnhappy(a,b):
    if (a[1] < b[1]):
        return -1
    elif (a[1] == b[1]):
        if (a[0] > b[0]):
            return 1
        else:
            return -1
    else:
        return 1

def solve(l):
    result_ignore = []
    result_obey = []
    s = set()

    if (ignore == 0):
        l.sort(cmp=sortByGreyHair, reverse=True)
        for i in xrange(obey):
            print l[i][2],
        return

    l.sort(cmp=sortByUnhappy)
    # pick orders she will obey
    subl = l[ignore:total]
    subl.sort(cmp=sortByGreyHair, reverse=True)
    least_happy_obey = sys.maxint

    for j in xrange(obey):
        last_entry_obey = subl.pop(0)
        if (last_entry_obey[1] < least_unhappy_obey):
            least_unhappy_obey = last_entry_obey[1]
        s.add(last_entry_obey)

    j = 0
    for entry in reversed(l):
        if entry[1] < least_unhappy_obey:



            

    for entry in s:
        print entry[2]    

solve(l)        
    



