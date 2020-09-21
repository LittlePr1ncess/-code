#include<bits/stdc++.h>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
#define MN 300005
#define LL long long
LL n,m,sum[3][MN],a[MN],b[MN],ans,con,l,r,c,cnt,dp[MN],tot,L ,summ ,ww;
struct lll{
    int l,r,w,con;
}e[MN],aa[MN];
bool cmp(lll a,lll b)
{
    return a.r<b.r;
}
int main()
{
    cin>>n>>m;
    so(i,1,n,1) cin>>b[i],sum[1][i]=sum[1][i-1]+b[i];
    so(i,1,n,1) cin>>a[i],sum[2][i]=sum[2][i-1]+a[i];
    so(i,1,n,1) ans+=max(a[i],b[i]),sum[0][i]=ans;
    so(i,1,m,1) 
    {
        cin>>con>>l>>r>>c;
        if(sum[con][r]- sum[con][l-1]+ c>sum[0][r]- sum[0][l-1])
        e[++tot].l=l,e[tot].r=r+1,e[tot].w=sum[con][r]- sum[con][l-1]+ c-(sum[0][r]- sum[0][l-1]),e[tot].con=con;
    }
    so(i,1,tot,1)
    {
        int f = 0;
        so(j,1,cnt,1)
        {
            if(e[i].con!=aa[j].con) continue;
            if(e[i].l<=aa[j].r&&e[i].l>=aa[j].l)
            {aa[j].r=max(e[i].r,aa[j].r);aa[j].w+=e[i].w;f=1;break;}
            if(e[i].r<=aa[j].r&&e[i].r>=aa[j].l)
            {aa[j].l=min(e[i].l,aa[j].l);aa[j].w+=e[i].w;f=1;break;}
        }
        if(!f) aa[++cnt].l = e[i].l,aa[cnt].r=e[i].r,aa[cnt].con = e[i].con,aa[cnt].w = e[i].w;
    }
    sort(aa+1,aa+1+cnt,cmp);
    int k = 1;
    so(i,1,n+1,1)
    {
        dp[i]= dp[i-1];
        while(i==aa[k].r&&k<=cnt)
        {
            dp[i] = max(dp[i],dp[aa[k].l]+aa[k].w);
            k++;
        }
    }
    cout<<ans+dp[n+1];
    //cin>>ans;
}
/*
5 2
1 1 1 1 1
1 1 1 1 1
1 1 3 4 
1 3 5 5
*/