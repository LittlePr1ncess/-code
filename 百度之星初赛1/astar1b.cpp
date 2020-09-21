#include<bits/stdc++.h>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
int n,T,a[15]={0,0,60,62,65,67,70,75,80,85,90,95};double ans, b[15]={0,0,1,1.7,2,2.3,2.7,3,3.3,3.7,4,4.3};
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n;
        ans=0;
        so(i,1,11,1) so(j,1,11,1) so(k,1,11,1) so(l,1,11,1)
        {
            if(a[i]+a[j]+a[k]+a[l]<=n) ans=max(ans,b[i]+b[j]+b[k]+b[l]);
        }
        //cout<<ans<<endl;
        printf("%.1f\n",ans);
    }
}