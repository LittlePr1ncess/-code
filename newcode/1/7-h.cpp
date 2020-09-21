#include<bits/stdc++.h>
using namespace std;
const int p = 1e9+7;
long long n,k,ans=0,wz;
int main()
{
    cin>>n>>k;
    for(long long i=1,j;i<=k;i=j+1)
    {
        if(n/i==0) break;
        j=min(n/(n/i),k);
        ans+=(j-i+1)*(n/i);
        ans%=p;
    }
    //cout<<ans<<endl;
    n--;
    for(long long i=2,j;i<=k;i=j+1)
    {
        if(n/i==0) break;
        j=min(n/(n/i),k);
        ans+=(j-i+1)*(n/i);
        ans%=p;
    }
    n++;ans+=k-1;ans%=p;
    cout<<ans;
    //system("pause");
}