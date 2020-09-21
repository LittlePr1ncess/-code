#include<bits/stdc++.h>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
#define db double
int T,n,m,a[205][205];int b[205],c[205];db ans;
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        so(i,1,n,1) so(j,1,m,1) scanf("%d",&a[i][j]);ans=0;
        so(j,1,m,1) {b[j]=0;so(i,1,n,1) b[j]+=a[i][j],ans=max(ans,1.0*b[j]/a[i][j]);}
        //ans1=b[1],ans2=c[1];
        //so(j,1,m,1) if(ans1*c[j]<ans2*b[j]) ans1=b[j],ans2=c[j];
        //db outt=1.0*ans1/ans2;
        printf("%.9lf\n",ans);
    }
    //system("pause");
}