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
#define eps 1e-6
#define MN 15005
#define db double
int n;
db a[MN],w[MN];
db f(db x)
{
	db ans=0;
	so(i,1,n,1) ans+=fabs(x-a[i])*w[i];
	return ans;
}
int main()
{
	cin>>n;db M=0;
	so(i,1,n,1) cin>>a[i]>>w[i],M=max(M,a[i]);
	db r=M,l=0;
	while(r-l>=eps)
	{
		db s1=(l*2+r)/3,s2=(l+2*r)/3;
		if(f(s1)>f(s2)) l=s1;
		else r=s2;
	}
	//cout<<f(r);
	printf("%.5f",r);
	return 0;

}

