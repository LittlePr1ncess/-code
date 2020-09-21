#include<bits/stdc++.h>
using namespace std;
int n,a[200005],X=-1,x,opt,p,q,mx[200005],wr[200005];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cin>>q;
	for(int i=1;i<=q;i++)
	{ 
		cin>>opt;
		if(opt==2) cin>>x,mx[i]=x; 
		if(opt==1)
		{
			cin>>p>>x;
			a[p]=x;wr[p]=i;
		}
	}
	for(int i=q;i>=1;i--)
	{
		mx[i]=max(mx[i],mx[i+1]);
	}
	for(int i=1;i<=n;i++) cout<<max(a[i],mx[wr[i]+1])<<" ";
	//cout<<endl;for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	return 0;
}
