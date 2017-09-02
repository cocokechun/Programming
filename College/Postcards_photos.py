import sys

inputs = sys.stdin.readline().split()
s = inputs[0]

def solve():
    if s == "":
        print 0
    finish_cycle = False
    prev = ''
    times = 0
    for c in s:
        if (c != prev or counter == 5):
            times += 1
            counter = 1
            prev = c
            continue
        counter += 1
        prev = c
    print times
solve()
    

