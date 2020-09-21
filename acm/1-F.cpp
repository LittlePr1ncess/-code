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
int n,m,t[200],k,x,ans;
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		if(n==0) break;
		memset(t,0,sizeof(t));
		so(i,1,n,1)
		{
			cin>>k;
			so(i,1,k,1) cin>>x,t[x]++;
		}
		int M=0;
		so(i,1,100,1) if(t[i]>=m&&t[i]>M) M=t[i],ans=i;
		if(!M) puts("0");
		else cout<<ans<<endl;
	}
	return 0;

}

