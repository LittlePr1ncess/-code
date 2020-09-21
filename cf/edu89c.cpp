#include<bits/stdc++.h>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
#define LL long long 
#define db double
int T,n,m,bu[100][2];
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        int ans=0;
        memset(bu,0,sizeof(bu));
        so(i,1,n,1) so(j,1,m,1) 
        {
            int x;cin>>x;
            if(i+j-2==n+m-i-j) continue;
            bu[min(i-1+j-1,n-i+m-j)][x]++;
        }
        //so(i,0,n+m,1) cout<<bu[i][0]<<" "<<bu[i][1]<<endl;
        so(i,0,n+m,1) ans+=min(bu[i][0],bu[i][1]);
        cout<<ans<<endl;
    }
    //system("pause");
}