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
int T,a,b,c,d,n,l,r;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n>>a>>b>>c>>d;
		l=n*(a-b);r=n*(a+b);
		if(l>c+d||r<c-d) {
			cout<<"No"<<endl;
		}
		else cout<<"Yes"<<endl;
	} 
	return 0;

}

