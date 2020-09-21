#include<bits/stdc++.h>
using namespace std;
#define LL long long
int n,a[200005],l,r,k,mx;
bool check(int x)
{
	LL ans=0;int tot =0;
	for(int i=n;i;i--)
	{
		if(a[i]<x) ans+=x-a[i]; 
		if(ans>k) return 0;tot++;
		if(tot>n/2) return 1;
	}
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),mx=max(mx,a[i]);
	sort(a+1,a+1+n);
	l=a[(n+1)/2],r=mx+k;
	while(l<r)
	{
		int mid=(l+r+1)/2;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
