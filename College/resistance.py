import sys

inputs = sys.stdin.readline().split()
a = int(inputs[0])
b = int(inputs[1])

if (b == 1):
    print a
    exit()

div = a / b
result = div
a = a - div * b

while (True):
    b = b - a
    result += 1
    if (b == 1):
        result += a/b
        break
    div = a / b
    result += div
    a = a - div * b

print result


