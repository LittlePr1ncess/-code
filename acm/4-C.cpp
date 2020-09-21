#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<cmath>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
#define MN 105
struct lll{
	int x,y;
}a[MN];
bool cmp(lll a,lll b)
{
	return b.y>a.y;
}
int n;
int main()
{
	while(cin>>n)
	{
		int ans=0;
		if(n==0) break;
		so(i,1,n,1) cin>>a[i].x>>a[i].y;
		sort(a+1,a+1+n,cmp);
		int rwz=0;
		so(i,1,n,1) 
		{
			//cout<<rwz<<" "<<a[i].x<<" "<<a[i].y<<endl;
			if(a[i].x>=rwz) ans++,rwz=a[i].y;
		}
		cout<<ans<<endl;
	}
	return 0;

}

