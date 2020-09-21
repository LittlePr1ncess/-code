#include<bits/stdc++.h>
using namespace std;
int n,a[105],t[2];
int main()
{
	cout<<"test";
	cin>>n;char ha=getchar();
	for(int i=1;i<=n;i++) 
	{
		char ha=getchar();
		a[i]=ha-'0';
		t[a[i]]++;
	}
	if(t[1]!=t[0]) 
	{
		cout<<1<<endl;
		for(int i=1;i<=n;i++) cout<<a[i];
	}
	else 
	{
		cout<<2<<endl;
		for(int i=1;i<n;i++) cout<<a[i];
		cout <<" "<<a[n];
	}
	return  0;
}
