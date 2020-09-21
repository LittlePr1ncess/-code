#include<bits/stdc++.h>
using namespace std ;
#define LL unsigned long long
LL n,k,a[100];
void work (LL x, LL k)
{
	//cout<<n<<" "<<k<<endl;
	if(x==0) return;
	if(k<a[x-1]) cout<<0,work(x-1,k);
	else cout<<1,work(x-1,a[x]-k-1);
}
int main()
{
	cin>>n>>k;
	a[0]=1;
	for(int i=1;i<=n;i++) a[i]=a[i-1]*2;
	work(n,k);
}
