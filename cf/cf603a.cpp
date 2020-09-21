#include<bits/stdc++.h>
using namespace std;
#define LL long long 
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
int T;string S ,s ;int n;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>s;
		so(i,0,s.size()-1,1)
		{
			if(s[i]=='?') 
			{
				if(i==0) {
					if(s[i+1]=='b') s[i]='a';
					else s[i ] ='b';
				}
				if(s[i-1]=='a')
				{
					if(s[i+1]=='b') s[i]='c';
					else s[i] = 'b';
				}
				if(s[i-1]=='b')
				{
					if(s[i+1]=='a') s[i]='c';
					else s[i] = 'a';
				}
				if(s[i-1]=='c')
				{
					if(s[i+1]=='b') s[i]='a';
					else s[i] = 'b';
				}
			}
		}
		int flag = 0;
		so(i,0,s.size()-1,1) if(i!=(s.size()-1)&&s[i]==s[i+1]) flag=1;
		if(flag==1) cout<<-1<<endl;
		else{
			so(i,0,s.size()-1,1) cout<<s[i];
			cout<<endl;
		}
	}
} 
