#include<bits/stdc++.h>
using namespace std;
int n,m;int b[600005];
void work(int a,int bb)
{
	int ans1=0;
	memset(b,0,sizeof(b));b[a]=1;
	for(int i=1;i*i<=a;i++)
	{
		if(a%i==0) {
			if(!b[i]) ans1+=i,b[i]=1;
			if(!b[a/i]) ans1+=a/i,b[a/i]=1;
		}
	}
	int ans2=0;
	memset(b,0,sizeof(b));b[bb]=1;
	for(int i=1;i*i<=bb;i++)
	{
		if(bb%i==0) {
			if(!b[i]) ans2+=i,b[i]=1;
			if(!b[bb/i]) ans2+=bb/i,b[a/i]=1;
		}
	}
	if(ans1==bb&&ans2==a) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	//cout<<ans1<<" "<<ans2<<endl;
}
int main()
{
	int T,a,b;
	cin>>T;
	while (T--)
	{
		cin>>n>>m;
		work(n,m);
	}
}
