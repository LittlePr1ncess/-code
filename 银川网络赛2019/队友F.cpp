#include<bits/stdc++.h>
using namespace std;
struct City{int num,dang;}c[217];
int Map[217][217],n,m,dis[217][217];
struct Query{int top,num,ans,u,v;}q[31234];
bool comp1(City a,City b){
	return a.dang<b.dang;
}
bool comp2(Query a,Query b){
	return a.top<b.top;
}
bool comp3(Query a,Query b){
	return a.num<b.num;
}
void Work(int cnum){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",&c[i].dang);
		c[i].num=i;
	}
	sort(c+1,c+n+1,comp1);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			scanf("%d",&Map[i][j]);
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&q[i].u,&q[i].v,&q[i].top);
		q[i].num=i;
	}
	sort(q+1,q+m+1,comp2);
	for(int i=1,topd,j=1;i<=m;++i){
		topd=q[i].top;
		for(int o=c[j].num;j<=n and c[j].dang<=topd;++j){
			for(int k=1;k<=n;++k)
				for(int l=1;l<k;++l)
					if(Map[k][l]>Map[k][o]+Map[o][l])
						Map[l][k]=Map[k][l]=
							Map[k][o]+Map[o][l];
		}
		q[i].ans=Map[q[i].u][q[i].v];
	}
	sort(q+1,q+m+1,comp3);
	printf("Case #%d:\n",cnum);
	for(int i=1;i<=m;++i)
		printf("%d\n",q[i].ans);
}
int main(){
	freopen("a.txt","r",stdin); 
	int T;scanf("%d",&T);
	for(int i=1;i<=T;++i)
		Work(i);
	return 0;
}
