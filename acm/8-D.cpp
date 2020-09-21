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
#define MN 105
#define db double 
struct lll{
	db l;int p1,p2;
}e[MN*MN];
bool cmp(lll a,lll b)
{
	return a.l<b.l;
}
int fa[MN];
int find(int x)
{
	return (x==fa[x])?x:fa[x]=find(fa[x]);
}
int n;db x[MN],y[MN],z[MN],r[MN];
int main()
{
	while(cin>>n)
	{
		if(!n) break;
		int tot=0;db ans=0;so(i,1,n,1) fa[i]=i;
		so(i,1,n,1) cin>>x[i]>>y[i]>>z[i]>>r[i];
		so(i,1,n,1) so(j,i+1,n,1) 
		{
			db a=x[i]-x[j],b=y[i]-y[j],c=z[i]-z[j];
			e[++tot].l=sqrt(a*a+b*b+c*c)-r[i]-r[j];
			e[tot].p1=i,e[tot].p2=j;
		} 
		sort(e+1,e+1+tot,cmp);
		so(i,1,tot,1)
		{
			if(find(e[i].p1)==find(e[i].p2)) continue;
			fa[find(e[i].p1)]=find(e[i].p2);
			if(e[i].l>0) ans+=e[i].l;	
		}
		printf("%.3f\n",ans);
	} 
	return 0;

}

