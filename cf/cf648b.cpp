#include<bits/stdc++.h>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
int T,n,a[2],x,b[505];
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n;
        int f=1;a[0]=a[1]=0;
        so(i,1,n,1) cin>>b[i];so(i,1,n,1) cin>>x,a[x]=1;
        so(i,1,n-1,1) if(b[i]>b[i+1]) f=0;
        //cout<<f<<" "<<a[0]<<" "<<a[1]<<endl;
        if(f) {
            cout<<"Yes"<<endl;continue;
        }
        if(n==1||(a[0]==1&&a[1]==1)) 
        cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    //system("pause");
}