#include<bits/stdc++.h>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i++)
#define MM 4000005
#define MN 4005
queue<int>q;
struct lll{
    int to,nxt;
}a[MM];
int tot,ans,h[MN],ru[MN],b[MN],x,y,n,m,dep[MN],emm[MN];
void add(int x,int y)
{
    a[++tot].to=y;a[tot].nxt=h[x];h[x]=tot;ru[y]++;
}
int main()
{
    //freopen("luogu/P1983_2.in","r",stdin);
    //freopen("luogu/niema.txt","w",stdout);
    cin>>n>>m;
    so(i,1,m,1)
    {
        so(j,1,n,1) b[j]=0;
        cin>>x;
        so(j,1,x,1) cin>>emm[j],b[emm[j]]=1;
        so(j,emm[1],emm[x],1) 
        {
            if(b[j]) {if(emm[x]-emm[1]>=x)add(i+n,j);}
            else add(j,i+n);
        }
    }
    //so(i,1,n,1) cout<<ru[i]<<" ";cout<<endl;
    so(i,1,n,1) if(!ru[i]) q.push(i),dep[i]=1;
    while(!q.empty())
    {
        int u = q.front();q.pop();
        //cout<<1<<endl;
        for(int i=h[u];i;i=a[i].nxt)
        {
            int v=a[i].to;
            ru[v]--;
            if(ru[v]) continue;
            if(v>n) dep[v]=dep[u],q.push(v);
            else dep[v]=dep[u]+1,q.push(v);
            ans = max(ans,dep[v]);
        }
    }
    cout<<ans;
    //cin>>x;
}