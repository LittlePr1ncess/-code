#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<cmath>
using namespace std;
#define so(i,j,k,l) for(LL i=j;i<=k;i+=l)
#define LL long long
int T;LL n;

LL mul(LL a,LL b)
{
	LL ans=0,aa=a;
	for(;b;b>>=1)
	{
		if(b&1) ans=(ans+aa)%n;
		aa=(aa+aa)%n;
	}
	return ans;
}
LL ksm(LL a,LL b)
{
	LL ans=1,aa=a;
	for(;b;b>>=1)
	{
		if(b&1) ans=mul(ans,aa);
		aa=mul(aa,aa);
	}
	return ans;
}
void solve (LL p)
{
	//cout<<"########";
	LL ans=1;
	so(i,p+1,n-2,1) ans=mul(ans,i);
	
	//cout<<"####";
	cout<<ksm(ans,n-2)<<endl;
}
bool check(LL num)
{
	if(num ==2|| num==3 )return 1 ;
	if(num %6!= 1&&num %6!= 5)return 0 ;
    LL tmp =sqrt( num);
    for(LL i= 5;i <=tmp; i+=6 )
    if(num %i== 0||num %(i+ 2)==0 )return 0 ;
    return 1 ;
}
int main()
{
	//for(LL i=100000000000000;i;i--)if(check(i)) {cout<<i;break;}
	cin>>T;
	while(T--)
	{
		scanf("%lld",&n);
		for(LL i=n-1;i;i--)
		{
			//cout<<i;
			if(check(i)){
				//cout<<i;
				solve(i);break;
			}
		}
	}
	return 0;

}
/*
1
99999999999973
*/

