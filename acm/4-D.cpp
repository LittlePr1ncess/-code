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
int pp[30]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int n,x,y,ans,a[200005];
int M=2100000000,MM=0,S;
int main()
{
	cin>>n;
	so(i,1,n,1) cin>>a[i],M=min(M,a[i]),S+=a[i];
	so(i,1,n,1) so(k,2,sqrt(a[i]),1)
	{
		if(a[i]%k) continue;
		x=a[i]/k;MM=max(MM,(x-1)*(k-M));MM=max(MM,(k-1)*(x-M));
	}
	cout<<S-MM; 
	return 0;

}

