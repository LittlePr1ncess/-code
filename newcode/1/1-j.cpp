#include<bits/stdc++.h>
using namespace std;
#define p 998244353
#define LL long long
LL n,di[2000010],sum[1000010],inv;
LL ksm(LL a, LL b)
{
    LL sum=1;
    LL aa=a;
    for(;b;b>>=1,aa*=aa,aa%=p)
    {
        if(b&1) sum*=aa,sum%=p;
    }
    return sum;
}
int main()
{
    sum[1]=di[1]=1;
    for(int i=2;i<=1000000;i++)
    sum[i]=sum[i-1]*i,sum[i]%=p,sum[i]=sum[i]*i,sum[i]%=p;
    for(int i=2;i<=2*1000000+1;i++)
    di[i]=di[i-1]*i,di[i]%=p;
   // for(int i=1;i<=5;i++) cout<<di[i]<<" ";

    while(cin>>n)
    {
        inv=ksm(di[2*n+1],p-2);
        cout<<((sum[n]*inv)%p)<<endl;
    }
}