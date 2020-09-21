#include<bits/stdc++.h>
using namespace std;
#define MN 200005
#define LL long long
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
int n,T,a[MN],dp[MN][2];
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n;
        memset(dp,127,sizeof(dp));
        //cout<<dp[1][1];
        dp[0][0] = 0;
        so(i,1,n,1) cin>>a[i];
        so(i,1,n,1)
        {
            if(i-1>=0) dp[i][1]=min(dp[i-1][0]+a[i],dp[i][1]),dp[i][0] = min(dp[i][0],dp[i-1][1]);
            if(i-2>=0) dp[i][1]=min(dp[i][1], dp[i-2][0]+a[i]+a[i-1]),dp[i][0] = min(dp[i][0],dp[i-2][1]);
        }
        cout<<min(dp[n][0],dp[n][1])<<endl;
    }
    //cin>>n;
}