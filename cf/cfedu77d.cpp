#include<bits/stdc++.h>
using namespace std;
#define MN 200005
int w[MN],b[MN],n,d[MN],r[MN],l[MN],t,m,k;
vector<int>lei[MN],fa[MN];
bool check(int x)
{
	memset(b,0,sizeof(0));
	x=w[x];
	int ans=0,now=0;
	for(int i=0;i<=n;i++)
	{
		if(lei[i+1].size()==0) {
			ans++;continue;
		}
		for(int j=0;j<lei[i+1].size();j++)
		{
			if(b[lei[i+1][j]]) continue;
			if(d[lei[i+1][j]]>x) {
				while(now<r[lei[i+1][j]])
				{
					for(int k=0;k<fa[now+1].size();k++)
					{
						b[fa[now+1][k]]=1;
					}
					ans++;now++;
				}
			}
		}
		ans++;
	} 
	if(ans<=t) return 1;
	else return 0;
}
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	cin>>m>>n>>k>>t;
	for(int i=1;i<=m;i++) cin>>w[i];
	sort(w+1,w+1+n,cmp); 
	for(int i=1;i<=k;i++) 
	cin>>l[i]>>r[i]>>d[i],lei[l[i]].push_back(i)
	,fa[r[i]].push_back(i);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<lei[i].size();j++)
		cout<<lei[i][j]<<" ";cout<<endl;
	}
	check(5);
	int lb=0,rb = n; 
	while( rb - lb > 1 )  // 区间长度为2时终止循环
{
    // 防止溢出
    int m = lb + (rb - lb) / 2;    // 由于是区间长度为2时终止循环，所以不用加1（不会死循环）
    if( check(m) ) lb = m;
    else rb = m;
}
	cout<<lb<<endl;
	return 0;
} 
