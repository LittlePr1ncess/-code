#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<cmath>
#define eps 0.0000000001
#define mem(a) memset(a,0,sizeof(a))
#define maxx 1e10
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
//priority_queue<ll,vector<ll>,greater<ll> > q;
#define mod 123456789
const ll maxn=50500;
 
int n,m,ans,sum;
struct A
{
    int st,ed;
    int w;
} a[maxn];
int father[maxn];
bool flag;
queue<int> q;
bool cmp(A a,A b)
{
    return a.w<b.w;
}
int Find(int x)
{
    if(x!=father[x])
    {
        father[x]=Find(father[x]);
    }
    return father[x];
}
void Union(int x,int y,int n)
{
    int fx=Find(x);
    int fy=Find(y);
    if(fx!=fy)
    {
        father[fx]=fy;
        ans+=a[n].w;
        if(flag==0)
        {
            q.push(n);
        }
 
    }
}
void init()
{
    ans=0;
    for(int i=1; i<=m; i++)
        father[i]=i;
    return;
}
 
int main()
{
    while(cin>>n>>m)
    {
        init();flag=0;
        int ans_num=0,ans_sum=0;
        int x,y,z;
        int gg;
        for(int i=1; i<=m; i++)
        {
            cin>>x>>y>>z;
            a[i].st=x;
            a[i].ed=y;
            a[i].w=z;
        }
        sort(a+1,a+m+1,cmp);
        for(int i=1; i<=m; i++)
        {
            Union(a[i].st,a[i].ed,i);
        }
        gg=ans;flag=1;
        while(!q.empty())
        {
            int i=q.front();
            q.pop();
            init();
            for(int j=1; j<=m; j++)
            {
                if(j==i)
                    continue;
                Union(a[j].st,a[j].ed,j);
            }
            if(ans!=gg)
            {
                ans_num++;
                ans_sum+=a[i].w;
            }
        }
        cout<<ans_num<<" "<<ans_sum<<endl;
    }
    return 0;
}
 
 
