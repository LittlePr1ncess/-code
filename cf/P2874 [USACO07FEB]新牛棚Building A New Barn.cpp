#include<bits/stdc++.h>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
#define MN 20005
#define MM 20005
int n,x[MM],y[MM],dp[MN],dp2[MN],sum1[MN],sum2[MN],a[MN],b[MN],
Min=2100000000,Min2=2100000000,ans,ans2,cnt,cnt2,emm;
int main()
{
	cin>>n;
	so(i,1,n,1) cin>>x[i]>>y[i],x[i]+=10001,y[i]+=10001;
	so(i,1,n,1) a[x[i]]++,b[y[i]]++;
	so(i,1,20001,1) sum1[i]=sum1[i-1]+a[i],sum2[i]=sum2[i-1]+b[i];
	so(i,1,20001,1) dp[1]+=a[i]*(i-1);
	so(i,2,20001,1) dp[i]=dp[i-1]-(sum1[20001]-sum1[i-1])+sum1[i-1];
	so(i,1,20001,1) dp2[1]+=b[i]*(i-1);
	so(i,2,20001,1) dp2[i]=dp2[i-1]-(sum2[20001]-sum2[i-1])+sum2[i-1];
	so(i,1,20001,1) Min=min(Min,dp[i]),Min2=min(Min2,dp2[i]);
	so(i,10001,10010,1) cout<<dp2[i]<<endl;
	so(i,1,20001,1) 
	{
		if(dp[i]==Min)ans++;
		if(dp2[i]==Min2)ans2++;
	}
	so(i,1,n,1) if(dp[x[i]]==Min&&dp2[y[i]]==Min2) emm++;
	if((ans*ans2-emm)==0) emm-=2,Min+=1;
	cout<<Min+Min2<<" "<<ans*ans2-emm;
	return 0;
} 
