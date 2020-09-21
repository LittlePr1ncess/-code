nclude<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<iostream>
using namespace std;
int t;
int n;
int ite;
int p[20][5];
int l[20];
bool used[200];
int ans;
int res[20][5];
void dfs(int u)
{
	if(u==ite+1)
	{
		int rec=0;
		for(int i=1;i<=n;i++)
		{
			int fi=100000,la=0;
			for(int j=1;j<=ite;j++)
			{
				if(p[l[j]][1]==i||p[l[j]][2]==i)
				{
					fi=min(fi,j);
					la=max(fi,j);
				}
			}
			rec+=la-fi+1;
		}
		if(rec<=ans)
		{
			ans=rec;
			for(int j=1;j<=ite;j++)
			{
				res[j][1]=p[l[j]][1];
				res[j][2]=p[l[j]][2];
			}
		}
		return;
	}
	for(int i=1;i<=ite;i++)
	{
		if(!used[i])
		{
			l[u]=i;
			used[i]=true;
			dfs(u+1);
			l[u]=0;
			used[i]=false;
		}
	}
	return;
}
int main()
{
	cin>>t;
	for(int o=1;o<=t;o++)
	{
		scanf("%d",&n);
		ans=10000000;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				p[++ite][1]=i;
				p[ite][2]=j;
			}
		}
		dfs(1);
		for(int i=1;i<=ite;i++)
		{
			printf("%d %d\n",res[i][1],res[i][2]);
		}
		//printf("%d\n",ans);
	}
	return 0;
}
