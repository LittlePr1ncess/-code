#include<bits/stdc++.h>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
int n,m,a[100005],ans[100005],aa[100005];
bool work(int l,int x,int rwz)
{
	if(x==1)
	{
		if(l>=1) {
			ans[x]=1;return 1;
		}
		else return 0;
	}
	if(a[x]>rwz+l) return 0;
	
	ans[x]=l-a[x]+1;
	if(a[x-1]>rwz+a[x]+l) return 0;
	a[x-1]-=a[x]+rwz;
	if(a[x-1]<1) a[x-1]=1;
	return work(l-a[x],x-1,rwz+a[x]);
	
}
int main() {
	cin>>n>>m;
	so(i,1,m,1) cin>>a[i],aa[i]=a[i];
	int sum=0;
	so(i,1,m,1) sum+=a[i];
	if(sum<n||!work(n,m,0))
	{
		cout<<-1<<endl;
	}
	else{
		//so(i,1,m,1)
		//cout<<ans[i]<<" ";
		aa[0]=1;
		so(i,1,m,1) {
			if(ans[i-1]+aa[i-1]<ans[i]) ans[i]=ans[i-1]+aa[i-1];
		}
		so(i,1,m,1)
		cout<<ans[i]<<" ";
	}
}
