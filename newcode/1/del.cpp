#include<bits/stdc++.h>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
int a[100][100],ans[100][100];
int main()
{
    so(i,1,50,1) a[1][i]=1;
    so(j,3,10,1)
    {
        so(i,1,50,1) if(a[i][j]) {if(i+j<=50) a[i+j][j]=1;if(i*j<=50)a[i*j][j]=1;}
        so(i,1,50,1) ans[i][j]=ans[i-1][j]+a[i][j],cout<<ans[i][j]<<" ";cout<<endl;
    }    
    system("pause");
}