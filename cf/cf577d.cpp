#include<bits/stdc++.h>
using namespace std;
int n,k,a[200005];long long ans;
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	ans=a[n/2+1];
	for(int i=n/2+1;i<n;i++)
	{
		if(1ll*(i-(n/2))*(a[i+1]-a[i])<=k)
		ans=a[i+1],k-=1ll*(i-(n/2))*(a[i+1]-a[i]);
		else {
			ans=a[i]+k/(1ll*(i-(n/2)));k=0;break;
		}
	}
	if(k) ans+=k/(n/2ll+1ll);
	cout<<ans;
	return 0;
} 
