#include<bits/stdc++.h>
using namespace std;
long long n,a[100005],ans;
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];a[0] = a[1];
        ans+=a[i]-a[i-1];
    }
    ans/=n-1;ans+=a[n];
    cout<<ans;
    //cin>>n;
}