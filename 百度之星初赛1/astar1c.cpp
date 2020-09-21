#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{return b?gcd(b,a%b):a;}
int a,b,T,dp[1010][1010];
int main()
{
    //int rwz=clock();
    dp[1][1]=1;
    for(int i=1;i<=1000;i++)
     for(int j=1;j<=1000;j++)
     {
         int G=(gcd(i,j)==1);
         if(i-1) dp[i][j]=max(dp[i][j],dp[i-1][j]+G);
         if(j-1) dp[i][j]=max(dp[i][j],dp[i][j-1]+G);
     }
    //int rwz2=clock();
    //cout<<rwz2-rwz;
    cin>>T;
    while(T--)
    {
        scanf("%d%d",&a,&b);
        //cout<<dp[a][b]<<endl;
        printf("%d\n",dp[a][b]);
    }
}