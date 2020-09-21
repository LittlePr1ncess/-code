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
#define MN 200005
int T,n,k,a[MN],b[MN],sum[MN],ans,wz;
int main()
{
	cin>>T;
	while(T--)
	{
		ans=0;
		cin>>n>>k;
		//a[n+1]=0;sum[n+1]=0;b[n+1]=0;
		so(i,1,n,1) cin>>a[i];
		so(i,1,n,1) if((a[i]>a[i-1])&&(a[i]>a[i+1])) b[i]=1;else b[i]=0;
		b[1]=b[n]=0;
		so(i,1,n,1) sum[i]=sum[i-1]+b[i];
		//so(i,1,n,1) cout<<b[i]<<" ";cout<<endl;
		//so(i,1,n,1) cout<<sum[i]<<" ";cout<<endl;
		so(i,1,n-k+1,1) if(sum[i+k-2]-sum[i]>ans) ans=sum[i+k-2]-sum[i],wz=i;
		so(i,1,n,1) a[i]=b[i]=sum[i]=0;
		if(ans)
		cout<<ans+1<<" "<<wz<<endl;
		else cout<<1<<" "<<1<<endl;
	}
	return 0;

}

