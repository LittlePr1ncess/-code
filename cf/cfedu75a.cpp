#include<bits/stdc++.h>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
int T,flag[256];string s;
int main()
{
	cin>>T;
	while(T--)
	{
		memset(flag,0,sizeof(flag));
		cin>>s;s[s.size()]='1';
		int sum=0;
		so(i,0,s.size(),1) 
		{
			if(s[i]!=s[i-1]) {
				if(sum%2) flag[s[i-1]]=1;sum=1; 
			}
			else sum++;
		}
		so(i,'a','z',1) if(flag[i]) cout<<(char)i;
		cout<<endl;
	}
	
} 
