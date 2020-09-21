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
#define N 30000000
#define LL long long
LL sum[N+5];int T,n;
void init()
{
	so(i,1,N,1)
	{
		for(int j=i;j<=N-i;j+=i)
		{
			if(((i+j)^j)==i) sum[i+j]++;
		}
	}
	so(i,1,N,1) sum[i]+=sum[i-1];
}
int main()
{
	init();
	cin>>T;
	so(_,1,T,1)
	{
		cin>>n;
		cout<<"Case "<<_<<":"<<sum[n]<<endl;
	}
	return 0;

}

