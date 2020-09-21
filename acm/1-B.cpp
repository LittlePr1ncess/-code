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
int T;
int work(int x)
{
	LL ans=0;
	so(i,2,sqrt(x),1)
	{
		if(x%i==0) ans+=i,ans+=x/i;
	}
	return ans;
	
}
int main()
{
	cin>>T;
	while(T--)
	{
		int a,b;cin>>a>>b;
		//cout<<work(a)<<" "<<work(b)<<endl;
		if((a==work(b)+1)&&(b==1+work(a))) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
	
}
