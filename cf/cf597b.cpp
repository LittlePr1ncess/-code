#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define so(i,j,k,l) for(int i=j;i<=k;i+=l) 
int n,ans[105],T,a,b,c;char s[105];
void print()
{
	so(i,1,n,1) 
	{
		if(ans[i]) continue;
		if(a) {a--;ans[i]='R';continue;}
		if(b) {b--;ans[i]='P';continue;}
		if(c) {c--;ans[i]='S';continue;}
	}
	so(i,1,n,1) cout<<(char)ans[i];
	cout<<endl;
}
int main()

{
	cin>>T;
	while(T--)
	{
		memset(ans,0,sizeof(ans));
		int sum=0;
		cin>>n>>a>>b>>c;char x;
		so(i,1,n,1)
		{
			cin>>x;
			if(x=='R'&&b) {b--;ans[i]='P';sum++;continue;}
			if(x=='P'&&c) {c--;ans[i]='S';sum++;continue;}
			if(x=='S'&&a) {a--;ans[i]='R';sum++;continue;}
		}
		if(sum>=((n+1)/2)) 
		{
			cout<<"YES"<<endl;print();
		}
		else cout<<"NO"<<endl;
		 
	}
	
}
 
