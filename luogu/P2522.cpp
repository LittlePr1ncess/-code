#include<bits/stdc++.h>
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
using namespace std;
#define N 50000
#define MN 50005
int ispp[MN],pp[MN],tot,mu[MN],sum[MN],a,b,c,d,k,T;
void OLS()
{
    so(i,1,N,1) ispp[i] = 1;
    mu[1] = sum[1] = 1;
	so(i,2,N,1)
	{
		if(ispp[i]) pp[++tot]=i,mu[i] = -1;
		so(j,1,tot,1)
		{
			if(i*pp[j]>N) break;
			ispp[i*pp[j]]=0;
			if(i%pp[j]==0) {mu[i*pp[j]] = 0;break;}
            mu[i*pp[j]] = -mu[i];
		}
        sum[i] = sum[i-1] + mu[i];
	}
	ispp[1]=0;
}
int work(int n,int m)
{
    n/=k,m/=k;int t = min(n,m),r,ans = 0;
    for(int l=1;l<=t;l=r+1)
    {
        r = min(n/(n/l),m/(m/l));
        ans += (sum[r] - sum[l-1])*(n/l)*(m/l);
    }
    return ans;
}
int main()
{
    OLS();
    cin>>T;
    while(T--)
    {
        cin>>a>>b>>c>>d>>k;
        //cout << work(b,d) <<" "<< work(a-1,d) <<" "<< work(b,c-1) <<" "<< work(a-1,c-1)<<endl;
        cout << work(b,d) - work(a-1,d) - work(b,c-1) + work(a-1,c-1)<<endl;
    }
    //cin>>a;
}