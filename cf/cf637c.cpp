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
#define MN 100005
int T,n,a[MN],lk[MN];
bool check()
{
	int ed=n ;
	int x=lk[1];
	while(ed)
	{
		int i;
		for(i=x+1;i<=ed;i++) if(a[i]!=a[i-1]+1) return 0;
		ed=x-1;
		x=lk[a[i-1]+1];
	}
	return 1;
}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n;
		so(i,1,n,1) cin>>a[i],lk[a[i]]=i;
		if(check()) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	} 
	 
	
	return 0;

}

