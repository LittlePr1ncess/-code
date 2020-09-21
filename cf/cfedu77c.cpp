#include<bits/stdc++.h>
using namespace std;
#define LL long long 
LL T,M,m,k;
LL gcd(LL a,LL b)
{
	return b?gcd(b,a%b):a; 
} 
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>M>>m>>k;
		if(M<m) swap(M,m);
		LL lc = M/gcd(M,m)*m;
		if(((lc/m-1+lc/M-1)/(lc/M))>=k) 
		{
			cout<<"REBEL"<<endl;
		}
		else cout<<"OBEY"<<endl;
	} 
	return 0;
} 
