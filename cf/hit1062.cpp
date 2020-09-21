#include<bits/stdc++.h>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
#define MN 50005
int n,a[MN],Max,Min;
int main()
{
	cin>>n;
	while(n)
	{
		queue<int>q1,q2;
		so(i,1,n,1)cin>>a[i];
		sort(a+1,a+1+n);
		so(i,1,n,1) q1.push(a[i]);
		for(int i=1;i<n;i++)
		{
			if(q2.empty()) {x=q1.front(),q1.pop();break;}
			if(q1.empty()) {x=q2.front(),q2.pop();break;}
			if(q1.front()<q2.front()) x=q1.front(),q1.pop();
			else x=q2.front(),q2.pop();32
			if(q2.empty()) {y=q1.front(),q1.pop();break;}
			if(q1.empty()) {y=q2.front(),q2.pop();break;}
			if(q1.front()<q2.front()) y=q1.front(),q1.pop();
			else y=q2.front(),q2.pop();
			q2.push(x*y+1);
		}
		Max=q2.front();q2.pop();
		for(int i=n;i>=1;i++) q1.push(a[i]);
		for(int i=1;i<n;i++)
		{
			if(q2.empty()) {x=q1.front(),q1.pop();break;}
			if(q1.empty()) {x=q2.front(),q2.pop();break;}
			if(q1.front()>q2.front()) x=q1.front(),q1.pop();
			else x=q2.front(),q2.pop();
			if(q2.empty()) {y=q1.front(),q1.pop();break;}
			if(q1.empty()) {y=q2.front(),q2.pop();break;}
			if(q1.front()>q2.front()) y=q1.front(),q1.pop();
			else y=q2.front(),q2.pop();
			q2.push(x*y+1);
		}
		Min=q2.front();q2.pop();
        cout<<Max-Min<<endl;
		cin>>n;
	}
}