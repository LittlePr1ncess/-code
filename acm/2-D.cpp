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
int q,ans;
int check(int x)
{
	int ret=0;
	while(x)
    {
        ret+=x/5;
        x=x/5;
    }
	return ret;
}
int main()
{
	cin>>q;
	if(q==0) {
		cout<<1;return 0;
	}
	int l=0,r=q;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(5*mid)>=q)
		ans=mid,r=mid-1;
		else l=mid+1;
	}
	if(check(5*ans)!=q) 
	cout<<"No solution";
	else 
	cout<<ans*5;
	return 0;

}

