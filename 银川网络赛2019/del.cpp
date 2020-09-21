#include<bits/stdc++.h>
using namespace std;
#define MN 100005
#define mod 998244353
int n,pp[MN],ans[MN],ol[MN],tot,cnt,bb[MN],x[20005][20005],bu[MN],
phi[20005],lk[MN],shangjie;bool ispp[MN];
void OLS()
{
	n=MN;memset(ispp,1,sizeof(ispp));
	for(int i=2;i<=n;i++)
	{
		if(ispp[i]) pp[++tot]=i,ol[i]=i-1;
		for(int j=1;j<=tot;j++)
		{
			if(i*pp[j]>n) break;
			ispp[i*pp[j]]=0;
			if(i%pp[j]==0){
				ol[i*pp[j]]=ol[i]*(pp[j]) ;break;
			}
			ol[i*pp[j]]=ol[i]*(pp[j]-1);
		}
	}
} 
int ksm(int p)
{
	int ans=1,ha=2;
	for(;p;p>>=1,ha*=ha,ha%=mod)
	if(p&1) ans*=ha,ans%=mod;
	return ans;
}
int main()
{
	freopen("biao.txt","w",stdout);
	cin>>shangjie;
	OLS();ol[1]=1;
	//cout<<1<<endl;
	//for(int i=1;i<=MN;i++) cout<<ol[i]<<endl;
	for(int i=1;i<=MN;i++)
	{
		if(!bb[ol[i]]) bb[ol[i]]=1,phi[++cnt]=ol[i],lk[ol[i]]=cnt; 
	}	
	//cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++)
	{
		for(int j=1;j<=cnt;j++)
		{
			x[i][j]=(phi[i]*phi[j])%mod*ksm((phi[i]*phi[j])%(mod-1));
			//if(i*cnt+j>100000000)cout<<i*cnt+j<<endl;
		}
	}
	//cout<<2<<endl;
	/*for(int i=1;i<=cnt;i++)
	{
		for(int j=1;j<=cnt;j++)
		{
			cout<<x[i][j]<<" ";
		}
		cout<<endl;
	}*/
	for(int i=1;i<=shangjie;i++)
	{
		bu[lk[ol[i]]]++;
		ans[i]=ans[i-1];
		for(int j=1;j<=cnt;j++)
		{
			ans[i]+=(x[lk[ol[i]]][j]*bu[j])%mod;ans[i]%=mod;
			ans[i]+=(x[j][lk[ol[i]]]*bu[j])%mod;ans[i]%=mod;
			//cout<<lk[ol[i]]<<" "<<j<<" ";
		}
		ans[i]-=x[lk[ol[i]]][lk[ol[i]]];ans[i]+=mod;ans[i]%=mod;
	}
	//cout<<3<<endl;
	cout<<"{";
	for(int i=0;i<=shangjie;i++)
	{
		cout<<",";
		cout<<ans[i];
	}
	cout<<"}";
	return 0;
}
