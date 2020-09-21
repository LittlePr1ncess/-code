#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL a[100005];int n,x,y;
int main()
{
	cin>>n>>x>>y;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		bool flag=0;
		for(int j=max(1,i-x);j<=min(n,i+y);j++)
		{
			if(a[i]>=a[j]&&i!=j) flag=1;
		}
		if(flag==0) {
			cout<<i;break;
		}
	}
	return 0;
} 
