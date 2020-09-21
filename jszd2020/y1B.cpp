#include<bits/stdc++.h>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
#define MN 300005
#define LL long long
LL n,m,sum[3][MN],a[MN],b[MN],ans,con,l,r,c;
int main()
{
    cin>>n>>m;
    so(i,1,n,1) cin>>b[i],sum[1][i]=sum[1][i-1]+b[i];
    so(i,1,n,1) cin>>a[i],sum[2][i]=sum[2][i-1]+a[i];
    so(i,1,n,1) ans+=max(a[i],b[i]),sum[0][i]=ans;
    so(i,1,m,1) 
    {
        cin>>con>>l>>r>>c;
        if(sum[con][r]- sum[con][l-1]+ c>sum[0][r]- sum[0][l-1]) ans+=sum[con][r]- sum[con][l-1]+ c-(sum[0][r]- sum[0][l-1]);
    }
    cout<<ans;
   // cin>>ans;
}