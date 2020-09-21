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
#define LL long long
#define MN 200005
LL n,x,a[MN*3],yr,sum[MN*3],sum2[MN*3],ans;
void work(LL i,LL t)
{
	LL ret=0;//cout<<i<<":"<<endl;
	if(sum2[i-1]+t>2*yr) ret+=sum[n]*(t/yr),t%=yr;
	//cout<<ret<<" ";
	LL tar=upper_bound(sum+1,sum+1+3*n,sum[i-1]+t)-sum;
	//cout<<tar<<"#";
	if(tar!=i)
	{
		ret+=sum2[tar-1]-sum2[i];
		//cout<<ret<<" ";
		t-=sum[tar-1]-sum[i];
		//cout<<"@"<<t;
		//int l=t/2; ret+=l
		LL l=t-a[tar];
		l=a[i]-l; 
		if(a[tar]>=a[i]&&t<=a[tar]) ret+=(t*(t+1)/2);
		else ret+=(a[tar]*(a[tar]+1)/2),ret+=a[i]*(a[i]+1)/2-l*(l+1)/2;
		//cout<<ret<<" ";
	}
	else
	ret+=a[i]*(a[i]+1)/2-(a[i]-t)*(a[i]-t+1)/2;
	//cout<<ret<<" ";
	ans=max(ans,ret);
}
int main()
{
	cin>>n>>x;
	so(i,1,n,1) cin>>a[i],a[i+n]=a[i],a[i+n+n]=a[i],yr+=a[i];
	so(i,1,3*n,1) sum2[i]=sum2[i-1]+a[i]*(a[i]+1)/2,sum[i]=sum[i-1]+a[i];
//	so(i,1,n,1) cout<<sum[i]<<" ";
	so(i,1,n,1){work(i,x);}
	cout<<ans<<endl;
	return 0;

}

