#include<bits/stdc++.h>
using namespace std;
#define so(i,j,k,l)  for(int i=j;i<=k;i+=l)
#define MN 200005
int n,a[MN],b[MN],ans,lk[MN],bu[2][MN];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    so(i,1,n,1) cin>>b[i],lk[b[i]]=i;
    so(i,1,n,1) {
        int rwz=lk[a[i]]-i;
        
        //if(i==1&&a[1]==b[n]) bu[0][1]++;
        //if(i==n&&a[n]==b[1]) rwz=1;
        //cout<<rwz<<endl;
        if(rwz>0) bu[1][rwz]++,bu[0][n-rwz]++;
        else bu[0][-rwz]++,bu[1][n+rwz]++;

    }
    so(i,1,n,1) ans=max(ans,max(bu[0][i],bu[1][i]));
    cout<<ans;
    //system("pause");
}