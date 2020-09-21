#include<bits/stdc++.h>
using namespace std;
#define MN 100005
int n,link[MN],bu[MN],b[MN],ans[MN],cnt=0,bb[MN];
int main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		link[u]=i;link[v]=i;
		bu[u]++;bu[v]++;
	}
	
	for(int i=1;i<=n;i++)
	if(bu[i]==1) b[link[i]]=1;
	/*for(int i=1;i<=n;i++) cout<<link[i]<<" ";cout<<endl;
	for(int i=1;i<=n;i++) cout<<bu[i]<<" ";cout<<endl;
	for(int i=1;i<=n;i++) cout<<b[i]<<" ";cout<<endl;
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";cout<<endl;*/
	for(int i=1;i<=n;i++)
	{
		if(cnt==3) break;
		//for(int i=1;i<=n;i++) cout<<ans[i]<<" ";cout<<endl;
		if(b[i]) ans[i]=cnt++,bb[i]=1;//,cout<<cnt<<endl,cnt++;
	}
	for(int i=1;i<n;i++)
	{
		if(bb[i]) continue;
		ans[i]=cnt++;
	}
	
	for(int i=1;i<n;i++)
	{
		cout<<ans[i]<<endl;
	}
} 
