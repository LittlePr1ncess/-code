#include<bits/stdc++.h>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
int n,T,m,a,b,ans;
int main()
{
    cin>>T;
    while(T--)
    {
        ans=2100000000;
        cin>>n>>m;
        so(i,1,n,1) cin>>a>>b,
        ans=min(ans,(m+a-1)/a*b);
        cout<<ans<<endl;
    }
    //system("pasuse");
}