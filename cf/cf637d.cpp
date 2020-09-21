#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<cmath>
using namespace std;
#define so(i,j,k,l) for(register int i=j;i<=k;i+=l)
int num[15]={6,2,5,5,4,5,6,3,7,6};
int er[15]={119,18,93,91,58,107,111,82,127,123};
int a[2005],c[2005],b[2005][13],n,k,sz[2005];
string dp[2005];char ss[10];
int pows[10]={1,2,4,8,16,32,64};
int parse(string s)
{
	int ans=0;
	so(i,0,6,1)
	ans+=pows[6-i]*(s[i]-'0');
	return ans;
}
int jx(string s)
{
	int ans=0;
	so(i,0,6,1) if(s[i]=='1' ) ans++;return ans;
}
int main()
{
	cin>>n>>k;
	memset(b,-1,sizeof(b));
	so(i,1,n,1) scanf("%s",&ss),a[i]=parse(ss),c[i]=jx(ss);
	//so(i,1,n,1) cout<<a[i]<<" ";cout<<endl;
	so(i,1,n,1) so(j,0,9,1)
	if((a[i]|er[j])==er[j]) b[i][num[j]-c[i]]=max(b[i][num[j]-c[i]],j);
	//so(i,1,n,1) {so(j,0,9,1) cout<<b[i][j]<<" ";cout<<endl;}
	so(i,1,n,1) {
		for(register int j=k;j>=0;j--) 
		so(kk,0,7,1)
	{
		if(b[i][kk]==-1) continue;
		if(j-kk<0) break;
		if((dp[j-kk]=="")&&(j-kk!=0)) continue;
		if(sz[j-kk]<i-1) continue;
		//dp[j]="";
		//if(i==3) cout<<dp[j]<<" "<<dp[j-kk]<<" "<<b[i][kk]<<endl; 
		if(sz[j]<i) dp[j]=dp[j-kk]+(char)(b[i][kk]+48),sz[j]=sz[j-kk]+1;
		else if(dp[j-kk]+(char)(b[i][kk]+48)>dp[j])dp[j]=dp[j-kk]+(char)(b[i][kk]+48),sz[j]=sz[j-kk]+1;
		//if(i==3) cout<<dp[j]<<" " <<dp[j-kk]+(char)(b[i][kk]+48)<<endl;
	}
	//so(j,0,k,1) if(dp[j]=="") cout<<"_ ";else cout<<dp[j]<<" ";cout<<endl;
	so(j,0,k,1) if(sz[j]<i) dp[j]="",sz[j]=0;
	}
	//so(i,1,n,1) {so(j,0,k,1)if(dp[i][j]=="") cout<<"_ ";else cout<<dp[i][j]<<" ";cout<<endl;}
	if(dp[k]=="")
	cout<<"-1";
	else cout<<dp[k];
	return 0;
}

