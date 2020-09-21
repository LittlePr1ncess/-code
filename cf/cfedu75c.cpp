#include<bits/stdc++.h>
using namespace std;
#define so(i,j,k,l) for (int i=j;i<=k;i+=l)
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string s;
		queue<int>q1,q0;
		cin>>s;
		so(i,0,s.size()-1,1) 
		{
			int x=s[i]-'0';if(x%2) q1.push(x);else q0.push(x);
		}
		so(i,1,s.size(),1)
		{
			if(q1.empty()) cout<<q0.front(),q0.pop();
			else if(q0.empty()) cout<<q1.front(),q1.pop();
			else {
				if(q1.front()<q0.front()) cout<<q1.front(),q1.pop();
				else cout<<q0.front(),q0.pop();
			}
		}
		cout<<endl;
	}
} 
