#include<bits/stdc++.h>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
#define LL long long 
#define db double
#define N 3200
#define MN 500005
int ispp[N+5],pp[N+5],n,x,tot,a[MN],ans[2][MN];
void OLS()
{
    so(i,1,N,1) ispp[i]=1;
	for(int i=2;i<=N;i++)
	{
		if(ispp[i]) pp[++tot]=i;
		for(int j=1;j<=tot;j++)
		{
			if(i*pp[j]>N) break;
			ispp[i*pp[j]]=0;
			if(i%pp[j]==0) break;
		}
	}
	ispp[1]=0;
}
int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}
int main()
{
    OLS();
    //so(i,1,10,1) cout<<pp[i]<<" ";
    cin>>n;
    so(i,1,n,1)
    {
        cin>>x;int cnt=0;
        so(j,1,tot,1)
        {
            if(pp[j]*pp[j]>x) break;
            if(x%pp[j]==0) a[++cnt]=pp[j];
        }
        so(j,1,cnt,1) cout<<a[i]<<" ";cout<<endl;
        ans[0][i]=ans[1][i]=-1;
        so(j,1,cnt,1) 
        {
            if(gcd(x,a[j]+a[cnt])==1)
        {
            ans[0][i]=a[j];ans[1][i]=a[cnt];break;
        }
        }
    }
    so(i,1,n,1) cout<<ans[0][i]<<" ";cout<<endl;
    so(i,1,n,1) cout<<ans[1][i]<<" ";cout<<endl;
    system("pause");
}