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
#define eps 0.00000001 
#define db double
int p[15005],n;
db x[15005],l,r;
db f(db xx)
{
	db ret=0;
	so(i,1,n,1) ret+=((x[i]-xx>0)?(x[i]-xx):(xx-x[i]))*p[i];
	//cout<<xx<<" "<<ret<<endl;
	return ret; 
}
int main()
{
	cin>>n;int M=0;
	so(i,1,n,1) cin>>x[i]>>p[i],M=max(M,p[i]);
	l=-1.0,r=50005.0;
	//cout<<l<<" "<<r<<endl;
	while(r-l>=eps)
	{
		//cout<<l<<" "<<r<<endl;
		db s1=(l+r)/2,s2=(s1+r)/2;
		if(f(s1)<f(s2)) r=s2;
		else l=s1; 
		//cout<<f(s1)<<" "<<f(s2)<<endl;
		//cout<<l<<" "<<r<<endl;
	}
	cout<<f(l);
	printf("%.5lf",l);
	return 0;

}

