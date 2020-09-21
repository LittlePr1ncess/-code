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
int main()
{
	int T,n;
	cin>>T;
	
	while(T--)
	{
		cin>>n;
		cout<<pow(2,n/2+1)-2<<endl;
	}
	return 0;

}

