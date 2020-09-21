#include<bits/stdc++.h>
using namespace std;
#define LL long long 
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
int T,a,b;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>a>>b;
		if(a<b) swap(a,b);
		cout<<(a-b)/5+((a-b)%5)/2+((a-b)%5)%2<<endl;
	}
} 
