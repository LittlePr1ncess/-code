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
int n,dp[250005],a[55],num[55];
int main()
{
	while(cin>>n)
	{
		if(n==-1) break;
		int sum=0;
		so(i,1,n,1) cin>>a[i]>>num[i],sum+=a[i]*num[i];
		int V=sum/2;
		memset(dp,0,sizeof(dp));
		so(i,1,n,1)
		for(int j=V;j>=0;j--)
		{
			for(int k=num[i];k>=0;k--)
			{
				if(j-num[i]*a[i]<0) break;
				dp[j]=max(dp[j],dp[j-num[i]*a[i]]+num[i]*a[i]);
			}
		}
		cout<<sum-dp[V]<<" "<<dp[V]<<endl;
	}
	return 0;

}

