#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<cmath>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
#define N 100000
#define LL long long
int tot,ispp[N+5],pp[N],m,a,b,ans1,ans2;
void OLS(int n)
{
	so(i,1,n,1) ispp[i]=1;
	so(i,2,n,1)
	{
		if(ispp[i]) pp[++tot]=i;
		so(j,1,tot,1)
		{
			if(i*pp[j]>n) break;
			ispp[i*pp[j]]=0;
			if(i%pp[j]==0) break;
		}
	}
	ispp[1]=0;
}
int main()
{
	OLS(N);
	while(~scanf("%d%d%d",&m,&a,&b))
	{
		if(m==0) break;
		int M=0;
		so(i,1,tot,1)
		{
			int flag=0;
			so(j,i,tot,1)
			{
				LL s=pp[i],l=pp[j];
				if(s*l>m) break;
				if(s*b<l*a) break;
				if(M<=s*l)
				ans1=s,ans2=l,M=s*l;
			}
		}
		cout<<ans1<<" "<<ans2<<endl;
	}
	
	return 0;
}

