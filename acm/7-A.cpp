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
int fr[100010],to[200010*2],nex[2*200010],v[200010],tl,d[100010];
bool b[100010];
void add(int x,int y,int w){
    to[++tl]=y;
    v[tl]=w;
    nex[tl]=fr[x];
    fr[x]=tl;
}
priority_queue< pair<int,int> > q;
int main(){
    int n,m,x,y,z,s;
    while(~scanf("%d%d",&m,&n)){
	tl=0;if(n==0) break;
	for(int i=1;i<=n;i++) d[i]=1e10,b[i]=fr[i]=0;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);add(y,x,z);
    }
    
    while(!q.empty() ) q.pop();
    d[1]=0;//b[1]=1;
    q.push(M(0,1));
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
    printf("%d\n",d[n]);
	}
    return 0;
}
