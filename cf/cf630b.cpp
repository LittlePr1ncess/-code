#include<bits/stdc++.h>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
#define LL long long
int bu[20]={0,2,3,5 ,7, 11, 13, 17, 19, 23, 29, 31},lk[10005],a[10005],ans[10005],T,n,m,tag[20];
int main()

{
	cin>>T;
	while(T--)
	{
		cin>>n;
		m=0;
		memset(tag,0,sizeof(tag));
		so(i,1,n,1) cin>>a[i];
		so(i,1,n,1)
		so(j,1,11,1)
		{
			if(a[i]%bu[j]==0) {ans[i]=j,tag[j]=1;break;}
		}
		//so(i,1,11,1) cout<<tag[i]<<" ";cout<<endl;
		//so(i,1,11,1) cout<<ans[i]<<" ";cout<<endl;
		so(i,1,11,1)
		{
			if(tag[i]) lk[i]=++m;
		}
		cout<<m<<endl;
		so(i,1,n,1) cout<<lk[ans[i]]<<" ";cout<<endl;
	}
} 
