#include<bits/stdc++.h>
using namespace std;
#define p 1000000007
#define MN 305
#define MM 80000
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
#define LL long long
struct lll{
	int x,sup;
}a[MN];
int T,n,dp[MN][MM][2],ans,sum;
bool cmp(lll a, lll b)
{
	return a.sup>b.sup;
}
int main()
{
	cin>>T;
	while(T--)
	{
		memset(dp,0,sizeof(dp));
		sum=0;ans=0;
		cin>>n;so(i,1,n,1) cin>>a[i].x,sum+=a[i].x;
		so(i,1,n,1) a[i].sup=(sum+a[i].x)/2;
	
		sort(a+1,a+1+n,cmp);	
		//so(i,1,n,1) cout<<a[i].x<<" "<<a[i].sup<<endl;
		//so(i,0,a[n].sup,1) dp[0][i][0]=1;
		dp[0][0][0]=1;
		so(i,1,n,1)
		{
			so(j,0,a[1].sup,1)
			//for(int j=a[n].sup;j>=0;j--)
			{
				dp[i][j][0]+=(dp[i-1][j][1]+dp[i-1][j][0])%p;dp[i][j][0]%=p;
				if(j-a[i].x<0)  continue;
				dp[i][j][1]+=(dp[i-1][j-a[i].x][1]+dp[i-1][j-a[i].x][0])%p;
				dp[i][j][1]%=p;
			}
		}
		/*so(i,1,n,1)
		{
			so(j,0,a[1].sup,1)
			cout<<dp[i][j][1]<<" ";
			cout<<endl;
		}
		so(i,1,n,1)
		{
			so(j,0,a[1].sup,1)
			cout<<dp[i][j][0]<<" ";
			cout<<endl;
		}*/
		so(i,1,n,1)
		{
			int l = (sum+1)/2;
			so(j,l,a[i].sup,1)
			ans+=dp[i][j][1];ans%=p;
		}
		cout<<ans<<endl;
	}
}
/*
1
3
1 3 7

*/
