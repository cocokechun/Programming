import sys

inputs = sys.stdin.readline().split()
s = inputs[0]

def solve():
    if s == "":
        print 0
    finish_cycle = False
    prev = ''
    times = 0
    counter = 0
    for c in s:
        print c,
        print "count ", counter
        if (c != prev):
            times += 1
            counter = 1
            prev = c
            print times
            continue
        elif (finish_cycle == True):
            times += 1
            counter = 1
            print "because cycle"
            print times
            prev = c
            finish_cycle = False
            continue
        counter += 1
        if (counter == 5):
            finish_cycle = True
            counter = 0
        prev = c
    print times
solve()
