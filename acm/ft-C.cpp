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
int a,b,c,d;
bool check()
{
	if(a!=d) return 0;
	if(c&&(!a))return 0;
	return 1;
}
int main()
{
	cin>>a>>b>>c>>d;
	cout<<check()<<endl;
	return 0;

}

