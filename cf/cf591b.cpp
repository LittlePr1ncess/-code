#include<bits/stdc++.h>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
int T,n,bu[300],tag[300];string s,t;
int main()
{
	
	cin>>T;
	while(T--)
	{
		cin>>s>>t;
		int ans=0;
		memset(bu,0,sizeof(bu));
		memset(tag,0,sizeof(tag));
		bool flag = 0;
		for(int i=0;i<s.size();i++) {
			if(s[i]!=t[i]) break;
			if(i==s.size()-1) flag=1;
		}
		if(flag==1) {
			cout<<"YES"<<endl;continue;
		}
		so(i,0,s.size()-1,1) bu[s[i]]=1;
		so(i,0,s.size()-1,1) 
		{
			//if(!bu[t[i]]) flag=1;
			if(!tag[t[i]]) tag[t[i]]=1;
		}
		
		so(i,'a','z',1) if(bu[i]&&tag[i]) ans++;
		if(ans==0) {
			cout<<"NO"<<endl;continue;
		}
		else cout<<"YES"<<endl;
		//if(ans=='0') 
		//if(s.size()>ans) cout<<"YES"<<endl;
		//else cout<<"NO"<<endl;
	}
	return 0;
} 
