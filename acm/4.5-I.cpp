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
#define Ma make_pair
#define MN 505
int dx[5]={0,0,0,1,-1},dy[5]={0,1,-1,0,0};
char a[MN][MN],b[MN][MN],c[MN][MN];
int dep[MN][MN],ans1,ans2,n,m;
int bfs()
{
	queue< pair<int,int> >q;
	so(i,1,n,1) so(j,1,m,1) dep[i][j]=0;
	q.push(Ma(1,1));dep[1][1]=1;
	while(!q.empty())
	{
		int x=q.front().first,y=q.front().second;q.pop();
		//cout<<x<<" "<<y<<endl;
		if(x==n&&y==m) return dep[x][y];
		so(i,1,4,1)
		{
			int xx=x+dx[i],yy=y+dy[i];
			if(xx<1||xx>n||yy<1||yy>m||dep[xx][yy]||c[xx][yy]=='#') continue;
			q.push(Ma(xx,yy));dep[xx][yy]=dep[x][y]+1;
		}
	}
	return -1;
}
int main()
{
	cin>>n>>m;
	so(i,1,n,1) so(j,1,m,1) cin>>a[i][j];
	so(i,1,n,1) so(j,1,m,1) cin>>b[i][j]; 
	
	so(i,1,n,1) so(j,1,m,1) c[i][j]=a[i][j];
//	so(i,1,n,1) {so(j,1,m,1) cout<<c[i][j]<<" "; cout<<endl;}
	ans1=bfs();
	so(i,1,n,1) so(j,1,m,1) c[i][j]=b[i][j];
//	
	ans2=bfs();
	so(i,1,n,1) so(j,1,m,1) if(a[i][j]=='.'&&b[i][j]=='.') c[i][j]='.';else c[i][j]='#';
	//so(i,1,n,1) {so(j,1,m,1) cout<<c[i][j]<<" "; cout<<endl;}
	if(ans1==-1) {
		cout<<"NO";return 0;
	}
	if(ans1!=ans2)
	cout<<"NO";
	else if(ans1==bfs())
	cout<<"YES";
	else cout<<"NO";
	//cout<<ans1<<" "<<ans2<<" "<<bfs();
	return 0;

}
/*
3 5


.....
##.#.
.....

.....
.#.##
.....
  
*/
