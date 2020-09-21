#include<bits/stdc++.h>
using namespace std;
#define LL long long 
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
#define INF  800000000
#define MN 505
#define MM 11000
int n,m,t[MN],dp[MM][MN],a[MM],emm,tmax,sum[MM],tim[MM],spc=INF;
int main()
{
	cin>>n>>m;tmax=-1;
	for(int i=1;i<=n;i++) cin>>t[i],tmax=max(tmax,t[i]);
	sort(t+1,t+n+1);
	//so(i,1,n,1) cout<<t[i]<<" ";
	for(int i=1;i<=n;i++) a[t[i]]++;
	so(i,0,tmax+m,1) sum[i]=sum[i-1]+a[i];
	so(i,0,tmax+m,1) tim[i]=tim[i-1]+sum[i-1];
	//so(i,0,tmax,1) cout<<sum[i]<<" "<<tim[i]<<endl;
	//cout<<tim[11+m]-tim[11]-sum[11]*m;
	//so(i,1,emm,1) cout<<tmm[i]<<" ";
	so(i,0,tmax+m,1) so(j,0,n,1) dp[i][j]=INF;
	
	dp[0][0]=0;//so(i,0,n,1) {so(j,0,n,1) cout<<dp[i][j]<<" "; cout<<endl;}
	so(i,0,tmax,1) so(j,0,n,1)
	{
		dp[i+1][j+a[i+1]]=min(dp[i+1][j+a[i+1]],dp[i][j]+j);
		if(i+m<=tmax)
		dp[i+m][sum[i+m]-sum[i]]=min(dp[i+m][sum[i+m]-sum[i]],dp[i][j]+tim[i+m]-tim[i]-sum[i]*m);
		else spc=min(spc,dp[i][j]+tim[i+m]-tim[i]-sum[i]*m);
	}
	//so(i,0,tmax,1) {so(j,0,n,1) cout<<dp[i][j]<<" "; cout<<endl;}
	int Min = INF;
	for(int i=0;i<=n;i++)//for(int j=tmax;j<=tmax+m;j++)
	Min=min(Min,dp[tmax][i]);
	cout<<min(Min,spc);
	return 0;
}
