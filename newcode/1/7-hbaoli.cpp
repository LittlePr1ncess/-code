#include<bits/stdc++.h>
using namespace std;
#define p 1000000007
long long n,k,ans;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=k;i++) ans+=(n-1)/i,ans%=p;
    cout<<ans<<endl;
    ans+=k;ans%=p;
    for(int i=2;i<=k;i++)
    {
        if(i>n) break;
        ans+=(long long)(log2(n)/log2(i)+0.001);
        ans%=p;
    }
    cout<<ans;
    system("pause");
}