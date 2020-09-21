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
#define M(x,y) make_pair(x,y)
int fr[100010],to[200010],nex[200010],v[200010],tl,d[100010];
bool b[100010],tag[100010];
void add(int x,int y,int w){
    to[++tl]=y;
    v[tl]=w;
    nex[tl]=fr[x];
    fr[x]=tl;
}
priority_queue< pair<int,int> > q;
int main(){
    int n,m,x,y,z,s,ans=1e10;
    while(~scanf("%d%d%d",&n,&m,&s))
	{
	tl=0;so(i,1,n,1) fr[i]=b[i]=0;ans=1e10;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&x,&y,&z);
        add(y,x,z);
    }
    
    for(int i=1;i<=n;i++) d[i]=1e10;
    d[s]=0;
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
   	// so(i,1,n,1 )cout<<d[i]<<" "; 
   	int emm;
    cin>>emm;so(i,1,emm,1) cin>>x,ans=min(ans,d[x]);
    if(ans==2147483647) cout<<-1<<endl;
    else 
    cout<<ans<<endl;
	}
    return 0;
}
