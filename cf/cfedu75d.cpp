#include<bits/stdc++.h>
using namespace std;
#define so(i,j,k,l) for(register int i=j;i<=k;i+=l)
#define LL long long
#define MN 200005
int T,n;LL anss,ans,tot,cnt,cnt2,r[MN],l[MN],s;bool b[MN],b2[MN];
struct lll{
	int pos;LL l;
}a[MN];
bool cmp(lll a,lll b)
{
	return a.l<b.l;
}
bool check(LL x)
{
	memset(b,0,sizeof(b));
	memset(b2,0,sizeof(b2));
	tot=cnt=cnt2=ans=0;
	so(i,1,n,1) 
	{
		if(r[i]>=x) cnt++;
		else b[i]=1,cnt2++,ans+=l[i];
		if(r[i]>=x&&l[i]<=x) b2[i]=1;
		//a[++tot].l=l[i],a[tot].pos=i;
	}
	if(cnt<n/2) return 0;
	int rwz=0;
	so(i,1,n,1) {if(rwz+cnt2>n/2) break;if(b2[i]) ans+=a[i].l,rwz++;}
	ans+=x*(n/2+1);
	return ans<=s; 
}

int main()
{
	cin>>T;
	while(T--)
	{
		scanf("%d%lld",&n,&s);
		so(i,1,n,1) scanf("%lld%lld",&l[i],&r[i]),a[i].l=l[i],a[i].pos=i;
		LL L=0,R=s;sort(a+1,a+1+n,cmp);
		while(L<R)
		{
			LL mid=(R+L+1)>>1;
			if(check(mid)) 
			L=mid;
			else R=mid-1;
		}
		printf("%lld\n",L);
	}
} 
