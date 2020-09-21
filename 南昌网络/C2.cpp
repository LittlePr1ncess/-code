#include<iostream>
#include<cstdio>
using namespace std;
#define MN 205 
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
int n,a[MN],b[MN],dp[MN][20][10],pre[MN][20][10][5],tag[MN];
void find(int dep,int room1,int room2)
{
	if(dep==0) return ;
	tag[dep]=pre[dep][room1][room2][3];
	find(dep-1,pre[dep][room1][room2][2],pre[dep][room1][room2][4]);
}
int main()
{
	//freopen("c.txt","w",stdout);
	cin>>n; 
	while(n)
	{
		so(i,1,n,1) cin>>a[i]>>b[i];
		dp[0][0][0] = 0;
		so(i,1,n,1) 
		{
			so(j,0,8,1)
			{
				so(k,0,8,1)
				{
				if(dp[i-1][j][k]+a[i]>dp[i][j+1][k]) 
				dp[i][j+1][k]=dp[i-1][j][k]+a[i],
				pre[i][j+1][k][1]=i-1,
				pre[i][j+1][k][2]=j,
				pre[i][j+1][k][3]=1,
				pre[i][j+1][k][4]=k;
				//{0,i-1,j,1};
				if(dp[i-1][j][k]+b[i]>dp[i][j][k+1]) 
				dp[i][j][k+1]=dp[i-1][j][k]+b[i],
				pre[i][j][k+1][1]=i-1,
				pre[i][j][k+1][2]=j,
				pre[i][j][k+1][3]=2,
				pre[i][j][k+1][4]=k;
				//={0,i-1,j,2};
				if(dp[i-1][j][k]>dp[i][j][k]) 
				dp[i][j][k]=dp[i-1][j][k],
				pre[i][j][k][1]=i-1,
				pre[i][j][k][2]=j,
				pre[i][j][k][3]=0,
				pre[i][j][k][4]=k;
				//={0,i-1,j,0};
				}
			}
		}
		cout<<dp[n][8][8]<<endl;
		find(n,8,8); 
		so(i,1,n,1) 
		if(!tag[i]) continue; else cout<<i<<" "<<a[i]<<" "<<b[i]<<" "<<tag[i]<<endl;
		cin>>n;
	} 
	return 0;
} 
