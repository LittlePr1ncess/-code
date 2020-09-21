#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define MN 400005
int n,I,a[MN],L,R,len,ans=2100000000,K,tot,cost[MN],sum[MN],cost2[MN],sum2[MN]; 
int main()
{
	cin>>n>>I;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	I*=8;I/=n;
	//cout<<I<<endl;
	sort(a+1,a+1+n);sum[0]=sum2[0]=-1;
	for(int i=1;i<=n;i++) 
	{
		if(a[i]!=a[i-1]||i==1) K++,cost[K]=cost[K-1]+len,len=1,sum[K]=sum[K-1]+1;
		else len++;
	}
	len=0;
	for(int i=n;i>=1;i--)
	{
		if(a[i]!=a[i+1]||i==n) tot++,cost2[tot]=cost2[tot-1]+len,len=1,sum2[tot]=sum2[tot-1]+1;
		else len++;
	}
	//for(int i=1;i<=K;i++) cout<<sum[i]<<" "<<cost[i]<<endl;
	 //for(int i=1;i<=tot;i++) cout<<sum2[i]<<" "<<cost2[i]<<endl;
	 sum[0]=sum2[0]=0; 
	for(int i=1;i<=K;i++) 
	{
		L=1,R=tot;
		while(L<R)
		{
			int mid=(L+R)/2;
			if(K-sum[i]-sum2[mid]<=0||ceil(log2(K-sum[i]-sum2[mid]))<=I) R=mid;
			else L=mid+1;
		}
		ans=min(ans,cost[i]+cost2[L]);
	}
	cout<<ans;
	return 0;
} 
