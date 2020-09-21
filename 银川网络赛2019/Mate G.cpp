#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int tails,n,m,to[555],fr[311],nxt[555],len[555];
void add(int f,int t,int le){
	len[++tails]=le;
	nxt[tails]=fr[f];
	fr[f]=tails;
	to[tails]=t;
}
int dis[333];bool inq[333];queue<int>R;
int SPFA(int st,int en){
	memset(dis,127,sizeof(dis));
	memset(inq,0,sizeof(inq));
	dis[st]=0;inq[st]=1;R.push(st);
	while(!R.empty()){
		int u=R.front();R.pop();inq[u]=0;
		for(int i=fr[u];i;i=nxt[i]){
			if(dis[to[i]]>dis[u]+len[i]){
				dis[to[i]]=dis[u]+len[i];
				if(!inq[to[i]]){
					R.push(to[i]);
					inq[to[i]]=1;
				}
			}
		}
	}
	return dis[en];
}
void Work(){
	scanf("%d%d",&n,&m);
	for(int i=1,p1,p2,p3;i<=m;++i){
		scanf("%d%d%d",&p1,&p2,&p3);
		++p1;++p2;add(p1,p2,p3);
	}
	for(int i=1,p3,p1,p2;i<=6;++i){
		scanf("%d%d",&p1,&p2);
		++p1;++p2;p3=SPFA(p2,p1);
		add(p1,p2,-p3);
		printf("%d\n",-p3);
	}
	return;
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		memset(fr,0,sizeof(fr));
		tails=0;Work();
	}
	return 0;
}
