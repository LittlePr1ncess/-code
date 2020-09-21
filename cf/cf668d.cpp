#include<bits/stdc++.h>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
#define MN 200005
void dfs(int u)
{
    
}
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>a>>b>>da>>db;
        so(i,1,n-1,1) cin>>x>>y,add(x,y),add(y,x);
        dfs(1);
    }
}