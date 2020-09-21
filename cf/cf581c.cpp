#include<bits/stdc++.h>
using namespace std;
#define MN 105
int n,dis[MN][MN],ans[MN],tot,p[MN],m;char x;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
	{
		cin>>x;
		if(i==j) continue;
		if(x=='1') dis[i][j]=1;else dis[i][j]=100000;
	}
	 
    cin>>m;
    for(int i=1;i<=m;i++) cin>>p[i];
    /*for(int i=1;i<=n;i++)
     {
     	for(int j=1;j<=n;j++)
     	cout<<dis[i][j]<<" ";cout<<endl;
     }*/
	for(int k=1;k<=n;k++)  
     for(int i=1;i<=n;i++)  
     for(int j=1;j<=n;j++)  
      if(dis[i][j]>dis[i][k]+dis[k][j] )   
                         dis[i][j]=dis[i][k]+dis[k][j];  
    /*for(int i=1;i<=n;i++)
     {
     	for(int j=1;j<=n;j++)
     	cout<<dis[i][j]<<" ";cout<<endl;
     }*/
    for(int i=1;i<m;i++)
    {
    	if(i==1) {ans[++tot]=p[i];}
    	if(i==m-1) {ans[++tot]=p[i+1];continue;}
    	
    	if(2<=dis[p[i]][p[i+2]]) continue;
    	else ans[++tot]=p[i+1];
    	
    }
    cout<<tot<<endl;
    for(int i=1;i<=tot;i++) cout<<ans[i]<<" ";
}
