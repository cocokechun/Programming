import sys

num = int(raw_input())
i = 0


def process(s):
    s = s.rstrip('\n')
    length = len(s)
    if length >= 5:
        last_word = s[length-5: length]
        first_word = s[0:5]
    else:
        print "OMG>.< I don't know!"
        return
    if last_word == "lala.":
        if first_word != "miao.":
            print "Freda's"
        else:
            print "OMG>.< I don't know!"
        return
    if first_word == "miao.":
        print "Rainbow's"
        return 
    else:
        print "OMG>.< I don't know!"
        return
              
while (i < num):
    s = sys.stdin.readline()
    process(s)
    i += 1
