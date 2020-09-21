#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL c,sum;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		LL ans=0;
		cin>>c>>sum;
		LL rwz=sum/c;
		ans=rwz*rwz*c;
		ans-=rwz*rwz*(sum%c);
		ans+=(rwz+1)*(rwz+1)*(sum%c);
		cout<<ans<<endl;
	}
	return 0;
} 
