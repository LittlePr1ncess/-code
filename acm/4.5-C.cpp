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
	int n,x,y,a,b,c,d;
	cin>>n;
	cin>>x>>y;cin>>a>>b>>c>>d;
	if((a-x)*(c-x)>0&&(b-y)*(d-y)>0) cout<<"YES";
	else cout<<"NO";
	
	return 0;

}

