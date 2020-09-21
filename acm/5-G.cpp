#include<iostream>
#include<cstdio>





#include<cmath>
using namespace std;
#define so(i,j,k,l) for(register int i=j;i<=k;i+=l)
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define MN 100005
#define LL long long
int n,k;LL sum[MN*4];int T,opt,x,y;
inline void read(long long &x)
{
    x=0; int f=1; char c=getchar();
    while(c<'0'|| c>'9')  { if(c=='-') f=-1; c=getchar(); }
    while(c>='0' && c<='9') { x=x*10+c-'0'; c=getchar(); }
    x*=f;
}
inline void update(int rt)
{sum[rt]=sum[rt<<1]+sum[rt<<1|1];}
inline void build(int l,int r,int rt)
{
	if(l==r) {read(sum[rt]);return ;}
	int mid=(l+r)>>1;
	build(lson);build(rson);update(rt);
}
inline void change(int L,int R,int l,int r,int rt)
{
	if(sum[rt]==r-l+1) return;
	if(l==r) {sum[rt]=sqrt(sum[rt]);return ;}
	int mid=(l+r)>>1;
	if(L<=mid) change(L,R,lson);
	if(R>mid) change(L,R,rson);
	update(rt);
}
inline LL ask(int L,int R,int l,int r,int rt)
{
	if(L<=l&&r<=R)return sum[rt];
	int mid=(l+r)>>1;
	LL ret=0;
	if(L<=mid) ret+=ask(L,R,lson);
	if(mid<R)  ret+=ask(L,R,rson);
	return ret;
	
}
int main()
{
	//freopen("a.txt","w",stdout);
	while(~scanf("%d",&n)) 
	{
		T++;
		printf("Case #%d:\n",T);
		
		build(1,n,1);
		//so(i,1,10,1) cout<<sum[i]<<" ";
		scanf("%d",&k);
		so(i,1,k,1)
		{
			scanf("%d%d%d",&opt,&x,&y);
			if(x>y) swap(x,y);
			if(opt==0) change(x,y,1,n,1);
			else printf("%lld\n",ask(x,y,1,n,1) );
		}
		cout<<endl;
	}
	return 0;

}

