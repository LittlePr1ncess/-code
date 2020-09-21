T = int(input())
for emm in range (0,T):
    n = int(input())
    a = input().split()
    #a = [int(i) for i in aa]
    a.sort()
    f = 0
    s = ''
    zero = 0
    for i in a:
        if(i=='0'):
            zero += 1 
            continue
        if(i!='0' and f!=1):
            key = int(i)
            f = 1
            continue
        s += i
    key = key*int(s)
    sam = ''
    for i in range (0,zero):
        sam += '0'
    print(key,end="")
    print(sam)