#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
#define MN 105
bool cmp(int a,int b)
{
    return a>b;
}
int n,T,a[MN],b[MN],c[MN],tot,cnt;
int main()
{
    cin>>T;
    while(T--)
    {
        tot = cnt = 0;
        cin>>n;
        so(i,1,n,1) cin>>a[i];so(i,1,n,1) cin>>b[i];
        so(i,1,n,1) if(!b[i]) c[++tot] = a[i];
        sort(c+1,c+1+tot,cmp);
        so(i,1,n,1) if(b[i]) cout<<a[i]<<" ";else cout<<c[++cnt]<<" ";
        cout<<endl;
        
    }
    //cin>>n;
}