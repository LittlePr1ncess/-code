#include<bits/stdc++.h>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
int n,m,a[55][55],aa,b,T;
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        aa=b=0;
        so(i,1,n,1) so(j,1,m,1) cin>>a[i][j];
        so(i,1,n,1) {
            int f=0;
            so(j,1,m,1) if(a[i][j]) f=1;
            if(!f) aa++;
        }
        so(j,1,m,1) {
            int f=0;
            so(i,1,n,1) if(a[i][j]) f=1;
            if(!f) b++;
        }
        //cout<<aa<<" "<<b<<endl;
        aa=min(aa,b);
        if(aa%2) cout<<"Ashish"<<endl;
        else cout<<"Vivek"<<endl;
    }
    //system("pause");
}