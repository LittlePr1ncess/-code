#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<iostream>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
int t;
int n;
int a[100010];
bool check(int h)
{
    if(a[1]>h) return 0;
    long long sum = 0;
	so(i,1,n,1)
    {
        sum += a[i];
        if(sum>1ll*h*i) return 0;
    }
    return 1;
}
int main()
{
	cin>>t;
    int ans = 0;
	for(int o=1;o<=t;o++)
	{
		scanf("%d",&n);
		int l=2000000000,r=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			l=min(l,a[i]);
			r=max(r,a[i]);
		}
        a[n+1]= 0;
		while(l<=r)
		{
			int mid=(l+r)/2;
            //cout<<l<<" "<<r<<" " <<ans<<endl;
			if(check(mid)) ans=mid,r=mid-1;
            else l=mid+1;
		}
        //cout<<check(3)<<endl;
		cout<<ans<<endl;
	}
	
    //system("pause");
    return 0;
}
