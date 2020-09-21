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
#define MN 105
int a[MN],b[MN],ans[MN],T,n,k,wz;
int main()
{
	cin>>T;
	while(T--)
	{
		memset(b,0,sizeof(b));
		int tot=0,cnt=0;
		cin>>n>>k;
		so(i,1,n,1) cin>>a[i];
		so(i,1,n,1) b[a[i]]++;
		so(i,1,n,1) if(b[i]) tot++,wz=i;
		if(tot>k) {cout<<-1<<endl;continue;}
		so(i,1,n,1) if(b[i]) ans[++cnt]=i;
		while(cnt<k) ans[++cnt]=wz;
		cout<<k*100<<endl;
		so(i,1,100,1) so(j,1,cnt,1)
		{
			cout<<ans[j]<<" ";
		}
		cout<<endl;
	}
	return 0;

}

