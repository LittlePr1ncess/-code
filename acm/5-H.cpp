#include<iostream>
#include<cstdio>

#include<algorithm>

using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
#define LL long long
LL B,n,k,A,N;int a[100005];

/*LL f(int l,int r)
{
	int x=upper_bound(a+1,a+1+k,r)-lower_bound(a+1,a+1+k,l);
	if(x) return B*x*(r-l+1);
	else return A;
}*/
LL solve(int l,int r)
{
	LL ans;
	int x=upper_bound(a+1,a+1+k,r)-lower_bound(a+1,a+1+k,l);
	if(x) ans= B*x*(r-l+1);
	else return ans= A;int mid=(l+r)>>1;
	if(r-l>=1)
	ans=min(ans,solve(l,mid)+solve(mid+1,r));
	return ans;
}
int main()
{
	cin>>N>>k>>A>>B;
	
	LL n=1<<N;
	so(i,1,k,1) scanf("%d",&a[i]);
	//so(i,1,n,1) so(j,i,n,1) cout<<i<<" "<<j<<":"<<upper_bound(a+1,a+1+k,j)-lower_bound(a+1,a+1+k,i)<<" ";  
	sort(a+1,a+1+k);
	cout<<solve(1,n); 
	return 0;

}

