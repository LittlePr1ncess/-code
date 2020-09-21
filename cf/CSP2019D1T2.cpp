#include<bits/stdc++.h>
using namespace std;
#define MN 500005
#define LL long long
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
struct lll{
	int to,nxt;
}a[MN*2];
LL h[MN],tot,ans,vis[MN],n,x;char s[MN];
void link(int x,int y)
{a[++tot].to=x,a[tot].nxt=h[y];h[y]=tot;}
void dfs(LL st[],LL fa,LL faa,LL u,LL l[],LL r[],LL p)
{
	LL sum =0;
	if (s[u]-st[p]==1) sum=(1+l[p]),ans^=u*(faa+1+l[p]),p--,r[p]+=1;//,cout<<sum+faa<<" "<<u<<endl;
	//if (s[u]-st[p]==1) sum=(1+l[p]),ans+=(faa+ 1+l[p]),p--,r[p]+=1,cout<<sum<<" "<<u<<endl;
	else st[++p]=s[u],r[p]=0,l[p]=r[p-1],ans^=u*faa;
	for(int i=h[u];i;i=a[i].nxt)
	{if(!vis[a[i].to]) vis[a[i].to]=1,dfs(st,u,faa+sum,a[i].to,l,r,p);}
}
int main()
{
	cin>>n;so(i,1,n,1) cin>>s[i];so(i,2,n,1) cin>>x,link(x,i),link(i,x);
	vis[1]=1;
	LL ll[MN],stt[MN],rl[MN];
	memset(ll,0,sizeof(ll));
	memset(stt,0,sizeof(stt));
	memset(rl,0,sizeof(rl));
	dfs(stt,0,0,1,ll,rl,0);
	cout<<ans;
	return 0; 
}
/*
10
()(()())()
1 2 3 4 5 6 7 8 9

*/
