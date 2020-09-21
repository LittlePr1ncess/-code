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
int a[25][5],m,tot,cnt,vis[25], s[25];
void dfs(int x)
{
	so(i,1,3,1)
	{
		if(!vis[a[x][i]])  vis[a[x][i]]=1,s[++tot]=a[x][i],dfs(a[x][i]),tot--,vis[a[x][i]]=0;
		if(tot==20&&a[x][i]==m) 
		{
			cout<<++cnt<<": ";so(i,1,20,1) cout<<" "<<s[i];cout<<" "<<m;cout<<endl;
		}
	}
	return;
}
int main()
{
	so(i,1,20,1) cin>>a[i][1]>>a[i][2]>>a[i][3];
	while(~scanf("%d",&m))
	{
		if(!m) break;
		tot=cnt=0;
		vis[m]=1;s[++tot]=m;dfs(m);
	}
	return 0;

}

