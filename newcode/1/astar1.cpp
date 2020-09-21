#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
#define LL long long
LL T,m,q,p,n,ans;
LL ksm(LL a,LL b)
{
    LL sum = 1;
    LL aa = a;
    for(;b;b>>=1,aa*=aa,aa%=mod){
        if(b&1) sum *=aa,sum%=mod;
    }
    return sum;
}
int main()
{
    cout<<(1<<1);
    cin>>T;
    while(T--)
    {
        cin>>m>>q>>p;
        n = (m*100)%mod*ksm(q,mod-2);
        n %= mod;
        ans = (m - ((((n - 1 +mod)%mod*p)%mod*ksm(100,mod-2))%mod )+mod)%mod;
        cout<<ans<<endl;
    }
    //system("pause");
}