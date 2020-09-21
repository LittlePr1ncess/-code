#include<bits/stdc++.h>
using namespace std;
int ans,n,h,l,r,a[2005],dp[2005][2005];
int main()
{
	cin>>n>>h>>l>>r;
	for(int i=1;i<=n;i++) cin>>a[i];
	//memset(dp,128,sizeof(dp));
	for(int i=1;i<=n;i++) for(int j=0;j<h;j++) dp[i][j]=-1;
	dp[1][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<h;j++)
		{
			if(dp[i][j]==-1) continue;
			int slp=(j+a[i])%h;
			dp[i+1][slp]=max(dp[i+1][slp],dp[i][j]+(slp>=l&&slp<=r));
			slp=(j+a[i]-1)%h;
			dp[i+1][slp]=max(dp[i+1][slp],dp[i][j]+(slp>=l&&slp<=r));
		}
	}
	for(int i=0;i<h;i++) ans=max(ans,dp[n+1][i]);
	/*for(int i=1;i<=n;i++)
	{
		for(int j=0;j<h;j++)
		cout<<dp[i][j]<<" ";cout<<endl;
	}*/
		cout<<ans;
} 
