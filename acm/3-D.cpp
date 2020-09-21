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
int vis[12],n,k,ans;char mapp[12][12];
void dfs(int x,int sum)
{
	if(sum==k) {
		ans++;return ;
	}
	if(x==n+1) {
		return ;
	}
	so(i,x,n,1) {
		so(j,1,n,1)
		{
		if(mapp[i][j]=='.'||vis[j]) continue;
		if(sum<k) vis[j]=1,dfs(i+1,sum+1),vis[j]=0;}
		//dfs(x+1,sum);
	}
}
int main()
{
	while(~scanf("%d%d",&n,&k))
	{
		ans=0;
		if(n==-1) break;
		so(i,1,n,1) scanf("%s",mapp[i]+1),vis[i]=0;
		dfs(1,0);
		printf("%d\n",ans);
	}
	return 0;

}

