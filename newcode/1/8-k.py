T=int(input())
for cs in range(1,T+1):
    ans = 0
    n=int(input())
    sum=[1]*(n+5)
    maxx=[1]*(n+5)
    minn=[1]*(n+5)
    wz=[1]*(n+5)

    aa = input().split()
    a = [int(i) for i in aa]
    bb = input().split()
    b = [int(i) for i in bb]
    sum[0] = a[0]
    for i in range(1,n):
        sum[i] = sum[i-1] + a[i]
    maxx[0] = sum[0]
    minn[0] = b[0]
    for i in range(1,n):
        maxx[i] = max(maxx[i-1],sum[i])
        #minn[i] = min(minn[i-1],int(b[i]))
        if(b[i]<minn[i-1]):
            minn[i] = b[i]
            wz[i] = i
        else :
            minn[i] = minn[i-1]
            wz[i] = wz[i-1]
    tot = b[0]
    R = n-1
    while(tot>0):        
        ans += maxx[R]*min(tot,minn[R]-(b[0]-tot))
        #print(ans)
        tot -= minn[R]-(b[0]-tot)
        #print(tot)
        R = wz[R]-1
    print('Case #'+str(cs)+':',b[0],ans)
    #print(sum)
    #print(maxx)
    


