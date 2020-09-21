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
#define MN 25
#define Ma make_pair
int n,m,ans,vis[MN][MN],sx,sy,dx[5]={0,0,0,1,-1},dy[5]={0,1,-1,0,0};
char mapp[MN][MN];
int main()
{
	while(cin>>m>>n)
	{
		queue< pair<int,int> >q;
		if(!n) break;
		memset(vis,0,sizeof(vis));
		ans=0;
		so(i,1,n,1) so(j,1,m,1){cin>>mapp[i][j];if(mapp[i][j]=='@') sx=i,sy=j;}
		//cout<<"#####"<<sx<<" "<<sy<<"#######";
		q.push(Ma(sx,sy));vis[sx][sy]=1;
		while(!q.empty())
		{
			int x=q.front().first,y=q.front().second;q.pop();
			so(i,1,4,1)
			{
				int xx=x+dx[i],yy=y+dy[i];
				//cout<<xx<<" "<<yy<<endl;
				if(xx<1||yy<1||xx>n||yy>m||vis[xx][yy]||mapp[xx][yy]=='#')continue;
				q.push(Ma(xx,yy));vis[xx][yy]=1;
			}
		}
		//so(i,1,n,1){so(j,1,m,1) cout<<vis[i][j]<<" ";cout<<endl;}
		so(i,1,n,1) so(j,1,m,1 ) if(vis[i][j]) ans++;
		cout<<ans<<endl;
	} 
	return 0;

}

