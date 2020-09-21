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
#define MN 6005
//vector<int> son[MN];
int n,a[MN],dp[MN][2],x,y,fa[MN];
void dfs(int u)
{
	dp[u][1]=dp[u][0]=0;
	if(son[u].size()==0) {
		dp[u][1]=a[u];dp[u][0]=0;return ;
	}
	so(i,0,son[u].size()-1,1)
	{
		dfs(son[u][i]);
		dp[u][1]+=dp[son[u][i]][0];
		dp[u][0]+=max(dp[son[u][i]][1],dp[son[u][i]][0]);
	}
}
int main()
{
	while(cin>>n)
	{
	so(i,1,n,1) cin>>a[i];
	vector<int>son[n+5];
	so(i,1,n-1,1) cin>>x>>y,son[y].push_back(x),fa[x]=y;
	so(i,1,n,1) if(!fa[i]){dfs(i);cout<<max(dp[i][0],dp[i][0])<<endl;break;}
	}
	
	return 0;

}

