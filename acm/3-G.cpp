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
#define MN 10005
int b[MN],T,x,y,vis[MN],dep[MN];
void init()
{
	so(i,1000,9999,1)
	{
		for(int j=2;j*j<=i;j++)
		if(!(i%j)) b[i]=1;
	}
}
int main()
{
	
	init();
	so(i,0,999,1) b[i]=1; 
	cin>>T;
	//cout<<b[1030];
	while(T--)
	{	
		memset(vis,0,sizeof(vis));
		memset(dep,0,sizeof(dep));
		queue<int>q;
		cin>>x>>y;
		vis[x]=1;q.push(x);
		while(!q.empty())
		{
			int v=q.front();q.pop();
		//	cout<<dep[v]<<" "<<v<<" ";
			if(v==y) {cout<<dep[y]<<endl;break;}
			int a=v%10,bb=int((v/10))%10,c=(v/100)%10,d=v/1000;
			//cout<<v<<" "<<a<<" "<<bb<<" "<<c<<" "<<d<<endl;
			so(i,0,9,1){int u=v-a+i;if((vis[u]==0)&&!b[u]) vis[u]=1,/*cout<<v<<" "<<u<<" ",*/q.push(u),dep[u]=dep[v]+1;}
			so(i,0,9,1){int u=v-bb*10+i*10;if((vis[u]==0)&&!b[u]) vis[u]=1,/*cout<<v<<" "<<u<<" ",*/q.push(u),dep[u]=dep[v]+1;}
			so(i,0,9,1){int u=v-c*100+i*100;if((vis[u]==0)&&!b[u]) vis[u]=1,/*cout<<v<<" "<<u<<" ",*/q.push(u),dep[u]=dep[v]+1;}
			so(i,0,9,1){int u=v%1000+i*1000;if((vis[u]==0)&&!b[u]) vis[u]=1,/*cout<<v<<" "<<u<<" ",*/q.push(u),dep[u]=dep[v]+1;}
		}
	}
	return 0;

}

