#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;int t=n/2;
    if((n*(n-1)/2)%n!=k) {cout<<"-1";return 0;}
    for(int i=1;i<=t;i++)
    {
        cout<<i<<" ";if(i!=(n-i)) cout<<n-i<<" ";
    }
    cout<<n;
    //system("pause");
}