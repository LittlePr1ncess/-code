#include<bits/stdc++.h>
using namespace std;
#define MN 5000005
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
struct lll{
    int x,y;
}a[MN];
vector<int>v[MN];
int n,m,x,y,colr[MN],ans[MN],u,w,flag;
bool cmp(lll a,lll b)
{
    return a.y<b.y;
}
int main()
{
    //freopen("stdout.txt","r",stdin);
    cin>>n>>m;
    //cout<<n<<m<<endl;
    so(i,1,m,1) cin>>x>>y,v[x].push_back(y),v[y].push_back(x);
    //cout<<"W";
    so(i,1,n,1) cin>>a[i].y,a[i].x=i;
    sort(a+1,a+1+n,cmp);
    //if(m==0) {cout<<1;return 0}
    so(i,1,n,1) {
        u=a[i].x,w=a[i].y,flag=0;
        if(v[u].size()>0)
        {
            so(j,0,v[u].size()-1,1)
            {
                int rwz=v[u][j];
                //cout<<v[u][j];
                if(colr[rwz]==w) {cout<<-1;return 0;}
                if(colr[rwz]==w-1) flag=1;
                colr[u]=w;
            }
        }
        if(!flag) {cout<<-1;return 0;}
        ans[i]=u;
    }
   // cout<<"w";
    so(i,1,n,1) cout<<ans[i]<<" ";
    return 0;
   // system("pause");
}