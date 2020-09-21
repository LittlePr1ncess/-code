import random
maxn=25
maxm=500
t=random.randint(1,5)
print(t)
for i in range(0,t):
    n=random.randint(1,maxn)
    print(n)
    for j in range(n):
        a=random.randint(1,maxm)
        print(a,end=' ')
    print()
