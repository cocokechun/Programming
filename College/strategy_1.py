import sys
import string

# read words from a file
words = set()
n = 0
letters = string.ascii_lowercase
while (True):
    line = sys.stdin.readline()
    if line == "":
        break
    word = line.split()[0]
    words.add(word)
    n = len(word)

# data structures\
# LL holds related letters 
# Two letters are related if they have appeared at the same position
# in the string before
LL = dict()

# If we find LP[c][i] for some letter c and some position i, then we have seen
# c appears at position i and we can easily decode c when it appears again at
# position i 
LP = dict()

# PP holds related positions
# Two positions are related if a letter has appeared at both positions before 
PP = dict()

# P_history[i] contains all letters that have apepared on position i for all
# i < n
P_his = dict()

# L_history[c] contains all positions that c has appearned before for all 
# lowercase letter c
L_his = dict()

def init():
    # init LL
    for c in letters:
        LL[c] = dict()

    # init LP
    for c in letters:
        LP[c] = dict()

    # init PP
    for i in xrange(n):
        PP[i] = dict()
    
    # init P_his
    for i in xrange(n):
        P_his[i] = set()
    
    # init L_his
    for c in letters:
        L_his[c] = set()

'''    
print LL 
print LP
print PP
print P_his
print L_his
'''

# Determines if we can decode letter c at position i according to the maps we 
# have
def can_decode_letter(c, i):
    for c2 in LL[c]:
        for j in PP[i]:
            if j in LP[c2]:
                return True
    return False

def can_decode_string(s):
    for i in xrange(n):
        c = s[i]
        if (not can_decode_letter(c, i)):
            return False
    return True

def add_info(s):
    for i in xrange(n):
        c = s[i]
        LP[c][i] = s

        P_his[i].add(c)
        for c2 in P_his[i]:
            LL[c][c2] = i
            LL[c2][c] = i
        L_his[c].add(i)
        for j in L_his[c]:
            PP[j][i] = c
            PP[i][i] = c

def solve():
    init()
    counter = 0
    for word in words:
        print word,
        counter += 1
        if can_decode_string(word):
            print 
            print counter
            print
            counter = 0 
            init()
        else:
            add_info(word)

solve()
