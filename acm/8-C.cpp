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
	while(cin>>n)
	{
		if(!n) break;LL ans=0,cnt=0,tot=0;
		so(i,1,n-1,1)
		{
			//cout<<endl<<i<<endl;
			int rwz,emm;char ww;
			cin>>ww;
			cin>>rwz;//cout<<"#"<<ww<<"#";
			so(j,1,rwz,1) {
			cin>>ww;a[++tot].x=ww;a[tot].y=i+'A'-1;cin>>a[tot].z;}
		} //cout<<tot;
		so(i,1,n,1) fa[i+'A'-1]=i+'A'-1;
	//	so(i,1,tot,1) cin>>a[i].x>>a[i].y>>a[i].z;
		sort(a+1,a+1+tot,cmp);
		so(i,1,tot,1)
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
/*
3
A 1 B 1

*/

