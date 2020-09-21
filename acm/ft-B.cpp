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
int n,k,dep[MN*2];
int main()
{
	cin>>n>>k;
	queue<int>q;
	memset(dep,-1,sizeof(dep));
	q.push(n);dep[n]=0;
	while(!q.empty())
	{
		int v=q.front();q.pop();
		if(v==k) {
			cout<<dep[v]<<endl;break;
		}
		if(dep[v+1]==-1) dep[v+1]=dep[v]+1,q.push(v+1);
		if(v>=1&&dep[v-1]==-1) dep[v-1]=dep[v]+1,q.push(v-1);
		if(v<=k&&dep[2*v]==-1) dep[2*v]=dep[v]+1,q.push(v*2);
	}
	return 0;

}

