#include<bits/stdc++.h>
using namespace std;
#define MN 100005
string x,y;int T,lenx,leny,wz1,k;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>x>>y;
		lenx=x.size(),leny=y.size();
		for(int i=leny-1;i>=0;i--) 
		if(y[i]=='1') {wz1=leny-i;break;}
	//	cout<<wz1<<endl;
	//	cout<<lenx-wz1<<endl; 
		for(int i=lenx-wz1;i>=0;i--) if(x[i]=='1') {k=lenx-wz1-i;break;}
		cout<<k<<endl;
	}
	return 0;
} 
