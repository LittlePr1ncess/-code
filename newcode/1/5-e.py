import math
ans=1
mod=1
vis=[0]*100005
p=[None]*100005
#f=open('a.txt','r')
n=int(input())
a=input().split()
#n=int(f.readline())
#a=f.readline().split()
def gcd(a,b):
    if(int(b)==0):
        return a
    else:
        return gcd(b,a%b)
def lcm(a,b):
    return a*b//gcd(a,b)
def work(i):
    nxt = 1
    nxt = int(p[i])
    #print(type(nxt))
    len = 1
    while(int(nxt) != int(i)):
        len+=1
        vis[int(nxt)]=1
        nxt=p[int(nxt)]
        #if(len<=20):
        #    print(i," ",nxt)
    #print(len)
    global ans
    ans=lcm(ans,len)
for i in range(0,n):
    #mod*=10
    p[i+1]=a[i]
    vis[i+1]=0
for i in range(1,n+1):
    #print(i," ",vis[i])
    if(vis[i]!=1):
        work(int(i))
mod = pow(10, n)
print(int(ans%mod))

    

