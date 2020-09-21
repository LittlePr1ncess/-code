#include<bits/stdc++.h>
using namespace std;
int n,T;char x;string s;
int main()
{
	cin>>T;
	while(T--)
	{
		//cin>>n;
		cin>>s;
		int len = s.size();
		int M=0;int last=0;
		for(int i=1;i<=len;i++)
		{
			char x=s[i-1];
			if(x=='L') continue;
			M=max(M,i-last);last=i;
		}
		M=max(M,len+1-last);
		cout<<M<<endl;
	}
} 
