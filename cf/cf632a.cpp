#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
#define MN 105
int n,m,T,rwz;char ans[MN][MN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		so(i,1,n,1)
		{
			
			rwz=(i-1)%2;
			so(j,1,m,1)
			{
				if(rwz) ans[i][j]='W',rwz^=1;
				else ans[i][j]='B',rwz^=1;
			}
			
		}
		if(((n%2)==0)&&((m%2)==0)) ans[n][1]='B';
		if((n%2)*(m%2)==0) ans[n][m]='B';
		so(i,1,n,1)
		{
			so(j,1,m,1)
			cout<<ans[i][j];
			cout<<endl;
		}
	}
} 
