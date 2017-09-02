import sys
import math

inputs = sys.stdin.readline().split()
n = inputs[0]

num5 = 0
num0 = 0

digits = sys.stdin.readline().split()
for i in digits:
    if i == '5':
        num5 += 1
    if i == '0':
        num0 += 1

if num0 == 0:
    print -1
else:
    if (num5 < 9):
        print 0
    else:
        max_num5 = num5 / 9 * 9
        s = '5' * max_num5 + '0' * num0 
        print s
