#include<cstdio>
#include<queue>
#include<cstring>
#include<iostream>
using namespace std;
#define MN 10010
#define MM 500010
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
deque<int>q;
int n,m,dis[MN],s,x,h[MN],vis[MN],tot;
struct lll{
	int to,ne,w;
}a[MM];
void link(int x,int y,int z)
{
	a[++tot].to=y,a[tot].ne=h[x],h[x]=tot,a[tot].w=z;
}
int main()
{
	
	while(~scanf("%d%d%d",&n,&m,&s))
	{
		for(int i=1;i<=n;i++) dis[i]=(1<<31)-1;
		tot=0;
		memset(vis,0,sizeof(vis));
		memset(h,0,sizeof(h));
		while(m--)
		{
			int y,z;scanf("%d%d%d",&x,&y,&z);link(y,x,z);
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
		int emm,ans=(1<<31)-1;
		cin>>emm;so(i,1,emm,1) cin>>x,ans=min(ans,dis[x]);
		if(ans==(1<<31)-1) cout<<-1<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}
