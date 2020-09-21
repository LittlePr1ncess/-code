#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<cmath>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
char x;
int a[1005],dp[1005][11][11],pre[1005][11][11][2],n,ans[1005];
int main()
{
	so(i,1,10,1) cin>>x,a[i]=x-'0';
	cin>>n;
	so(i,1,10,1)
	{
		if(a[i]) dp[1][i][i]=1;
	}
	so(i,1,n,1) so(j,1,10,1)
	{
		so(k,1,10,1)
		{
			if(!dp[i][j][k]) continue;
			so(v,j+1,10,1)
			{
				if(!a[v]) continue;
				if(v==k) continue;
				dp[i+1][v-j][v]=1;pre[i+1][v-j][v][0]=j;pre[i+1][v-j][v][1]=k;
			}
		}
	}
	so(i,1,10,1) so(j,1,10,1)
	{
		if(dp[n][i][j])
		{
			int x=i,y=j;
			cout<<"YES"<<endl;//<<j<<" ";
			ans[n]=j;
			for(int k=n;k>=2;k--)
			{
				int x1=pre[k][x][y][0];
				int y1=pre[k][x][y][1];
				x=x1;y=y1;
				//cout<<y1<<" ";
				ans[k-1]=y1;
			}
			so(i,1,n,1) cout<<ans[i]<<" ";
			return 0;
		}
	}
	//so(i,1,n,1) so(j,1,10,1){so(k,1,10,1) cout<<i<<":"<<dp[i][j][k]<<" ";cout<<endl;}
	cout<<"NO";
	return 0;

}

