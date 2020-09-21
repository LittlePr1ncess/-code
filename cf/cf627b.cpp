#include<bits/stdc++.h>
using namespace std;
int n,T,a[5005];
bool check()
{
	for (int i=1;i<=n;i++)
	{
		for (int j=i+2;j<=n;j++)
		{
			if(a[j]==a[i]) return 1;
		}
		int con=0;
		for (int j=i+2;j<=n;j++)
		{
			if(con&&a[j]==a[i]) return 1;
			if(a[j]==a[j-1]) con=1;
 		}
	}
	return 0;
}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++) 
		{
			cin>>a[i];
		}
		if(check()) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
} 
