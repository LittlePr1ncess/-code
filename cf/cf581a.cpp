#include<bits/stdc++.h>
using namespace std;
string s;bool flag=0;int ans;
int main()
{
	cin>>s;
	for(int i=1;i<s.size();i++)
	{
		if(s[i]=='1') flag=1; 
	} 
	int len=s.size()-1;
	//cout<<len<<endl;

	//cout<<ans<<endl;
	//if(flag==1) cout<<len/2+1;
	 if(len!=0)ans=len/2+1;
	 else ans=1;
	 if(len%2==0&&flag==0)cout<<ans-1;
	 else cout<<ans; 
//	else cout<<ans-1;
} 
//10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
