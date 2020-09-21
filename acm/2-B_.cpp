#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,m,h,r,dtx,l,mid,a[50001];
bool cool(int s)
{
	int stone=0,p=0;
 	for(int i=1;i<=n;i++)
  	if(a[i]-a[p]>=s)
  	{
   		p=i;
   		stone++;
  	}
 // if(dtx-a[n])
  	return stone>=h;
  
}

int main()
{
	cin>>dtx>>n>>m;
 	h=n-m;
 	for(int j=1;j<=n;j++)
  	cin>>a[j];
  	sort(a+1,a+1+n);
 	l=0;r=dtx;
 	while(l<r)
 	{
	 	mid=(l+r+1)/2;
  		if(cool(mid)) l=mid;
  		else r=mid-1;
 	}
 	cout<<l;
 	return 0;
}
