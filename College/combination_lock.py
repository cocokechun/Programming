import sys


def solve(): 
    inputs = sys.stdin.readline().split()
    n = int(inputs[0])
    if (n == 0):
        return -1
    a = int(inputs[1])
    b = int(inputs[2])
    c = int(inputs[3])
    
    result = 3 * n + n - 1

    if (b > a):
        result += (b - a)
    else:
        result += (n - abs(b-a))

    if (c < b):
        result += (b - c)
    else:
        result += (n - abs(c-b))
    print result

while (solve() != -1):
    continue
