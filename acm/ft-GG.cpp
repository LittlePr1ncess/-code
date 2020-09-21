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
#define lson rt<<1
#define rson rt<<1|1
#define N 50005
int n,m,a[N],opt,x,y;
struct lll {
    int ll,rr,maxx,sum;
}t[N<<2];

void update(int rt) 
{
    lll L=t[lson],R=t[rson];
    t[rt].sum=L.sum+R.sum;
    t[rt].ll=max(L.ll,L.sum+R.ll);
    t[rt].rr=max(R.rr,R.sum+L.rr);
    t[rt].maxx=max(L.rr+R.ll,max(L.maxx,R.maxx));
}

void build(int rt,int l,int r) 
{
    if(l==r) {
        t[rt].ll=t[rt].rr=t[rt].maxx=t[rt].sum=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(lson,l,mid);build(rson,mid+1,r);update(rt);
}
void change(int x,int rt,int l,int r,int val) 
{
    if(l==r) 
	{t[rt].ll=t[rt].rr=t[rt].maxx=t[rt].sum=val;return;}
    int mid=(l+r)>>1;
    if(x<=mid) change(x,lson,l,mid,val);
    else change(x,rson,mid+1,r,val);
    update(rt);
}
lll ask(int x,int y,int rt,int l,int r) 
{
    if(x<=l&&r<=y) return t[rt];
    int mid=(l+r)>>1;
    if(y<=mid) return ask(x,y,lson,l,mid);
    if(mid<x) return ask(x,y,rson,mid+1,r);
    lll L=ask(x,mid,lson,l,mid),R=ask(mid+1,y,rson,mid+1,r),maxx;
    maxx.sum=L.sum+R.sum;maxx.ll=max(L.ll,L.sum+R.ll);
    maxx.rr=max(R.rr,R.sum+L.rr);maxx.maxx=max(L.rr+R.ll,max(L.maxx,R.maxx));
    return maxx;
}
int main() 
{
   	cin>>n;so(i,1,n,1) cin>>a[i];
    build(1,1,n);
    cin>>m;
    while(m--)
    {
        cin>>opt>>x>>y;
        if(opt==1) cout<<ask(x,y,1,1,n).maxx<<endl;
        else change(x,1,1,n,y);
    }
    return 0;
}
