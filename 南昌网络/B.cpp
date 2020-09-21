#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 10100
#define inf 6e9
#define LL long long
using namespace std;
struct qq{
    LL t,w;
    qq(LL tt=0,LL ww=0){t=tt;w=ww;}
}z;vector<qq>e[N*N];
vector<qq>aa;
struct node{
    LL u,d;
    bool operator < (const node&b)const{return d>b.d;}
    node(LL uu=0,LL dd=0){u=uu;d=dd;}
}nd;priority_queue<node>Q;
LL n,m,s,C,K,S,xx[N],yy[N],kk[N],ww[N],T;bool vis[N];LL d[N],Max1,Max2;
void dij(){
    Q.push(node(s,0));
    while(!Q.empty()){
        nd=Q.top();Q.pop();LL u=nd.u;
        if(vis[u])continue;vis[u]=1;
        for(int i=0;i<e[u].size();i++){
            z=e[u][i];
            if(d[u]+z.w<d[z.t]){
                d[z.t]=d[u]+z.w;
                Q.push(node(z.t,d[z.t]));
            }
        }
    }
    //for(int i=1;i<=n;i++)printf("%d ",d[i]);cout<<endl;
}
void clear()
{
	memset(d,0,sizeof(d));
	for(int i=1;i<=n+10;i++ ) 
	e[i].swap(aa);
	memset(vis,0,sizeof(vis));
	//Max1=Max2=-inf;
}
int main(){
	ios::sync_with_stdio(false);
	freopen("B.in","r",stdin);
	freopen("ha.txt","w",stdout);
	cin>>T;cout<<T<<endl;
	while(T--)
	{
		
		cin>>n>>m>>S>>K>>C;
		//scanf("%d%d%d",&n,&m,&s);
		for(int i=1;i<=K;i++) cin>>kk[i];
    	for(int i=1;i<=n+10;i++) d[i]=inf;d[S]=0;
    	cout<<T<<endl;
    	for(int i=1,x,y,w;i<=m;i++)
		{
        	cin>>xx[i]>>yy[i]>>ww[i];
			//scanf("%d%d%d",&x,&y,&w);
        	e[xx[i]].push_back(qq(yy[i],ww[i]));
        	e[yy[i]].push_back(qq(xx[i],ww[i]));
        	cout<<i<<endl;
    	}
    	
    	s=S;cout<<T<<endl;
    	dij();Max1=0;
    	for(int i=1;i<=n;i++) Max1=max(Max1,d[i]);
    	//clear();
    	memset(vis,0,sizeof(vis));
    	for(int i=1;i<=n+10;i++)d[i]=inf;d[n+10]=0;
    	//for(int i=1,x,y,w;i<=m;i++)
		//e[xx[i]].push_back(qq(yy[i],ww[i]));
		for(int i=1;i<=K;i++)e[n+10].push_back(qq(kk[i],0)),e[kk[i]].push_back(qq(n+10,0));
		s=n+10;
		cout<<T<<endl;
		dij();
		Max2=0;
		for(int i=1;i<=n;i++) Max2=max(Max2,d[i]);
		//if(1ll*Max1<=1ll*C*Max2) cout<<Max1<<endl;
		//else cout<<Max2<<endl; 
		clear();
	}
    
    return 0;
}
/*
1
8 7 8 7 7
2 7 3 8 6 1 7 
2 1 3
3 1 3
4 2 7
5 1 3
6 2 4
7 3 3
8 7 1


*/
