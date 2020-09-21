#include<bits/stdc++.h>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
#define LL long long 
#define db double
int T,n,m,x,l,r,a,b;
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>x>>m;
        int l=x,r=x;
        so(i,1,m,1)
        {
            cin>>a>>b;
            if(a>r||b<l) continue;
            l=min(l,a);r=max(r,b);
        }
        cout<<r-l+1<<endl;
    }
    //system("pause");
}