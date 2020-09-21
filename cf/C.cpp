#include<bits/stdc++.h>
using namespace std;
#define p 1000000007
#define LL long long
struct lll{
	LL a[3][3];
};
lll mul( lll a,lll b)
{
	lll ans;
	for(int i=1;i<=2;i++)
	 for(int j=1;j<=2;j++)
	 {
	 	ans.a[i][j]=0;
	 	for (int k=1;k<=2;k++)
	   	ans.a[i][j]+=(a.a[i][k]*b.a[k][j])%p,ans.a[i][j]%=p;
	 }
	return ans;
}
int main()
{
	LL k;
	cin>>k;k--;
	lll ans;ans.a[1][1]=ans.a[2][2]=1,ans.a[1][2]=ans.a[2][1]=0;
	lll zz;zz.a[1][2]=zz.a[2][1]=zz.a[2][2]=1,zz.a[1][1]=0;
	for(;k;k>>=1,zz=mul(zz,zz))
	if(k&1) ans=mul(ans,zz);
	LL outt=(ans.a[1][1]+ans.a[1][2])%p;
	cout<<outt<<endl;
}
