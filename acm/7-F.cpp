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
#define MN 105
int n,m,x,y,a[MN][MN],ans;
int main()
{
	cin>>n>>m;
	so(i,1,m,1) cin>>x>>y,a[x][y]=1;
	so(k,1,n,1) so(i,1,n,1) so(j,1,n,1)
	{
		if(a[i][k]&&a[k][j]) a[i][j]=1;
	}
	so(i,1,n,1) 
	{
	int flag=1;	
	so(j,1,n,1) {
		if((i!=j)&&(!a[i][j])&&(!a[j][i])) flag=0; 
	}
	ans+=flag;
	}
	//so(i,1,n,1){so(j,1,n,1) cout<<a[i][j]<<" ";cout<<endl;}
	cout<<ans;
 	return 0;

}

