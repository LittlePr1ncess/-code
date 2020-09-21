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
#define db double
int n,k;db a[10005];
bool check (db x)
{
	int sum=0;
	if(x<0.01) return 0;
	so(i,1,n,1) sum+=int(a[i]/x);
	if(sum>=k) return 1;
	return 0;
}
int main()
{
	cin>>n>>k;
	db M=0;
	so(i,1,n,1) cin>>a[i],M=max(M,a[i]);
	db l=0.01,r=M;
	while(r-l>=0.0001)
	{
		db mid=(l+r)/2;
		if(check(mid)) l=mid;
		else r=mid;
	} 
	l*=100;int ww=l;
	l=ww*0.01;
	if(check(l))
	printf("%.2lf",l);
	else 
	cout<<"0.00";
	return 0;

}

