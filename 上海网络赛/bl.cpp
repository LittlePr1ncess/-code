#include<bits/stdc++.h>
#define p 1000000007
using namespace std;
int T,n,ans,S,a[1000],vis[1000];
void dfs(int x,int sum)
{
	if(x==n+1) 
	{
		for(int i=1;i<=n;i++) 
		{
			if(!vis[i]) continue;
			if(2*sum>S+a[i]) return ;
		}
		if(sum*2>=S) 
		{
			/*for(int i=1;i<=n;i++)
			{
				if(!vis[i]) continue;
				cout<<a[i]<<" ";
			}
			cout<<endl;*/
			ans++;
		}return ;
	}
	vis[x]=1;
	dfs(x+1,sum+a[x]);
	vis[x]=0;
	dfs(x+1,sum);
}
int main()
{
	cin>>T;
	while(T--)
	{
		ans=0;S=0;
		cin>>n;for(int i=1;i<=n;i++) cin>>a[i],S+=a[i];
		dfs(1,0);
		cout<<ans<<endl;
	}
}
