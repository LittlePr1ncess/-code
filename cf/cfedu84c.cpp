#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y;
int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++) cin>>x>>y;
	 for(int i=1;i<=k;i++) cin>>x>>y;
	cout<<n+m-3+n*m<<endl;
	for(int i=1;i<m;i++)
	{
		cout<<"L";
	}
	for(int i=1;i<n;i++)
	{
		cout<<"U";
	}
	int con=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<m;j++)
		{
			if(con) cout<<"L";
			else cout<<"R";
		}
		if(i!=n)cout<<"D";
		con^=1;
	}
} 
