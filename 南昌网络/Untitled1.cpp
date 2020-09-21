#include<cstdio>
#include<iostream>
#include<queue>
#define pair pair<int,int>
using namespace std;
int head[1100],size;
int T,n,m,s,k,f[1100],c,dis[1100];
struct edge{
	int to,next,v;
}e[2000010];
bool vis[1100];
priority_queue<pair,vector<pair>,greater<pair> > q;
void add(int x,int y,int v)
{
	size++;e[size].to=y;e[size].next=head[x];e[size].v=v;head[x]=size;
}
void dij(int S)
{
	for (int i=0;i<=n;i++) dis[i]=1e9,vis[i]=0;
    dis[S]=0;
    q.push(make_pair(0,S));
    while (!q.empty())
    {
        int k=q.top().second;
        q.pop();
        if (vis[k]) continue; 
        vis[k]=1;
        for (int i=head[k];i;i=e[i].next)
        {
            int j=e[i].to;
            if (dis[j]>dis[k]+e[i].v)
                dis[j]=dis[k]+e[i].v,q.push(make_pair(dis[j],j));
        }
    }
    //for(int i=1;i<=n;i++) cout<<dis[i]<<" ";
	//cout<<endl; 
} 
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d%d%d",&n,&m,&s,&k,&c);
		for (int i=1;i<=k;i++) scanf("%d",&f[i]);
		for (int i=1,x,y,v;i<=m;i++)
			scanf("%d%d%d",&x,&y,&v),add(x,y,v),add(y,x,v);
		dij(s);
		int max1=0;
		for (int i=1;i<=n;i++) max1=max(max1,dis[i]);
		for (int i=1;i<=k;i++) add(0,f[i],0),add(f[i],0,0);
		dij(0);
		int max2=0;
		for (int i=1;i<=n;i++) max2=max(max2,dis[i]);
		if (max2*c>=max1) printf("%d\n",max1);
		else printf("%d\n",max2);
		size=0;
		for (int i=0;i<=n;i++) head[i]=0;
	}
}

