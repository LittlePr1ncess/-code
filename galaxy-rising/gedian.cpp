#include<bits/stdc++.h>
using namespace std;
#define MM 100005
#define MN 20005
#define so(i,j,k,l) for(int i = j;i <= k;i += l)
struct lll{
    int to,nxt;
}a[MM*2];
int n,m,tot,cnt,emm,h[MN],low[MN],dfn[MN],gedian[MN],x,y;
void add(int x,int y)
{
    a[++tot].to = y;a[tot].nxt = h[x];h[x] = tot;
}
void tarjan(int u,int fa)
{
    dfn[u] = low[u] = ++cnt;int chd = 0;
    for(int i = h[u];i;i = a[i].nxt)
    {
        int v = a[i].to;
        
        if(!dfn[v])
        {   
            if(fa == -1) chd ++;
            tarjan(v,u);
            low[u] = min(low[v],low[u]);
            if(fa != -1&&dfn[u] <= low[v] &&!gedian[u]) emm++,gedian[u] = 1;  
        }
        low[u] = min(low[u],dfn[v]);
    }
    if(fa == -1&&chd>=2&&!gedian[u]) emm++,gedian[u] = 1;  
}
int main()
{
    cin>>n>>m;
    so(i,1,m,1) cin>>x>>y,add(x,y),add(y,x);
    so(i,1,n,1) if(!low[i]) tarjan(i,-1);
    cout<<emm<<endl;
    so(i,1,n,1) if(gedian[i]) cout<<i<<" ";

}