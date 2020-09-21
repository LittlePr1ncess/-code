#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<cmath>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
#define MN 100005
int T,n,a[MN]; 
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n;
		int ans=0;
		so(i,1,n,1) cin>>a[i];sort(a+1,1+a+n);
		//so(i,1,n,1) cout<<a[i]<<" ";cout<<endl;
		so(i,1,n,1)
		if(i-a[i]>=0)
		{
			ans=i;
			//cout<<i+1<<endl;break;
		}
		if(!ans) cout<<1<<endl;
		else cout<<ans+1<<endl;
	}
	return 0;

}

