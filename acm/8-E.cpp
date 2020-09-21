#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
 
const int maxn=100005;
 
struct note
{
    int u,v;
    LL w;
    bool operator < (const note &other) const
    {
        return w>other.w;
    }
} edge[maxn];
 
int father[maxn];
bool flag[maxn];
int n,m;
 
void init()
{
    for(int i=0; i<=n; i++)
    {
        father[i]=i;
    }
}
 
int find(int u)
{
    if(u==father[u])
        return u;
    return father[u]=find(father[u]);
}
 
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0; i<n-1; i++)
        {
            int u,v;
            LL w;
            scanf("%d%d%I64d",&edge[i].u,&edge[i].v,&edge[i].w);
        }
        memset(flag,false,sizeof(flag));
        for(int i=0; i<m; i++)
        {
            int u;
            scanf("%d",&u);
            flag[u]=true;
        }
        init();
        LL sum=0;
        sort(edge,edge+n-1);
        for(int i=0; i<n-1; i++)
        {
            int x=find(edge[i].u);
            int y=find(edge[i].v);
            if(flag[x]&&flag[y])
            {
                sum+=edge[i].w;
            }
            else if(flag[x])
            {
                father[y]=x;
            }
            else
            {
                father[x]=y;
            }
        }
        printf("%I64d\n",sum);
    }
    return 0;
}
