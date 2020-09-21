#include<bits/stdc++.h>
using namespace std;
#define MN 100005
#define MM 500005
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
struct lll{
    int to,nxt;
}a[MM],e[MM];
int tot,cnt,h[MN],w[MN],W[MN],h1[MN],low[MN],dfn[MN],jsq,vis[MN],col[MN],n,m,x[MM],y[MM],tot1,ru[MN],dp[MN],ans;
void add(int x,int y)
{
    a[++tot].to = y;a[tot].nxt =h[x];h[x] = tot;
}
void link(int x,int y)
{
    e[++tot1].to = y;e[tot1].nxt = h1[x];h1[x] = tot1;ru[y] ++;
}

queue<int>q1;
stack<int>q;
void tarjan(int u)
{
    dfn[u] = low[u] = ++jsq;
    q.push(u);
    vis[u] = true;
    for(int i = h[u];i;i = a[i].nxt)
    {
        int v = a[i].to;
        if(!dfn[v])     tarjan(v),low[u] = min(low[u],low[v]);//深度优先搜索森林中的树根
        else if(vis[v])  low[u] = min(low[u],dfn[v]);//判断谁是树根    
    }
    if(dfn[u] == low[u])//发现更新完一轮自己是树根
    {
        cnt++;
        while(q.top() != u)
        {
            col[q.top()] = cnt;//染色
            vis[q.top()] = false;
            W[cnt]+=w[q.top()];
            q.pop();
        }
        col[q.top()] = cnt;//染色
            vis[q.top()] = false;
            W[cnt]+=w[q.top()];
            q.pop();
    }
}
int main()
{
    cin>>n>>m;
    so(i,1,m,1) cin>>x[i]>>y[i],add(x[i],y[i]);
    so(i,1,n,1) if(!low[i]) tarjan(i);
    so(i,1,m,1) if(col[x[i]]!=col[y[i]]) link(col[x[i]],col[y[i]]);
    //so(i,1,cnt,1) cout<<W[i]<<" ";cout<<endl;
    so(i,1,cnt,1) if(!ru[i]) ans++;
    cout<<ans;
   // cin>>n;
}