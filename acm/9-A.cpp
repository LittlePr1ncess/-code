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
#define N 10000
#define MN 10005
int ispp[MN],tot,pp[MN],n;
void OLS()
{
	so(i,1,N,1) ispp[i]=1;
	so(i,2,N,1)
	{
		if(ispp[i]) pp[++tot]=i;
		so(j,1,tot,1)
		{
			if(i*pp[j]>N) break;
			ispp[i*pp[j]]=0;
			if(i%pp[j]==0) break;
		}
	}
	ispp[1]=0;
}
int main()
{
	OLS(); 
	cout<<check(100000000000007);
	while(cin>>n)
	{
		for(int i=n/2;i>=2;i--)
		{
			if(ispp[i]&&ispp[n-i]) {
				cout<<i<<" "<<n-i<<endl;break;
			}
		}
	} 
	return 0;

}

