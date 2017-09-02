import sys

def fastPow(a,b,c):
    result = 1
    while (b > 0):
        if (b%2 == 1):
            result = result * a % c
        a = a * a % c
        b = b/2
    return result 
'''
inputs = sys.stdin.readline().split()
n = int(inputs[0])
m = int(inputs[1])
k = int(inputs[2])

w = n - m
divisor = 10**9+9
p = 30


if k*w + (k-1) >= n:
    print m
else:
    no_double = n - k*w
    cycle = no_double/k
    exp = cycle + 1
    remainder = no_double%k
    multiple = pow(2, exp, divisor)
    result = ((multiple-2) * k) % divisor
    result = (result + remainder) % divisor
    result = (result + w*(k-1)) % divisor
    print result
'''



