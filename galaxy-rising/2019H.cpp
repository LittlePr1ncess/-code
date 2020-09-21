#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define MN 100005
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
#define LL long long
LL n,k,T,ans,t[MN],big[MN],small[MN],tot1,tot2,m;
bool cmp1(int a,int b)
{
    if(a/k==b/k) return a%k>b%k;
    else return a/k>b/k;
}
bool cmp2(int a,int b)
{
    return a<b;
}
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>k;tot1=tot2=0;m=0;
        memset(small,127,sizeof(small));
        so(i,1,n,1) scanf("%lld",&t[i]);
        so(i,1,n,1) if(t[i]>=k) big[++tot1] = t[i];else small[++tot2] = t[i];
        sort(big+1,big+1+tot1,cmp1);sort(small+1,small+1+tot2,cmp2);
        swap(small[1],small[tot2+1]);
        sort(small+1,small+1+tot2,cmp2);
        swap(small[tot2],small[tot2+1]);
        //cout<<tot1<<" "<<tot2<<endl;
        ans=k;
        so(i,1,tot1,1)
        {
            int x = big[i];
            //cout<<x<<" "<<ans<<endl;
            if(x/k>=2) m+=x/k-1;
            if(m>=tot2) {ans+=x;continue;}
            if(k-(x%k)<=k-small[m+1]) ans+=(x+k-1)/k*k,m++;
            else ans+=x;
        }
        so(i,1,tot2,1)
        {
            if(m>0) ans+=small[i],m--;
            else if(i!=tot2) ans+=k;
            else ans+=small[i];
        }
        cout<<ans<<endl;
    }
    //cin>>n;
}
/*
2
9 5
1 2 3 4 5 6 7 8 9
*/