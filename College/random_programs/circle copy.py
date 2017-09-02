def printlist(n, l):
    acc = 0
    typeA = False
    for ele in l:
        if ele != 0:
            acc += ele
            if acc == n:
                typeA = True
            print ele,
    if typeA == True:
        print "*",
    print

def find(n, acc, acc_list):
    if (acc > 2*n):
        return 0
    if (acc == 2*n):
        printlist(n, acc_list)
        return 1
    # try step length of 1 or 2
    for step in xrange(1,3):
        if step == 1:
            # if a move is repeated, stop trying this move
            if acc >= n:
                if step == acc_list[acc%n]:
                    result1 = 0
                    continue
            result1 = find(n,acc+1,acc_list+[1])
        else:
            # if a move is repeated, stop trying this move
            if acc >= n:
                if step == acc_list[acc%n]:
                    result2 = 0
                    continue
            result2 = find(n,acc+2,acc_list+[2,0])
    return result1+result2

def solve(n):
    result = find(n, 0, [])
    print result

