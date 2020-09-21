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

string s=":(";
int n,tot;char a[300005],ans[300005];
bool check()
{
	int emm=0;
	so(i,2,n-1,1) if(ans[i]==')') {
		if(emm==0) return 0;emm--;
	}
	else emm++;
	return !emm;
}

int main()
{
	cin>>n;
	so(i,1,n,1) cin>>a[i];
	if(a[1]==')'){
		cout<<s;return 0;
	}
	if(a[n]=='('){
		cout<<s;return 0; 
	}
	if(n%2){
		cout<<s;return 0;
	}
	ans[1]='(';ans[n]=')';
	so(i,2,n-1,1) if(a[i]=='(') tot++;
	so(i,2,n-1,1) 
	{
		if(a[i]=='?'){
			if(tot<n/2-1) ans[i]='(',tot++;
			else ans[i]=')';
		}
		else ans[i]=a[i];
	}
	if(check()) 
	{
		so(i,1,n,1) cout<<ans[i];
	}
	else cout<<s;
	return 0;

}

