#include<bits/stdc++.h>
using namespace std;
#define MN 200005
int n;
long long a[MN],b[MN],A[MN],B[MN],ans;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++) A[i]=a[i]-b[i];
	for (int i=1;i<=n;i++) B[i]=b[i]-a[i];
	sort(B+1,B+1+n);
	for(int i=1;i<=n;i++)
	{
		ans+=(lower_bound(B+1,B+1+n,A[i])-B)-1;
		if(A[i]>0) ans-=1;
	}
	cout<<ans/2;
} 
