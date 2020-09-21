#include<bits/stdc++.h>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
#define LL long long
#define MN 100005
int T,n,k,bu[266],ans,Max;char c[MN];
int main()
{
	cin>>T;
	while(T--)
	{
		ans=0;
		cin>>n>>k;
		so(i,1,n,1) cin>>c[i];
		
		so(i,1,(k+1)/2,1)
		{
			int cnt=0;Max=-1;
			so(j,'a','z',1) bu[j]=0;
			
			so(j,i,n,k)
			{
				bu[c[j]]++;cnt++;
			}
			if(2*i!=k+1)
			{
			
			so(j,k-i+1,n,k)
			{
				bu[c[j]]++;cnt++;
			}
			
			}
			//so(j,'a','z',1) cout<<bu[j]<<" ";
			so(j,'a','z',1) Max=max(Max,bu[j]);
			ans+=cnt-Max;
			//cout<<i<<":"<<cnt<<" "<<Max<<endl;
		}
		cout<<ans<<endl;
	}
} 
/*
1
36 9
hippopotomonstrosesquippedaliophobia
*/
