#include<bits/stdc++.h>
using namespace std;
#define LL long long 
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
#define INF  800000000
#define MN 505
#define MM 110000
int n,m,t[MN],dp[MM][MN],a[MM],tt[MN],emm,tmax,sum[MM],tim[MM],spc=INF,tmp;
int main()
{
	//freopen("emm.txt","w",stdout);
	cin>>n>>m;tmax=-1;
	for(int i=1;i<=n;i++) cin>>tt[i],t[i]=tt[i];
	sort(tt+1,tt+n+1);sort(t+1,t+1+n);
	//so(i,1,n,1) cout<<tt[i]<<" ";
	so(i,1,n,1) 
	{
		if(tt[i]-tt[i-1] > 2*m) tmp+=(tt[i]-tt[i-1]-2*m);
		t[i]-=tmp;
	}
	so(i,1,n,1) tmax=max(tmax,t[i]);
	
	so(i,1,n,1) cout<<t[i]<<" ";
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
	int Min = INF;
	for(int i=0;i<=n;i++)//for(int j=tmax;j<=tmax+m;j++)
	Min=min(Min,dp[tmax][i]);
	cout<<min(Min,spc);
	//cout<<Min;
	return 0;
}
