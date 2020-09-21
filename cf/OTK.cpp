#include<bits/stdc++.h>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
int ans=0;
struct lll{
	int sp,x;
}a[100];
bool cmp( lll a, lll b)
{
	return a.x>b.x;
} 
int main() 
{
	int n,k,t;
	cin>>n>>k>>t;
	so(i,1,k+n,1) a[i].sp=0;
	so(i,1,k,1) a[i].sp=1;
	srand((unsigned )time(0));
	while(t--)
	{
		so(i,1,n+k,1) a[i].x=rand();
		sort(a+1,a+1+n+k,cmp);
		so(i,1,4,1) if(a[i].sp==1) {ans++;	break;}
		
	}
	cout<<ans<<" "<<t<<endl;
	cout<<(double)(ans*1.0)/(t*1.0);
	
}