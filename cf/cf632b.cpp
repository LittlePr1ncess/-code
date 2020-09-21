#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
#define MN 100005
int T,n,a[MN],b[MN],c[5];
bool check()
{
	c[1]=c[0]=0;
	so(i,1,n,1)
	{
		if(((b[i]-a[i])>0)&&c[1]==0)	return 0;
		if(((b[i]-a[i])<0)&&c[0]==0)	return 0;
		if(a[i]==1) c[1]=1;
		if(a[i]==-1) c[0]=1;
	}
	return 1;
}

int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n;
		so(i,1,n,1) cin>>a[i];
		so(i,1,n,1) cin>>b[i];
		if(check()) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
	}
} 
