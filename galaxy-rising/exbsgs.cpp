#include<bits/stdc++.h>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
#define LL long long
LL p , b , n;
map<LL,LL>M;
LL gcd(LL a,LL b)
{return b?gcd(b,a%b):a;}
LL kpow(LL a,LL b)
{
    LL ans = 1;
    for(;b;b>>=1,a *= a,a %= p)
    if(b&1) ans *= a,ans %= p;
    return ans;
}
LL BSGS(LL p,LL b,LL n)
{
    M.clear();M[n%p] = 0;
    LL m = ceil(sqrt(p));
    LL tmp = n,bm = kpow(b,m);
    so(i,1,m,1) 
    {tmp = tmp * b % p;M[tmp] = i;}
    tmp = 1;
    
    so(i,1,m,1) 
    {
        tmp *= bm; tmp %= p;
        if(M[tmp]&&(i*m-M[tmp]>=0)) {return i*m-M[tmp];}
        if(i == m) return -1;
    }
}
/*LL EXBSGS(LL p,LL b,LL n)
{
    if(n == 1) return 0;
    LL tn = n,tmp = 1,k = 0;
    for (int g = gcd(b,p);g!=1;g = gcd(b,p),k++)
    {
        if(tn%g) return -1;
        tn/=g;p/=g;tmp = tmp * b / g %p;
        if(tmp == tn) return k; 
    }
    return BSGS(p,b,n);
}*/
inline LL EXBSGS(LL a, LL b, LL p) {
    if(b == 1) return 0;
    LL tb = b, tmp = 1, k = 0;
    for(int g = gcd(a, p); g != 1; g = gcd(a, p)) {
        if(tb % g) return -1;
        tb /= g; p /= g; tmp = tmp * a / g % p;
        k++;
        if(tmp == tb) return k;
    }
    return BSGS(p, a, b);
    
}
int main()
{
    while(cin>>b>>p>>n)
    {
        //cout<<b<<" "<<p<<" "<<n<<endl;
        if(!(p+b+n)) break;
        LL ret = EXBSGS(b,n,p);
        if(ret == -1) cout<<"No Solution"<<endl;
        else cout<<ret<<endl;
    }
    
    cin>>n;
}