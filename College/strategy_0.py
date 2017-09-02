import sys

words = set()
while (True):
    line = sys.stdin.readline()
    if line == "":
        break
    words.add(line.split()[0])

def solve():
    seen = dict()
    counter = 0
    for word in words:
        print word,
        counter += 1
        can_decode = True
        for c in word:
            if c not in seen:
                can_decode = False
        for c in word:
            if c not in seen:
                seen[c] = word
        if (can_decode): 
            print
            for c in word:
                print "decode ", c, " from ", seen[c]
            print counter
            print
            counter = 0
            seen = dict()

solve()
