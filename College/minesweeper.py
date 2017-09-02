import sys

def is_valid(row, col, rows, cols):
    return (row >= 0 and row < rows and col >=0 and col < cols)

def solve():
    inputs = sys.stdin.readline().split()
    r = int(inputs[0])
    c = int(inputs[1])
    if r == 0 and c == 0:
        return -1

    l = [[0] * c for i in xrange(r)]
    res = [[0] * c for i in xrange(r)]

    for i in xrange(r):
        inputs = sys.stdin.readline().split()
        s = inputs[0]
        for j in xrange(c):
            l[i][j] = s[j]
            if l[i][j] == '*':
                res[i][j] = '*'

    for i in xrange(r):
        for j in xrange(c):
            if (l[i][j] == '*'):
                for drow in xrange(-1, 2):
                    for dcol in xrange(-1, 2):
                        if not (drow == 0 and dcol == 0):
                            trow = i + drow
                            tcol = j + dcol
                            if is_valid(trow, tcol,r,c):
                                if (res[trow][tcol] != '*'):
                                    res[trow][tcol] += 1

    for i in xrange(r):
        result = [str(ele) for ele in res[i]]
        print ''.join(result)


while (True):
    if (solve() == -1):
        break
