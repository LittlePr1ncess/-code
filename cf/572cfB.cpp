#include<bits/stdc++.h>
using namespace std;
int n,a[100005];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	if(a[n-1]+a[n-2]<=a[n]) 
	{
		cout<<"NO";
		return 0;
	}
	cout<<"YES"<<endl;
	for(int i=n;i>0;i-=2) cout<<a[i]<<" ";
	for(int i=n%2+1;i<=n;i+=2) cout<<a[i]<<" ";
	return 0;
} 
