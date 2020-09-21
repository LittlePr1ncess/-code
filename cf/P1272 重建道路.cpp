#include<bits/stdc++.h>
using namespace std;
#define MN 150
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
struct lll{
	int to,nxt;
}a[MN];
int n,p,h[MN],ans,fa[MN],root,x,y,tot;
void link(int x,int y)
{
	a[++tot].to=y;a[tot].nxt=h[x];h[x]=tot;
}
int dfs(int u)
{
	int son=0;
	for(int i=h[u];i;i=a[i].nxt)
	{
		son += dfs(a[i].to);
	}
	if(son+1==p) ans++;
	cout<<u<<" "<<son+1<<endl;
	
	return son+1;
}
int main()
{
	cin>>n>>p;
	so(i,1,n-1,1) cin>>x>>y,link(x,y),fa[y]=x;
	so(i,1,n,1) if(!fa[i]) root=i;
	dfs(root);
	cout<<ans;
} 
