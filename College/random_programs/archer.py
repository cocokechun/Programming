import sys
s = sys.stdin.readline()
data = [int(word) for word in s.split(" ")]
a = data[0]
b = data[1]
c = data[2]
d = data[3]

smallR_win = a*1.0/b
Z_win = c*1.0/d

P = smallR_win / (1-(1-smallR_win)*(1-Z_win))
print P
