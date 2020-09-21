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
#define MN 100005
int n,k,d[MN*4],vis[MN*4];
queue<int>q; 
int main()
{
	cin>>n>>k;
	q.push(n);
	vis[n]=1;d[n]=0;
	while(!q.empty())
	{
		int v=q.front();
		//cout<<v;
		if(v==k) {
			cout<<d[v];return 0; 
		}
		if(!vis[v+1]&&v+1<=k) q.push(v+1),d[v+1]=d[v]+1,vis[v+1]=1;
		if(!vis[v-1]&&v>=1) q.push(v-1),d[v-1]=d[v]+1,vis[v-1]=1;
		if(!vis[v*2]&&v<=k) q.push(v*2),d[v*2]=d[v]+1,vis[v*2]=1;
		q.pop();
		//so(i,1,20,1) cout<<d[i]<<" ";cout<<endl;
		
	}
	return 0;

}

