#include<bits/stdc++.h>
using namespace std;
#define MN 1000000
#define Mb 10
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
int n,T,b;long long sum[Mb+5][MN+5],ans[Mb+5][MN+5];
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	//int rwz1=clock();
	cin>>T;
		so(bb,2,Mb,1)
		{
			so(i,1,MN,1)
			{
				int x=i;
				while(x)
				{
					ans[bb][i]+=(x%bb);
					x/=bb;
				}
				sum[bb][i]=sum[bb][i-1]+ans[bb][i];
				//cout<<1<<endl;
			}
		}
	so(ha,1,T,1)
	{
		cin>>n>>b;
		printf("Case #%d: %lld\n",ha,sum[b][n]);
	}
	//int rwz2=clock();
	//cout<<rwz2-rwz1;
}
