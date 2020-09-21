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
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==d)
	{
		if(c>0)
		{
			if(a>0) cout<<1;
			else cout<<0;
		}
		else cout<<1;
	}
	else cout<<0;
	return 0;

}

