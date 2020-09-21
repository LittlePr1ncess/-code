#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define so(i,j,k,l) for(int i=j;i<=k;i+=l) 
int gcd (int a,int b)
{
	return b?gcd(b,a%b):a;
}
int T,a,b;
int main()

{
	cin>>T;
	while(T--)
	{
		cin>>a>>b;if(a<b) swap(a,b);
		cout<<((gcd(a,b)==1)?("Finite"):("Infinite"));
	}
}
 
