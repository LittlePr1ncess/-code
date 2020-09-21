#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<cmath>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
#define LL long long
LL n,s,x,y,M=2100000000,ans;
int main()
{
	cin>>n>>s;
	so(i,1,n,1)
	{
		cin>>x>>y;M=min(M,x+s*(n-i));
		ans+=M*y;ans-=s*(n-i)*y;
	}
	cout<<ans;
	return 0;

}

