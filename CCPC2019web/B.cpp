#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#define MN 100
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
#define LL long long
#define db double
using namespace std;
int T,n,a[MN];
int main()
{
    cin>>T;
    while(T--)
    {
        int f = 0;a[0] = -1;
        cin>>n;
        so(i,1,n,1) {cin>>a[i];if(a[i]==a[i-1]) f=1;}
        if(f) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
   //cin>>n;
    return 0;
}