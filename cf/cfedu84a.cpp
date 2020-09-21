#include<bits/stdc++.h>
using namespace std;
long long T,n,k,rwz;
int main()
{
	
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		rwz=n-k*k;
		if((rwz>=0)&&((rwz%2)==0)) 
		cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
} 
