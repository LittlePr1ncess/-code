#include<bits/stdc++.h>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
#define MN 10005
#define p 1000000007
struct lll{
	int nxt,to,w;
}a[MN*2];
int n,tot,vis[MN],x,y,z,root;
long long dp[3][MN],len[3][MN],h[MN],son[3][MN];
void link(int x,int y,int z)
{a[++tot].to=y;a[tot].w=z;a[tot].nxt=h[x];h[x]=tot;}
void dfs(int u)
{
	for(int i=h[u];i;i=a[i].nxt)
	{
		int v=a[i].to;
		if(!vis[v]) vis[v]=1,dfs(v);
		so(j,0,2,1) 
		{
			len[j][v]+=(a[i].w*son[j][v])%p;len[j][v]%=p;
			len[(j+a[i].w)%3][u]+=len[j][v];//+;
			len[(j+a[i].w)%3][u]%=p;
			son[(j+a[i].w)%3][u]+=son[j][v];
		}
		//son[0][u]++;
		so(j,0,2,1){dp[j][u]+=dp[j][v];dp[j][u]%=p;}
		so(j,0,2,1)
		{
			so(k,0,2,1)
			{
				dp[(j+k)%3][u]
				+=len[j][v]*((son[k][u]-son[k][v]+p)%p)%p+
				len[k][u]-len[k][v]+len[j][v];
				dp[(j+k)%3][u]%=p;
			}
		}
	}
	son[0][u]++;
}
int main()
{
	while(~scanf("%d",&n))
	{
		memset(h,0,sizeof(h));
		memset(vis,0,sizeof(vis));
		memset(dp,0,sizeof(dp));
		so(i,1,n-1,1) cin>>x>>y>>z,link(x,y,z),link(y,x,z),root=x;
		vis[root]=1;dfs(root);
		//cout<<root<<endl;
		so(i,0,2,1) cout<<dp[i][root]<<" ";
		
		so(i,0,n-1,1) {
		so(j,0,2,1) cout<<dp[j][i]<<" ";
		cout<<endl;
		}
	}
	return 0;
}
