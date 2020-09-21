#include<bits/stdc++.h>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
#define MN 1027
int T,bu[MN],bu2[MN],s[MN],n;
bool check(int M)
{
    so(i,0,M,1) if(bu[i]!=bu2[i]) return 0;
    return 1;
}
int main()

{
    cin>>T;
    while(T--)
    {
        cin>>n;
        int M=0;
        so(i,1,n,1) cin>>s[i],M=max(M,s[i]);
        M=1024;
        so(i,0,M,1)bu2[i]=0,bu[i]=0; 
        so(i,1,n,1) bu[s[i]]++;
        int f=0;
        so(i,1,M,1) {
            so(j,0,M,1) bu2[j]=0;
            so(j,1,n,1) bu2[i^s[j]]++;
            
            if(check(M)) {cout<<i<<endl;f=1;break;}
            /*cout<<M<<endl;
            so(j,0,M,1) cout<<bu[j]<<" ";cout<<endl;
            so(j,0,M,1) cout<<bu2[j]<<" ";cout<<endl;*/
        }
        if(!f) cout<<-1<<endl;
        
    }
    //system("pause");
}