#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<cmath>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
#define db double
int n,T;
db x[205],y[205],dis[205][205];
int main()
{
	while(cin>>n)
	{
		T++;
		if(n==0) break;
		so(i,1,n,1)  cin>>x[i]>>y[i];
		so(i,1,n,1) so(j,1,n,1) {
			dis[i][j]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
			dis[i][j]=sqrt(dis[i][j]);
		}//so(i,1,n,1){so(j,1,n,1) cout<<dis[i][j]<<" ";cout<<endl;}
		so(k,1,n,1) so(i,1,n,1) so(j,1,n,1) dis[i][j]=min(dis[i][j],max(dis[i][k],dis[k][j]));
		
		printf("Scenario #%d\n",T);
		printf("Frog Distance = %.3f\n\n",dis[1][2]);
	}
	return 0;

}

