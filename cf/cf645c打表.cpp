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
int c[1000000],n,m,ans;
int mapp[50][50];
void dfs(int a,int b,LL sum)
{
	if(a==n&&b==m) if(!c[sum]) c[sum]=1,ans++;
	if(a+1<=n) dfs(a+1,b,sum+mapp[a+1][b]);
	if(b+1<=m) dfs(a,b+1,sum+mapp[a][b+1]);
}
int main()
{
	//int n,m;
	//so(i,1,10,1) so(j,1,10,1)
	//mapp={{0},{0,1,2,4,7},{0,3,5,8,12},{0,6,9,13,18},{0,10,14,19,25}};
	so(i,1,4,1) so(j,1,4,1) cin>>mapp[i][j];
	for(n=1;n<=4;n++) for(m=n;m<=4;m++)
	{
		ans=0;
		memset(c,0,sizeof(c));
		dfs(1,1,0);
		if(n>1&&m>1)
		cout<<n-1<<" "<<m-1<<":"<<ans<<endl; 
	}
	return 0;

}
/*
1 2 4 7
3 5 8 12
6 9 13 18
10 14 19 25
*/

