#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
#define MN 1005
LL m,n,q,a[MN],v[MN],ans,tmp,dp[MN][100],l,r,x;
int main()
{
    cin>>n>>m>>q;
    LL p = pow(2,32);
    //cout<<p<<"##";
    so(i,1,n,1) cin>>a[i]>>v[i];
    so(rwz,1,q,1)
    {
        memset(dp,-1,sizeof(dp));
        tmp = 0;
        cin>>l>>r>>x;l++,r++;
        dp[l-1][0] = 0;
        so(i,l,r,1)
        {
            //so(j,dp[i][0] = dp[i-1][0];
            so(j,0,m-1,1)
            {
                dp[i][j] = dp[i-1][j];
                if(dp[i-1][j^a[i]]==-1) continue;
                dp[i][j] = max(dp[i][j],dp[i-1][j^a[i]]+v[i]);
                dp[i][j] %= p;
            }
        }
        so(i,0,m-1,1)
        {
            //cout<<dp[r][i]<<" ";
            tmp += (dp[r][i]*(x^i) +p);
            tmp %= p;
            
        }
        tmp += p;tmp %= p;
        //cout<<endl;
        //cout<<tmp<<endl;
        
        ans += (rwz^tmp) %p;
        ans %= p;
    }
    cout<<ans;
    //cin>>n;
}