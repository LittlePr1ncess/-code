#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	int T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++) if(a[i]!=a[i-1]) ans++;
		cout<<ans<<endl;
	}
} 
