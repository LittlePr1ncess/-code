#include<iostream>
#include<cstdio>
using namespace std;
#define MN 205 
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
int n,a[MN],b[MN],dp[MN][20],pre[MN][20][5],tag[MN];
void find(int dep,int room)
{
	if(dep==0) return ;
	tag[dep]=pre[dep][room][3];
	find(dep-1,pre[dep][room][2]);
}
int main()
{
	//freopen("c.txt","w",stdout);
	cin>>n; 
	while(n)
	{
		so(i,1,n,1) cin>>a[i]>>b[i];
		dp[0][0] = 0;
		so(i,1,n,1) 
		{
			so(j,0,16,1)
			{
				if(dp[i-1][j]+a[i]>dp[i][j+1]) 
				dp[i][j+1]=dp[i-1][j]+a[i],
				pre[i][j+1][1]=i-1,
				pre[i][j+1][2]=j,
				pre[i][j+1][3]=1;
				//{0,i-1,j,1};
				if(dp[i-1][j]+b[i]>dp[i][j+1]) 
				dp[i][j+1]=dp[i-1][j]+b[i],
				pre[i][j+1][1]=i-1,
				pre[i][j+1][2]=j,
				pre[i][j+1][3]=2;
				//={0,i-1,j,2};
				if(dp[i-1][j]>dp[i][j]) 
				dp[i][j]=dp[i-1][j],
				pre[i][j][1]=i-1,
				pre[i][j][2]=j,
				pre[i][j][3]=0;
				//={0,i-1,j,0};
			}
		}
		cout<<dp[n][16]<<endl;
		find(n,16); 
		so(i,1,n,1) 
		if(!tag[i]) continue; else cout<<i<<" "<<a[i]<<" "<<b[i]<<" "<<tag[i]<<endl;
		cin>>n;
	} 
	return 0;
} 
