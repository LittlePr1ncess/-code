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
int T;int a[MN],n,k;char c[MN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		scanf("%s",c+1);
		so(i,1,n,1) a[i]=c[i];
		sort(a+1,a+1+n);
		if(a[1]!=a[k]) cout<<char(a[k])<<endl;
		else{
			if(a[k+1]!=a[n]){
				cout<<char(a[1]);so(i,k+1,n,1) cout<<char(a[i]);cout<<endl;continue;
			}
			cout<<char(a[1]);
			int rwz=n-k;
			while(rwz>0)
			{
				cout<<char(a[k+1]);
				rwz-=k;
			}
			cout<<endl;
		}
	}
	return 0;

}

