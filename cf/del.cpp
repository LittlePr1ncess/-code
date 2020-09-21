#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200000
#define INF 2147483647/2-1
using namespace std;
inline int read()
{
    int x=0;
    bool f=1;
    char c=getchar();
    for(; !isdigit(c); c=getchar()) if(c=='-') f=0;
    for(; isdigit(c); c=getchar()) x=(x<<3)+(x<<1)+c-'0';
    if(f) return x;
    return 0-x;
}
int n,m,ans,f1[maxn+10],f2[maxn+10],head[maxn+10],cnt=0,T,a,b,da,db;
struct node
{
    int u,v,w,nex;
}edge[2*maxn+10];
inline void add(int x,int y,int z)
{
    cnt++;
    edge[cnt].u=x;
    edge[cnt].v=y;
    edge[cnt].w=z;
    edge[cnt].nex=head[x];
    head[x]=cnt;
}
inline void dp(int x,int fa)
{
    for(int i=head[x];i!=-1;i=edge[i].nex)
    {
        int j=edge[i].v;
        if(j==fa)continue;
        dp(j,x);
        if(f1[x]<f1[j]+edge[i].w)
        {
            f2[x]=f1[x];
            f1[x]=f1[j]+edge[i].w;
        }
        else if(f2[x]<f1[j]+edge[i].w)
        {
            f2[x]=f1[j]+edge[i].w;
        }
        ans=max(ans,f1[x]+f2[x]);
    }
}
inline int dfs(int x,int fa,int len)
{
    for(int i=head[x];i!=-1;i=edge[i].nex)
    {
        int j=edge[i].v;
        if(j==fa)continue;
        if(j==b) return len+1;
        int emm = dfs(j,x,len+1);
        if(emm) return emm;
    }
    return 0;
}
int main()
{
    
    int a[100] = {0,1 ,2 ,4 ,4};
    cout<<(lower_bound(a+1,a+1+4,3)-a);
    cin>>a[0];
}