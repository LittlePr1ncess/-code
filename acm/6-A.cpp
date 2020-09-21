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
#define MN 505
int n,V,v[MN],w[MN],dp[100005];
int main()
{
	cin>>n>>V;
	so(i,1,n,1) cin>>v[i]>>w[i];
	so(i,1,n,1)
	for(int j=V;j>=0;j--)
	{
		if(j-v[i]<0) break;
		dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
	}
	cout<<dp[V];
	return 0;

}

