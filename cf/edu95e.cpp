#include<bits/stdc++.h>
using namespace std;
#define MN 200005
#define p 998244353
#define LL long long
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
LL n,m,a[MN],d[MN],sum[MN],b[MN],nob[MN],x1,x2,S;
LL ksm(LL a, LL b)
{
    LL ans = 1 ;
    for(;b;a*=a,a%=p,b>>=1)
    if(b&1) ans = ans * a %p;
    return ans;
}
LL inv(LL a)
{
    return ksm(a,p-2);
}
int main()
{
    //cout<<5*inv(2)%p;
    cin>>n>>m;
    so(i,1,n,1) cin>>d[i];
    sort(d+1,d+1+n);so(i,1,n,1) sum[i] = sum[i-1] + d[i] % p;
    so(i,1,m,1) cin>>a[i]>>b[i],nob[i] = lower_bound(d+1,d+1+n,b[i])-d-1;
    so(i,1,m,1)
    {

        LL x = n - nob[i];
        if(x<a[i]) {cout<<0<<endl;continue;}
        cout<<((((sum[n]-sum[nob[i]]+p)%p*(x-a[i]))%p*inv(x))%p+((sum[nob[i]]*(x+1-a[i]))%p*inv(x+1))%p)%p<<endl;
    }
    //cin>>n;
}    
    