#include<bits/stdc++.h>
using namespace std;
int T,n;long long x[1000];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		int last = x[1]%2;bool flag=0;
		for(int i=2;i<=n;i++)
		{
		//	cout<<x[i]<<" "<<last<<endl;
			if((x[i]%2)!=last) 
			{
				cout<<"NO"<<endl;	flag=1;
				break;
			
			}
		}
		if(flag==0) cout<<"YES"<<endl;
	}
} 
