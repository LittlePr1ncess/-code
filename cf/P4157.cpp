#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL n,M=-2100000000;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		LL ans=1;
		LL x=(n/i);LL y=n%i;
		//cout<<x<<" "<<y<<endl;
		for(int j=1;j<=y;j++) ans*=(x+1);
		//cout<<"A"<<ans<<endl; 
		for(int j=y+1;j<=i;j++) ans*=x;
		//cout<<"A"<<ans<<endl;
		M=max(ans,M);
	}
	LL xx=M,ans2=0;
	while(xx)
	{
		xx/=10;ans2++;
	}
	cout<<ans2<<endl<<M;
} 
