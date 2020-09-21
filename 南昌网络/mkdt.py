import random
maxn=1000
maxm=500000
t=random.randint(1,10)
print(t)
for z in range(0,t):
    n=random.randint(1,maxn)
    m=random.randint(n,maxm+n)
    s=random.randint(1,n+1)
    k=random.randint(1,maxn)
    c=random.randint(1,10)
    print(n,m,s,k,c)

    for i in range(1,k+1):
        a=random.randint(1,n)
        print(a,end=' ')
    print()

    for i in range(2,n+1):
        a=i
        b=random.randint(1,a-1)
        w=random.randint(1,10)
        print(a,b,w)
        
    for i in range(1,m+2-n):
        a=random.randint(1,n)
        b=random.randint(1,n)
        w=random.randint(1,10)
        print(a,b,w)
                
