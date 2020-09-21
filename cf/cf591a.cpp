#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		if(n==2) {
			cout<<2<<endl;continue;
		}
		cout<<n%2<<endl;
	}
	return 0;
} 
