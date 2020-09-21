#include<bits/stdc++.h>
using namespace std;
long long solve(long long n)
{
    if(!n) return 0;
    return solve(n/2)+n;
}
int main()
{
    int T;cin>>T;
    while(T--)
    {
        long long n;cin>>n;
        cout<<solve(n)<<endl;
    }
    //system("pasuse");
}