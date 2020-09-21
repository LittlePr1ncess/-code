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
	int n,a,b;
	cin>>n;
	so(i,1,n,1) {
		cin>>a>>b;
		cout<<((a*b)+1)/2<<endl;
	} 
	return 0;

}

