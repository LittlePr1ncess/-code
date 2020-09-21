#include<bits/stdc++.h>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
#define MN 300005
int T,n,a[MN],vis[MN],con,k,bu[2],f;
string s;
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>k>>s;
        con = bu[1] = bu[0] = f = 0;
        so(i,1,k,1) vis[i] = -1;
        for(int i=0,j=1;i<n;i++,j++)
        {
            if(j==k+1) j = 1;
            if(s[i]=='1'&&vis[j]==-1) vis[j] = 1,bu[1]++;
            if(s[i]=='0'&&vis[j]==-1) vis[j] = 0,bu[0]++;
            //cout<<s[i]<<" "<<vis[j]<<" "<<con<<endl;
            if(s[i]=='1'&&vis[j]==0) 
            {cout<<"NO"<<endl,f=1;break;}
            if(s[i]=='0'&&vis[j]==1) 
            {cout<<"NO"<<endl,f=1;break;}
        }
        if(!f&&abs(bu[1]-bu[0])>k-bu[1]-bu[0]) {cout<<"NO"<<endl;continue;}
        if(!f) cout<<"YES"<<endl;
    }
    //cin>>n;
}