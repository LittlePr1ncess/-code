#include<bits/stdc++.h>
using namespace std;
#define pi 3.1415926535897
#define db double 
#define MN 105
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
struct lll{
	int x,y;db r;
}a[MN];
bool cmp(lll a,lll b)
{
	return a.r>b.r;
}
int n,x[MN],y[MN];db ans=0,r[MN];
int main()
{
	cin>>n;
	so(i,1,n,1) cin>>a[i].x>>a[i].y>>a[i].r;
	sort(a+1,a+1+n,cmp);
	so(i,1,n,1) x[i]=a[i].x,y[i]=a[i].y,r[i]=a[i].r;
	so(i,1,n,1)
	{
		//cin>>a[i].x>>[i]>>r[i];
		int con=0;
		so(j,1,i-1,1) 
		{
			if((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])<=r[j]*r[j]) con^=1;
			
		}
		ans+=1.0*pi*r[i]*r[i]*(con?-1.0:1.0);
		//cout<<ans<<endl;
	}
	printf("%.2lf",ans);
}
