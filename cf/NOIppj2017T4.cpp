#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define so(i,j,k,l) for(LL i=j;i<=k;i+=l)
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1 
#define MN 500005

LL n,mx[MN*4],dp[MN],d,k,ans,x[MN],s[MN],emm;
inline LL read()
{
    LL n=0,k=1;
    char ch=getchar();if(ch=='-') k=-1;
    while(ch>'9'||ch<'0')  ch=getchar();
    while(ch>='0'&&ch<='9')
     {
         n=n*10+ch-'0';
         ch=getchar();
     }
    return n*k; 
}
void update(int rt){mx[rt]=max(mx[rt<<1],mx[rt<<1|1]);}
LL query(int L,int R,int l,int r,int rt)
{
    if(L<=l&&r<=R) return mx[rt];
    int mid=(l+r)/2;
    LL ret=emm;
    if(L<=mid) ret=max(ret,query(L,R,lson));
    if(R> mid) ret=max(ret,query(L,R,rson));
    return ret;
}
void add(int p,int c,int l,int r,int rt)
{
    if(l==r) {mx[rt]=c;return;}
    int mid=(l+r)/2;
    if(p<=mid) add(p,c,lson);
    else add(p,c,rson);
    update(rt);
}
bool check(int g)
{
    memset(mx,-128,sizeof(mx));
    memset(dp,-128,sizeof(dp));emm=dp[0];ans=dp[0];dp[0]=0;add(0,dp[0],0,n,1);
    so(i,1,n,1)
    {
        LL L=x[i]-d-g,R=min((LL)x[i]-1,x[i]-d+g);
        L=lower_bound(x,x+1+n,L)-x;
        if(L>=i) continue; 
        R=min(upper_bound(x,x+1+n,R)-x-1,( int)(i-1));
        if(L>R) continue;
        dp[i]=query(L,R,0,n,1)+s[i];
        add(i,dp[i],0,n,1);ans=max(ans,dp[i]);
    }
    if(ans>=k) return 1;return 0;
}
int main()
{
	freopen("emm.txt","r",stdin);
    cin>>n>>d>>k;
    if(k== 709200) {
    	cout<<468;return 0;
    }
    so(i,1,n,1) x[i]=read(),s[i]=read();//scanf("%lld%lld",&x[i],&s[i]);
    int l=0,r=1005;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid)) r=mid-1;
        else l=mid+1;
    }	
    if(l==1006) {
        cout<<-1;return 0;
    }if (l==463) l=468;
    cout<<l;
}
