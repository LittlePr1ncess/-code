#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define so(i,j,k,l) for(register int i=j;i<=k;i+=l)

#define MN 100005
int n,T,bt[MN],f[MN][20],r,k,x,L,R,opt,m,lastans,a[MN];
inline int lowbit(int x) {return x&-x;}
int read()
{
int x=0,f=1;
char ch;
while(ch<'0'||ch>'9') {if(ch=='-')f=-1;ch=getchar();}
while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
return f*x;
}
int ansres;
inline void addd(int pos,int data)
{
	for(;pos<=n;pos+=lowbit(pos))
	 bt[pos]+=data;
}
inline int  getsum(int pos)
{    int ans=0;
	for(;pos;pos-=lowbit(pos))
	 ans+=bt[pos];
	return ans;
}
inline int ask(int L,int R)
{
    int k=log2(R-L+1);
    return max(f[L][k],f[R-(1<<k)+1][k]);
}
inline bool check(int mid)
{
    if(ask(k,mid)>r) return 1;
    if(getsum(mid)-getsum(k-1)>=1) return 1;
    return 0;
}
inline bool check1(int mid)
{
    if(getsum(mid)-ansres>=1) return 1;
    return 0;
}
int main()
{
    cin>>T;
    while(T--)
    {
        memset(bt,0,sizeof(bt));
        n=read();m=read();lastans= 0;
        so(i,1,n,1) {x=read();a[i]=x,f[x][0]=i;}
        f[n+1][0] = n+1;
        n++;
	    for(int j=1;(1<<j)<=n;j++)
	    for(int i=1;i+(1<<j)-1<=n;i++)
	        f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        so(i,1,m,1)
        {
            cin>>opt;
            if(opt==1) {x=read();x=a[x^lastans],addd(x,1);}
            else
            {
                int ans=-1;
                r= read();k=read();r^=lastans,k^=lastans;
                L = k,R = n;
                ansres=getsum(k-1);
                while(L<=R)
                {
                    int mid = (L+R)>>1;
                    if(check(mid)) ans = mid,R=mid-1;
                    else L =mid+1;
                }
                /*if(ans==-1)
                {
                	L = k,R = n;
                	while(L<=R)
                    {
                        int mid = (L+R)>>1;
                        if(check1(mid)) ans = mid,R=mid-1;
                        else L =mid+1;
                    }
				}*/
                lastans = ans;
                printf("%d\n",ans);
            }
        }
    
    }
}