#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
#define MN 10010
#define MM 500010
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
deque<int>q;
int n,m,dis[MN],diss[MN],s,hh[MN],h[MN],viss[MN],vis[MN],tott,tot,ans;
struct lll{
	int to,ne,w;
}a[MM],aa[MM];
void link(int x,int y,int z)
{
	a[++tot].to=y,a[tot].ne=h[x],h[x]=tot,a[tot].w=z;
}void link2(int x,int y,int z)
{
	aa[++tott].to=y,aa[tott].ne=hh[x],hh[x]=tott,aa[tott].w=z;
}
int main()
{
	scanf("%d%d%d",&n,&m,&s);
	//memset(dis,0x7f,sizeof(dis));
	for(int i=1;i<=n;i++) dis[i]=(1<<31)-1;
	while(m--)
	{
		int x,y,z;scanf("%d%d%d",&x,&y,&z);link(x,y,z);link2(y,x,z);
	}
	q.push_front(s);dis[s]=0;vis[s]=1;
	while(!q.empty())
	{
		int v=q.front();vis[v]=0;q.pop_front();
		for(int i=h[v];i;i=a[i].ne)
		{
			if(a[i].w+dis[v]<dis[a[i].to])
			{
				dis[a[i].to]=a[i].w+dis[v];
				if(!vis[a[i].to])
				if(!q.empty()&&dis[a[i].to]<dis[q.front()])
				q.push_front(a[i].to),vis[a[i].to]=1;
				else q.push_back(a[i].to),vis[a[i].to]=1;
			}
		}
	}
	while(!q.empty()) q.pop_front();
	
	for(int i=1;i<=n;i++) diss[i]=(1<<31)-1;
	q.push_front(s);diss[s]=0;viss[s]=1;
	//cout<<q.front();
	while(!q.empty())
	{
		int v=q.front();viss[v]=0;q.pop_front();
		//cout<<v<<" ";
		for(int i=hh[v];i;i=aa[i].ne)
		{
			if(aa[i].w+diss[v]<diss[aa[i].to])
			{
				diss[aa[i].to]=aa[i].w+diss[v];
				if(!viss[aa[i].to])
				if(!q.empty()&&diss[aa[i].to]<diss[q.front()])
				q.push_front(aa[i].to),viss[aa[i].to]=1;
				else q.push_back(aa[i].to),viss[aa[i].to]=1;
			}
		}
	}
	so(i,1,n,1) ans=max(ans,dis[i]+diss[i]);
	cout<<ans;
	/*for(int i=1;i<=n;i++)
	printf("%d ",dis[i]);cout<<endl;
	for(int i=1;i<=n;i++)
	printf("%d ",diss[i]);cout<<endl;*/
	return 0;
}
