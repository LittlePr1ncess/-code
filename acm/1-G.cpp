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
int T,n,S,ans[22],a[22],vis[22];
void dfs(int x,int sum)
{
	if(x>n)
	{
		so(i,1,n,1)
		{
			if(!vis[i]) continue;
			if((2*(sum-a[i])<S)&&(2*sum>=S)) ans[i]++;
		}
		return ;
	}
	vis[x]=1;dfs(x+1,sum+a[x]);
	vis[x]=0;dfs(x+1,sum);
}
int main()
{
	cin>>T;
	while(T--)
	{
		memset(ans,0,sizeof(ans));
		memset(vis,0,sizeof(vis));
		S=0;
		cin>>n;so(i,1,n,1 )		cin>>a[i],S+=a[i];
		dfs(1,0);
		so(i,1,n,1) 
		{
			if(i==1) cout<<ans[1];
			else cout<<" "<<ans[i];
		}
		
		cout<<endl;
	}
	return 0;

}

