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
#define MN 1005
struct lll{
	int x,y;
}a[MN*MN];
int n,lk[MN][MN],x_[5]={0,-1,1,0,0},y_[5]={0,0,0,-1,1},endx,endy,tot,vis[MN*MN],d[MN*MN]
;char mapp[MN][MN];
int main()
{
	//freopen("a.txt","r",stdin);
	while(~scanf("%d",&n)){
	queue<lll>q;
	//memset(vis,0,sizeof(vis));
	//memset(d,0,sizeof(d));tot=0;
	//while(!q.empty()) q.pop();
	//char c=getchar();
	so(i,1,n,1) 
	{scanf("%s",mapp[i]+1);//cout<<mapp[i]<<endl;
	
	so(j,1,n,1)
	{
		
		
		//cout<<i<<","<<j<<" "<<mapp[i][j]<<endl;
		a[++tot].x=i;a[tot].y=j;
		lk[i][j]=tot;vis[tot]=0;d[tot]=0;
		if(mapp[i][j]=='S') q.push(a[tot]),vis[tot]=1;
		if(mapp[i][j]=='E') endx=i,endy=j;
	}
	}
	while(!q.empty())
	{
		lll v=q.front();
		if(v.x==endx&&v.y==endy) {
			cout<<d[lk[v.x][v.y]]<<endl; break;
		}
		so(i,1,4,1)
		{
			int dx=v.x+x_[i],dy=v.y+y_[i];
			if(dx<1||dx>n||dy<1||dy>n) continue;
			if(mapp[dx][dy]=='#') continue;
			if(!vis[lk[dx][dy]]) 
			vis[lk[dx][dy]]=1,d[lk[dx][dy]]=d[lk[v.x][v.y]]+1,q.push(a[lk[dx][dy]]);
			
		}
		q.pop();
	}
		if(q.empty()) cout<<-1<<endl;
	}

}
/*
5
.....
.....
.E#..
.#.S.
.....
5
S.#..
#.#.#
#.#.#
#...E
#....
*/
