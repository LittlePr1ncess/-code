#include<iostream>
#include<cstdio>
#include<ctime>
#include<cmath>
//#include<windows.h>
using namespace std;
#define so(i,j,k,l) for(register int i=j;i<=k;i+=l)
#define MN 5005
#define LL long long
int n,m,k,st[MN][20],a[MN][MN],b[MN][MN];LL ans;
inline int gcd(int a,int b)
{return b?gcd(b,a%b):a;}
inline LL ask(int l,int r)
{
    //int k=log2(r-l+1);
    int k=0;
    int L=r-l+1;
    while(L){
        L>>=1;
        k++;
    }k--;
    return max(st[l][k],st[r-(1<<k)+1][k]);
}
inline void init(int kk)
{
    so(i,1,n,1) st[i][0]=a[i][kk];

    for(register int j=1;(1<<j)<=n;j++)
	    for(register int i=1;i+(1<<j)-1<=n;i++)
	        st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
    so(i,1,n+1-k,1) b[i][kk]=ask(i,i+k-1);
}
inline void init2(int kk)
{
    so(i,1,m,1) st[i][0]=b[kk][i];
    for(register int j=1;(1<<j)<=m;j++)
	    for(register int i=1;i+(1<<j)-1<=m;i++)
	        st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
    so(i,1,m+1-k,1) ans+=ask(i,i+k-1);
}
int main()
{
    cin>>n>>m>>k;
   // int rwz=clock();
    for(register int i=1;i<=n;i++) for(register int j=1;j<=m;j++) a[i][j]=i*j/gcd(i,j);
    for(register int j=1;j<=m;j++) init(j);
    //so(i,1,n+1-k,1){so(j,1,m,1) cout<<b[i][j]<<" ";cout<<endl;}
    for(register int i=1;i<=n-k+1;i++) init2(i);
    cout<<ans;
    //int rwz2=clock();cout<<endl<<rwz2-rwz;
    //system("pause");
}