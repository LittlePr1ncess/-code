#include<bits/stdc++.h>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
#define MN 100005
long long  T,n,a[MN],ans,sum;
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n;
        sum = ans = 0;
        so(i,1,n,1) cin>>a[i];
        so(i,1,n,1)
        {
            //cout<<sum<<" "<<ans<<endl;
            if(a[i]<0) 
            {
                if(sum+a[i]<0) ans-=sum+a[i],sum = 0;
                else sum += a[i];
            }
            else sum += a[i];
        }
        cout<<ans<<endl;
    }
    //cin>>n;
}