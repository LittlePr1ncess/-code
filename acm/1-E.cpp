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
#define MN 2005
int n,m,a[MN][MN],sum[MN][MN];string s;
bool check(int i)
{
	so(j,1,m,1) if(sum[j][n]-a[i][j]<1)  return 0;    
	return 1;
}
int main()
{
	cin>>n>>m;
	so(i,1,n,1){
		cin>>s;
		so(j,1,m,1) a[i][j]=s[j-1]-'0';
	}
	so(j,1,m,1) so(i,1,n,1) sum[j][i]=sum[j][i-1]+a[i][j];
/*	so(i,1,n,1){
		so(j,1,m,1) cout<<sum[j][i]<<" ";cout<<endl;
	}*/
	/*n=2000;m=2000;
	so(i,1,n,1) so(j,1,m,1) a[i][j]=0;*/
	so(i,1,n,1) 
	if(check(i)) {cout<<"YES";return 0;}
	cout<<"NO";
	return 0;

}

