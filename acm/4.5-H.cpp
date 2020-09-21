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
int n,T,ans;
int main()
{	
	cin>>T;
	while(T--)
	{
		ans=1000000;
		cin>>n;
		for(int i=1;i*i<=n;i++)
		{
			if(n%i) continue;
			//so(j,1,sqrt(n/i),1)
			for(int j=1;j*j<=n/i;j++)
			{
				if(n/i%j) continue;
				ans=min(ans,i*j+i*(n/i/j)+j*(n/i/j)); 
			}
			//if(i*j*k==n) ans=min(ans,i*j+j*k+i*k);
		}
		cout<<ans*2<<endl;
	}
	return 0;

}

