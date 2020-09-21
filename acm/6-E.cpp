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
using namespace std;
#define lb(x) x&-x
#define MN 100010
int n,b[MN],rk[MN],bt[MN],tot,lst[MN],T,ans=-210000000;
struct lll{
    int x,pos;
}a[MN];
int gmax(int pos)
{
    int ans=-2100000000;
    for(;pos<=tot;pos+=lb(pos))
    ans=max(ans,bt[pos]);
    return ans;
}
void upd(int pos,int data)
{
    for(;pos;pos-=lb(pos))
    if(bt[pos]<data) bt[pos]=data;
}
bool cmp(lll a,lll b)
{
    return a.x<b.x;
}
int main()
{
    while(cin>>n)
	{//while(~(scanf("%d",&a[++n].x)))b[n]=a[n].x;n--; 
	tot=T=0;
    so(i,1,n,1) cin>>a[i].x,b[i]=a[i].x;
    for(int i=1;i<=n;i++) a[i].pos=i;sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++) if(a[i].x!=a[i-1].x) rk[a[i].pos]=++tot;else rk[a[i].pos]=tot;
    for(int i=1;i<=n;i++) 
    {
        bt[rk[i]]=gmax(rk[i])+1;
        upd(rk[i],bt[rk[i]]);
    }
    for(int i=1;i<=n;i++) ans=max(ans,bt[i]);
   // cout<<ans;
    //for(int i=1;i<=n;i++) cout<<b[i]<<" ";
    for(int i=1;i<=n;i++)
    {
        int mm=210000000,wz;
        for(int j=1;j<=T;j++)
        if(lst[j]>=b[i]&&lst[j]<mm) mm=lst[j],wz=j;
        if(mm==210000000) lst[++T]=b[i]; 
        else lst[wz]=b[i];
    }
    cout<<T<<endl;}
}
/*
8 389 207 155 300 299 170 158 65
8 389 207 155 300 299 170 158 65
*/
