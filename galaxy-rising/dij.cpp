#include<bits/stdc++.h>
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
#define M(x,y) make_pair(x,y)
using namespace std;
#define MM 500005
#define MN 100005
struct lll{
    int to,w,nxt;
}a[MM*2];
int h[MN],tot,d[MN],vis[MN];
int n,m,x,y,z,s;
void add(int x,int y,int w)
{
    a[++tot].to=y;a[tot].w=w;a[tot].nxt = h[x];h[x]=tot;
}
priority_queue< pair<int,int> > q;
int main(){    
    while(~scanf("%d%d%d",&n,&m,&s))
    {
        tot=0;if(n==0) break;
        so(i,1,n,1) d[i]=((1<<31)-1),vis[i]=h[i]=0;
        so(i,1,m,1)
        {
            scanf("%d%d%d",&x,&y,&z);
            add(x,y,z);//add(y,x,z);
        }
        
        while(!q.empty() ) q.pop();
        d[s]=0;
        q.push(M(0,s));
        while(!q.empty())
        {
            int u=q.top().second; q.pop(); 
            if(vis[u]) continue;vis[u]=1;
            for(int i=h[u];i;i=a[i].nxt)
            {
                int v=a[i].to;
                if(d[v]>d[u]+a[i].w)
                {
                    d[v]=d[u]+a[i].w;
                    if(!vis[v]) q.push(M(-d[v],v));
                }
            }
        }
        so(i,1,n,1) printf("%d ",d[i]);
	}
    return 0;
}