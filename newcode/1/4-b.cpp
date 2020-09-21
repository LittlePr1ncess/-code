#include<bits/stdc++.h>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
#define MN 1000010
#define p 1000000007
#define LL long long
int pp[MN],ispp[MN],tot,lk[MN],dp[MN],x,c,T;
LL ksm(int a,int b)
{
    LL aa=a,sum=1;
    for(;b;b>>=1,aa*=aa,aa%=p)
    if(b&1) sum*=aa,sum%=p;
    return sum;
}
void OLS()
{
    so(i,1,1000000,1) ispp[i]=1;
	for(int i=2;i<=1000000;i++)
	{
		if(ispp[i]) pp[++tot]=i,lk[i]=1;
		for(int j=1;j<=tot;j++)
		{
			if(i*pp[j]>1000000) break;
			ispp[i*pp[j]]=0;
            lk[i*pp[j]]=i;
			if(i%pp[j]==0) break;
		}
	}
	ispp[1]=0;
}
int main()
{
    int t1=clock();
    OLS();
    so(i,2,1000000,1) dp[i]=dp[lk[i]]+1;
    //so(i,1,10,1) cout<<dp[i]<<" ";
    //cout<<clock()-t1;
    cin>>T;
    while(T--)
    {
        //cin>>x>>c;
        scanf("%d%d",&x,&c);
        //cout<<ksm(c,dp[x])<<endl;
        printf("%d\n",ksm(c,dp[x]));
    }
}