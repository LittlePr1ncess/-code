#include<bits/stdc++.h>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
#define LL long long
LL p , b , n;
map<LL,LL>M;
LL kpow(LL a,LL b)
{
    LL ans = 1;
    for(;b;b>>=1,a *= a,a %= p)
    if(b&1) ans *= a,ans %= p;
    return ans;
}
void BSGS(LL p,LL b,LL n)
{
    LL m = ceil(sqrt(p));
    M[n%p] = 0;
    LL tmp = n,bm = kpow(b,m);
    so(i,1,m,1) 
    {tmp = tmp * b % p;M[tmp] = i;if(i==92) cout<<tmp<<endl;}
    tmp = 1;
    
    so(i,1,m,1) 
    {   
        tmp *= bm; tmp %= p;
        if(M[tmp]) {cout<<i*m-M[tmp];break;}
        if(i == m) cout<<"no solution";
    }
}
int main()
{
    cin>>p>>b>>n;
    BSGS(p,b,n);
    cin>>n;
}
/*
8829 9758476 3358180
*/