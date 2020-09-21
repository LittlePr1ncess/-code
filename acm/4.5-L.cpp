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
int b[20],x[20],y[20],xx[5],yy[5],tot,ans=2100000000,rwz;char s;
void parse(int s)
{
	for(int i=1;i<=tot;i++)
	{
		if(s&1) cout<<x[i]<<" "<<y[i]<<endl;
		s>>=1;
	}
}
bool check(int s)
{
	int c[5][5];
	so(i,1,tot,1) c[x[i]][y[i]]=b[i];
	so(i,1,4,1) if(xx[i]==1) so(j,1,4,1) c[i][j]^=1;
	so(i,1,4,1) if(yy[i]==1) so(j,1,4,1) c[j][i]^=1;
	for(int i=1;i<=tot;i++)
	{
		if(s&1) c[x[i]][y[i]]^=1;
		s>>=1;
	}
	so(i,1,4,1) so(j,1,4,1) if(c[i][j]) return 0;
	return 1;
}
void dfs(int n,int s,int sum)
{
	if(n==tot+1)
	{
		//if(s==53261) so(i,1,4,1) cout<<xx[i]<<" "<<yy[i]<<endl;
		if(check(s))
		{
			cout<<sum<<endl;
			parse(s);
			exit(0);
		}
		return ;
	}
	
	xx[x[n]]^=1,yy[y[n]]^=1;dfs(n+1,s|(1<<(n-1)),sum+1);
	xx[x[n]]^=1,yy[y[n]]^=1;dfs(n+1,s,sum);
}
int main()
{
	so(i,1,4,1) so(j,1,4,1) {cin>>s;tot++;if(s=='+') b[tot]=1;x[tot]=i;y[tot]=j;}
	//so(i,1,tot,1) cout<<x[i]<<" "<<y[i]<<":"<<b[i]<<endl;
	dfs(1,0,0);
	//cout<<ans<<endl;
	//parse(rwz);
	return 0;

}

