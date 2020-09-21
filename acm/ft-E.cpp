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
	int x,y;db l;
}a[MN*MN];
int n;db x[MN],y[MN],z[MN],r[MN];int fa[MN];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
bool cmp( lll a,lll b)
{
	return a.l<b.l;
}
int main()
{
	while(cin>>n)
	{
		if(!n) break;
		db ans=0;int tot=0;
		so(i,1,n,1) fa[i]=i;
		so(i,1,n,1) cin>>x[i]>>y[i]>>z[i]>>r[i];
		so(i,1,n,1) so(j,i+1,n,1) 
		{	
			a[++tot].x=i,a[tot].y=j;
			db xx=(x[i]-x[j]),yy=y[i]-y[j],zz=z[i]-z[j];
			if(xx*xx+yy*yy+zz*zz>=(r[i]+r[j])*(r[i]+r[j])) 
			//a[tot].l=sqrt(xx*xx+yy*yy+zz*zz);
			a[tot].l=sqrt(xx*xx+yy*yy+zz*zz)-r[i]-r[j];
			else a[tot].l=0;
		}
		sort(a+1,a+1+tot,cmp);
		so(i,1,tot,1) {
			if(find(a[i].x)==find(a[i].y)) continue;
			ans+=a[i].l;
			fa[find(a[i].x)]=find(a[i].y);
		}
		printf("%.3f\n",ans);
	}
	return 0;

}

