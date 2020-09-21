#include<bits/stdc++.h>
using namespace std;
#define MM 2005
int g,n,m,T;
int a[30][MM+5][MM+5],sum[30][MM+5][MM+5];
void init()
{
	for(int k=2;k<=25;k++)
	{
		a[k][0][0]=1;
		for(int i=1;i<=MM;i++)
		{
			for (int j=0;j<=i;j++)
			{
				a[k][i][j]=(a[k][i-1][j]+a[k][i-1][j-1])%k;
			}
		}
	}
	for(int k=2;k<=25;k++)
	{
		a[k][0][0]=1;
		for(int i=1;i<=MM;i++)
		{
			for (int j=0;j<=i;j++)
			{
				if(a[k][i][j]==0) a[k][i][j]=1;
				else a[k][i][j]=0;
			}
		}
	}
	for(int k=2;k<=25;k++)
	{
		for(int i=1;i<=MM;i++)
		{
			for(int j=1;j<=MM;j++)
			{
				sum[k][i][j]=sum[k][i-1][j]+sum[k][i][j-1]-sum[k][i-1][j-1]+a[k][i][j];
			}
		}
	}
}
int main()
{
	//while(1) g=g;
	init();
	/*for(int i=0;i<=10;i++)
	{
		for(int j=0;j<=i;j++)
		{
			cout<<sum[4][i][j]<<" ";
		}cout<<endl;
	}*/
	scanf("%d",&T);
	while(T--)
	{
		//cin>>g;cin>>n>>m;
		scanf("%d%d%d",&g,&n,&m);
		cout<<sum[g][n][m]<<endl;
	}
} 
