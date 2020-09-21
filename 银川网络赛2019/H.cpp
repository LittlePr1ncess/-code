#include<bits/stdc++.h>
using namespace std;
#define MN 100005
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
#define LL long long
struct lll{
	int atk,t;
}a[MN];
LL T,n,h[MN],sum,ans;
bool cmp(lll a,lll b)
{
	return a.atk*b.t>b.atk*a.t;
}
int main()
{
	cin>>T;
	so(ha,1,T,1)
	{
		ans=sum=0;
		cin>>n;
		so(i,1,n,1) cin>>h[i]>>a[i].atk;
		so(i,1,n,1) so(j,1,1e5,1) {if(j*(j+1)/2>=h[i]) {a[i].t=j;break;}}
		//so(i,1,n,1) cout<<a[i].atk<<" "<<a[i].t<<endl;
		sort(a+1,a+1+n,cmp);
		//so(i,1,n,1) cout<<a[i].atk<<" "<<a[i].t<<endl;
		so(i,1,n,1)
		{
			sum+=a[i].t;
			ans+=a[i].atk*sum;
		}
		cout<<"Case #"<<ha<<": "<<ans<<endl;
	}
	
	return 0;
} 
