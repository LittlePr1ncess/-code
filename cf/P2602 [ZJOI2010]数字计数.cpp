#include<bits/stdc++.h>
using namespace std;
#define so(i,j,k,l ) for(int i=j;i<=k;i+=l)
#define LL long long
LL ans[15][2],l,r,ten[15],dp[20],n;
void slove(LL n,bool  con)
{
	LL a[14],b[14],tot=0;
	memset(a,0,sizeof(a));memset(b,0,sizeof(b));
	if(n==0) tot=1;
	while(n)
	{
		a[++tot] = n%10;
		b[tot]=b[tot-1]+a[tot]*ten[tot-1];
		n/=10;
	}
	
	for(int ha=tot;ha>=1;ha--)
	{
		if(ha==1) 
		{
			so(i,0,a[ha],1) ans[i][con]++;
			return ;
		}
		so(i,0,9,1) ans[i][con]+=dp[ha-1]*a[ha];
		so(i,0,a[ha]-1,1) 
		ans[i][con]+=ten[ha-1];
		ans[a[ha]][con]+=b[ha-1]+1;
		//ans[0][con]-=ten[tot]*(tot-1);
		
		ans[0][con]-=ten[ha-1];
		
	}

	//so(i,0,9,1) cout<<ans[i][1]<<" ";cout<<endl;
	//slove(b[tot-1],con);
}
int main()
{
	cin>>l>>r;
	ten[0]=1;//dp[0]=1;
	for(int i=1;i<=14;i++)
	{
		dp[i]=dp[i-1]*10+ten[i-1];
		ten[i]=ten[i-1] *10;
	}
	slove(r,1);
	
	slove(l-1,0);
//	so(i,0,9,1) cout<<ans[i][1]<<" ";cout<<endl;
//	so(i,0,9,1) cout<<ans[i][0]<<" ";cout<<endl;
	/*while(r) r/=10,n++;
	ans[0][1] -= 5*n*(n-1);l--;n=0;
	while(l) l/=10,n++;ans[0][0]-=5*n*(n-1);*/
	so(i,0,9,1) cout<<ans[i][1]-ans[i][0]<<" ";
} 
