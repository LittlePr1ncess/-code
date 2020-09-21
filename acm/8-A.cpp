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
#define LL long long
int fa[MN],n,m;
struct lll{
	 int x,y;LL z;
}a[MN*MN];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
bool cmp(lll a, lll b)
{
	return a.z<b.z;
}
int main()
{
	while(cin>>m>>n)
	{
		if(!m) break;LL ans=0,cnt=0;
		so(i,1,n,1) fa[i]=i;
		so(i,1,m,1) cin>>a[i].x>>a[i].y>>a[i].z;
		sort(a+1,a+1+m,cmp);
		so(i,1,m,1)
		{
			if(find(a[i].x)==find(a[i].y)) continue;
			cnt+=a[i].z;fa[find(a[i].x)]=find(a[i].y);
			ans++;if(ans>=n-1) break;
			
		}
		if(ans<n-1) cout<<"?"<<endl;
		else cout<<cnt<<endl;
	}
	return 0;

}

