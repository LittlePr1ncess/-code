#include<bits/stdc++.h>
using namespace std;
#define  MN 1005
#define LL long long
LL ans;
int n,m,bu[MN][MN],a[MN];char c;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		cin>>c,bu[j][c]++;
	}
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		ans+=max(max(max(max(bu[i]['A'],bu[i]['B']),bu[i]['C']),bu[i]['D']),bu[i]['E'])*a[i];
	}
	cout<<ans;
	return 0;
} 
