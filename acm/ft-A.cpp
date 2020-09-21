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
int dp[MN][MN];char s1[MN],s2[MN];
int main()
{
	while(~scanf("%s%s",s1+1,s2+1))
	{
		so(i,1,strlen(s1+1),1) so(j,1,strlen(s2+1),1)
		if(s1[i]==s2[j]) dp[i][j]=dp[i-1][j-1]+1;
		else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
		cout<<dp[strlen(s1+1)][strlen(s2+1)]<<endl; 
	}
	return 0;

}

