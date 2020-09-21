#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 100005
#define inf 2147483647
using namespace std;
struct qq{
    int t,w;
    qq(int tt=0,int ww=0){t=tt;w=ww;}
}z;vector<qq>e[N];
struct node{
    int u,d;
    bool operator < (const node&b)const{return d>b.d;}
    node(int uu=0,int dd=0){u=uu;d=dd;}
}nd;priority_queue<node>Q;
int n,m,s,d[N];bool vis[N];
void dij(){
    Q.push(node(s,0));
    while(!Q.empty()){
        nd=Q.top();Q.pop();int u=nd.u;
        if(vis[u])continue;vis[u]=1;
        for(int i=0;i<e[u].size();i++){
            z=e[u][i];
            if(d[u]+z.w<d[z.t]){
                d[z.t]=d[u]+z.w;
                Q.push(node(z.t,d[z.t]));
            }
        }
    }
    for(int i=1;i<=n;i++)printf("%d ",d[i]);
}
int main(){
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<=n;i++)d[i]=inf;d[s]=0;
    for(int i=1,x,y,w;i<=m;i++){
        scanf("%d%d%d",&x,&y,&w);
        e[x].push_back(qq(y,w));
    }
    dij();
    return 0;
}
