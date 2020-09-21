#include<bits/stdc++.h>

#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
#define LL long long 
#define p 998244353
#define MN 3000005
using namespace std;

LL n, m, limit = 1, l, r[MN],rwz[MN],G = 3, Gi = 332748118; 
LL a[MN], b[MN];
LL fastpow(LL a, LL b) {
	LL ans = 1;
    for(;b;b>>=1,a=a*a%p)
    if(b&1) ans = ans * a % p;
	return ans;
}
void NTT(LL *A, int emm) {
	so(i,0,limit-1,1)  if(i<r[i]) swap(a[i], a[r[i]]);
	for(int i = 1; i < limit; i<<= 1) {	
		LL wn = fastpow(emm==1?G:Gi,(p-1)/(i << 1));
		for(int j = 0; j < limit; j += (i << 1)) {
			LL w=1;
			for(int k=0; k<i; k++, w=(w*wn)% p) {
				 int x = a[j+k], y = w*a[j+k+i]%p;
				 a[j+k] = (x+y)%p,
				 a[j+k+i] = (x-y+p)%p;
			}
		}
	}
}
int btfl(int x)
{
    int ans = 0,tt = 0;
    for(int i=1;i<=l;i++)
    {
        rwz[i]=x&1;
        x>>=1;
    }
    for(int i=1;i<=l;i++)
    ans<<=1,ans+=rwz[i];
    return ans;
}
int main() {
	cin>>n>>m;
	so(i,0,n,1) cin>>a[i],a[i]%=p;
	so(i,0,m,1) cin>>b[i],b[i]%=p;
	while(limit<=n+m) limit<<=1,l++;
	for(int i=0;i<limit;i++) r[i]=btfl(i);
	//rev[i]=(rev[i>>1]>>1)|((i&1)<<(l-1));
	NTT(a,1);NTT(b,1);	
	for(int i=0;i<limit;i++) a[i]=(a[i]*b[i])%p;
	NTT(a,-1);	
	LL inv = fastpow(limit,p-2);
	for(int i=0; i<=n+m;i++)
		printf("%d ", (a[i]*inv)%p);
	return 0;
}