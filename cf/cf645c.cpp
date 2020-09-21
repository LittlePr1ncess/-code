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
long long a,b,c,d;
int T;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>a>>b>>c>>d;
		cout<<(c-a)*(d-b)+1<<endl;
	}
	return 0;

}

