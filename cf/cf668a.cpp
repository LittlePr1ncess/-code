#include<bits/stdc++.h>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
int T,n,a[10000];
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n;
        so(i,1,n,1) cin>>a[i];
        for(int i=n;i>=1;i--) cout<<a[i] <<" ";cout<<endl;
    }
    //cin>>n;
}