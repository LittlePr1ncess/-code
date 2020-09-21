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
#define LL long long
#define db double
int main()
{
	LL n,k;
	cin>>n>>k;
	k--;n--;
	LL N=k*(k+1)/2;
	if(n>N){
		cout<<"-1";return 0;
	} 
	LL x=sqrt(2*N-2*n+0.25)+0.5;
	while(n-(N-x*(x+1)/2)>x) x-=1;
	LL rwz=2*n-2*N+x*x+x;
	LL ans=k-x+((2*n-2*N+x*x+x)!=0);
	cout<<ans;
	return 0;

}

