#include<bits/stdc++.h>
using namespace std;
int n,l,r;
int main()
{
	cin>>n>>l>>r;
	cout<<(int )(pow(2,l)-1+n-l)<<" "<<(int)(pow(2,r)-1+pow(2,r-1)*(n-r));
}
