#include<bits/stdc++.h>
using namespace std;
struct lll{
	int v,t;
}a[100005];
int n;long long ans,tot;
bool cmp(lll a,lll b)

{
	return a.v*a.t+(a.t+b.t)*(b.v)<b.v*b.t+(b.t+a.t)*a.v;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].v>>a[i].t;
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		tot+=a[i].t;
		ans+=a[i].v*tot;
	}
	cout<<ans;
} 
