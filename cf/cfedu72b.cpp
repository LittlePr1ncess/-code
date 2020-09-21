#include<bits/stdc++.h>
using namespace std;
int T,x1,x2;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>x1>>x2;
		if(x2>2*x1){cout<<"NO"<<endl;continue;}
		if(x1>2*x2){cout<<"NO"<<endl;continue;}
		if((2*x1-x2)%3) {
			cout<<"NO"<<endl;continue;
		}
		if((2*x2-x1)%3) {
			cout<<"NO"<<endl;continue;
		}
		cout<<"YES"<<endl;
	}
	return 0;
} 
