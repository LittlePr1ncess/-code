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
int dp[505][505];
int main()
{
	char s1[505],s2[505];
	//scanf("%s",s1+1);//cout<<s1+1<<" "<<s2;
	while(~scanf("%s%s",s1+1,s2+1))
	{
		//cout<<s1+1<<" "<<s2+1;
		//cout<<"#######"<<strlen(s1+1)<<"###########";
		so(i,1,strlen(s1+1),1)
		so(j,1,strlen(s2+1),1)
		{
			if(s1[i]==s2[j]) dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
		cout<<dp[strlen(s1+1)][strlen(s2+1)]<<endl;
	}
	return 0;

}

