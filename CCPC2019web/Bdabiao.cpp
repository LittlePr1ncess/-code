#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
#define MN 1000010
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
#define LL long long
LL pp[MN],id1[MN],id2[MN],flag[MN],ncnt,m;
LL g[MN],sum[MN],a[MN],T,n,mod,tt;
int ID(LL x)
{
    return x<= T?id1[x]:id2[n/x];
}
LL calc(LL x)
{return x*(x+1)/2-1;}\
LL f(LL x)
{return x;}
void init()
{
    T = sqrt(n+0.5);
    so(i,2,T,1)
    {
        if(!flag[i]) pp[++ncnt] = i,sum[ncnt] = sum[ncnt-1] + i;
        for(int j=1;j<=ncnt && i*pp[j]<=T;j++)
        {
            flag[i*pp[j]]= 1;
            if(i%pp[j]==0) break;
        }
    }
    for(LL l = 1;l<=n;l=n/(n/l)+1)
    {
        a[++m] = n/l;
        if(a[m]<=T) id1[a[m]] = m;else id2[n/a[m]] = m;
        g[m] = calc(a[m]);
    }
    so(i,1,ncnt,1)
     for(int j = 1;j<=m&&(LL)pp[i]*pp[i]<=a[j];j++)
     g[j] = g[j] - (LL)pp[i]*(g[ID(a[j]/pp[i])]-sum[i-1]);
}
LL work(LL x)
{
    if(x<=1) return x;
    return n = x,init(),g[ID(n)];
}
int main()
{
    cin>>tt;
    while(tt--)
    {
        //cin>>n;cout<<work(n)<<endl;continue;
        memset(pp,0,sizeof(pp));
        memset(id1,0,sizeof(id1));
        memset(id2,0,sizeof(id2));
        memset(flag,0,sizeof(flag));
        memset(sum,0,sizeof(sum));
        memset(a,0,sizeof(a));
        memset(g,0,sizeof(g));
        ncnt = m = T = 0;
        cin>>n>>mod;
        if(n==1) {cout<<0<<endl;continue;}
        LL tmp; 
        //cout<<tmp<<endl;
        if((n+4)%2==0) tmp =((n+4)/2)%mod,tmp = (tmp*((n-1)%mod))%mod;
        else tmp = ((n-1)/2)%mod,tmp = (tmp *((n+4) % mod))%mod;
        //cout<<work(n+1)<<endl;
        tmp = tmp+(work(n+1)-2)%mod;
        //cout<<tmp<<endl;
        tmp%=mod;
        cout<<tmp<<endl;
    }
    //cin>>n;
}