#include<bits/stdc++.h>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
#define MN 	300005 
int T,n,a[MN],b[MN],m[MN],tot;
bool check(int x)
{
	bool flag1=1,flag2=1;
	int last=0;
	so(i,1,n,1) 
	{
		if(a[i]<=m[x]) continue;
		if(a[i]<last) flag1=0;
		 last =  a[i];
	}
	last =0;
	so(i,1,n,1)
	{
		if(a[i]>=m[tot-x+1]) continue;
		if(a[i]<last) flag2=0;
		 last = a[i];
	} 
	
	return flag1||flag2;
}
int main()
{
	cin>>T;
	while(T--)
	{
		tot=0;
		cin>>n;so(i,1,n,1) cin>>a[i],b[i]=a[i];
		sort(b+1,b+1+n);so(i,1,n,1) if(b[i]!=b[i-1]) m[++tot]=b[i];
		m[tot+1]=n+1;
		//check(0);
		int l = 0, r = n;
		while(l<r)
		{
			int mid = l+(r-l)/2;
			if(check(mid)) r = mid;
			else l = mid+1;
		}
		cout<<r<<endl;
	}
}
