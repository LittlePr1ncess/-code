#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
 LL x,y,k;int T;
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>x>>y>>k;
        cout<<(k*y+k-1+x-2)/(x-1)+k<<endl;
    }
    //cin>>T;
}