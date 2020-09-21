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
double x;int n,k,a[10005],ans;
bool check(int x)
{
	if(x==0) return 0;
	int sum=0;
	so(i,1,n,1) sum+=a[i]/x;
	return sum>=k;
}
int main()
{
	cin>>n>>k;
	int M=0;
	so(i,1,n,1) cin>>x,a[i]=100*x,M=max(M,a[i]);
	int l=0,r=M;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
		ans=mid,l=mid+1;
		else 
		r=mid-1;
	}
	x=ans*0.01;
	printf("%.2f",x);
	return 0;

}

