#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<cmath>

#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
#define M(x,y) make_pair(x,y)
using namespace std;
int fr[100010],to[200010],nex[200010],v[200010],tl,d[100010];
bool b[100010];
void add(int x,int y,int w){
    to[++tl]=y;
    v[tl]=w;
    nex[tl]=fr[x];
    fr[x]=tl;
}
priority_queue< pair<int,int> > q;
int main(){
    int n,m,x,y,z,ss,s;
    while(~scanf("%d%d%d",&n,&m,&ss))
    {
    	tl=0;
    so(i,1,n,1) b[i]=fr[i]=0;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
    }
	int ans=1e10,rwz;
    cin>>rwz;so(i,1,rwz,1) cin>>x,add(n+1,x,0);
    s=n+1;
    for(int i=1;i<=n;i++) d[i]=1e10;
    d[s]=0;
    while(!q.empty()) q.pop();
    q.push(M(0,s));
    while(!q.empty()){
        int x=q.top().second;
        q.pop(); 
        if(b[x]) continue;
        b[x]=1;
        for(int i=fr[x];i;i=nex[i]){
            int y=to[i],l=v[i];
            if(d[y]>d[x]+l){
                d[y]=d[x]+l;
                q.push(M(-d[y],y));
            }
        }
    }
    
    //so(i,1,n,1){so(j,1,n,1) cout<<d[i][j]<<" ";cout<<endl;}
    //for(int i=1;i<=n;i++) printf("%d ",d[i]);
    if(d[ss]==2147483647) cout<<-1<<endl;
    else cout<<d[ss]<<endl;
	}
	
    return 0;
}
/*
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<cmath>

#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
using namespace std;
 
const int maxn=99999999;
int mp[1005][1005];
int vis[1005],le[1005];
 
int main(void)
{
	int n,m,i,j,a,b,x,st,ed,w;
	while(~scanf("%d%d%d",&n,&m,&ed))
	{
		memset(vis,0,sizeof(vis));
		memset(le,maxn,sizeof(le));
		for(i=1;i<=1003;i++)
		{
			for(j=1;j<=1003;j++)
			{
				if(i==j) mp[i][j]=0;
				else mp[i][j]=maxn;
			}
		}
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&a,&b,&x);
			if(mp[b][a]>x) mp[b][a]=x;
		}
		for(i=1;i<=n;i++)
		{
			le[i]=mp[ed][i];
		}
		vis[ed]=1;
		for(j=1;j<=n;j++)
		{
			int k;
			int mi=maxn;
			for(i=1;i<=n;i++)
			{
				if(vis[i]==0&&le[i]<mi) //
				{
					mi=le[i];
					k=i;
				}
		    }
			vis[k]=1;
			for(i=1;i<=n;i++)
			{
				if(vis[i]==0&&le[k]+mp[k][i]<le[i])
				le[i]=le[k]+mp[k][i];
			}
		}
		int tp=maxn;
		scanf("%d",&w);
		while(w--)
		{
			scanf("%d",&st);
			if(le[st]<tp) tp=le[st];
		}
		if(tp==maxn) printf("-1\n");
		else printf("%d\n",tp);
	}
	return 0;
}
*/
