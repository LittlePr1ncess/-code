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
#define MN 100005
int n;
LL x[MN],ans;
bool check(LL k)
{
	LL sum=0;
	so(i,1,n,1)
	sum+=n-(lower_bound(x+i,x+1+n,x[i]+k)-x)+1;
	//cout<<k<<" "<<sum<<endl;
	return sum>=(n-1)*n/4+1;
}
int main()
{
	while(~scanf("%d",&n))
	{
		LL M=0,Mi=1<<31;
		so(i,1,n,1) scanf("%lld",&x[i]),M=max(M,x[i]),Mi=min(Mi,x[i]);
		sort(x+1,x+1+n);
		LL l=0;LL r=M;
		while(l<=r)
		{
			LL mid=(l+r)>>1;
			if(check(mid))
			ans=mid,l=mid+1;
			else r=mid-1;
		}
		cout<<ans<<endl;
	}
	return 0;

}

