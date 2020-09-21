#include<bits/stdc++.h>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
#define MN 500005
int T,L,s,e,dep[MN],vis[MN],xx,ans;
queue<int>q;
int work(int x,int u)
{
   // cout<<x<<" ";
    if( x>=MN) return 0;
    if(x == e) return dep[u]+1;
    if(vis[x]) return 0 ;
    dep[x]=dep[u]+1;
    vis[x] = 1;
    q.push(x);
    return 0;
}
void doo(int x)
{
    for(;x;x>>=1)
    cout<<(x&1);
    cout<<endl;
}
int main()
{
    cin>>T;
    while(T--)
    {
        ans = 0;
        memset(vis,0,sizeof(vis));
        memset(dep,0,sizeof(dep));
        while(!q.empty()) q.pop();
        cin>>L; string s1, s2;
        cin >>s1>>s2;
        s = e = 0;
        for(int i=L-1;i>=0;i--) s*=2,s+=s1[i]-'0',e*=2,e+=s2[i]-'0';
        //cout<<s<<" "<<e<<endl;
        q.push(s);vis[s] = 1;
        while(!q.empty())
        {
            int u = q.front();
            //cout<<u<<" ";
            //doo(u);
            ans = work(u+1,u);
            int emm = u;
            for(int i=0;(emm | i<L);i++,emm>>=1)
            {
                if(emm&1) ans= work(u-(1<<i),u);
                else ans = work(u+(1<<i),u);
                if(ans ) break;
            }
            if(ans) break;
            q.pop();
        }
        //so(i,1,15,1) cout<<dep[i]<<" ";cout<<endl;
        cout<<ans<<endl;
    }
    //system("pause");
}