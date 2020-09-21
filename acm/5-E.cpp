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
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1 
#define MN 200005
int n,m,Max[4*MN],x,y;char opt;
void update(int rt)
{Max[rt]=max(Max[rt<<1],Max[rt<<1|1]);}
void build(int l,int r,int rt)
{
	if(l==r) {scanf("%d",&Max[rt]);return;}
	int mid=(l+r)>>1;
	build(lson);build(rson);update(rt);
}
void change(int pos,int c,int l,int r,int rt)
{
	if(l==r) {
		Max[rt]=c;return ;
	}
	int mid=(l+r)>>1;
	if(pos<=mid) change(pos,c,lson);
	else change(pos,c,rson);
	update(rt);
}
int ask(int L,int R,int l,int r,int rt)
{
	if(l>=L&&r<=R) {
		return Max[rt];
	}
	int ret=0;
	int mid=(l+r)>>1;
	if(L<=mid)  ret=max(ask(L,R,lson),ret);
	if(mid<R)  ret=max(ask(L,R,rson),ret);
	return ret;
}
int main()
{
	while(cin>>n>>m)
	{
		build(1,n,1);
		so(i,1,m,1)
		{
			cin>>opt;scanf("%d%d",&x,&y);
			if(opt=='Q')
			{
				cout<<ask(x,y,1,n,1)<<endl;
			}
			else
			{
				change(x,y,1,n,1);
			}
		}
	}
	return 0;

}

