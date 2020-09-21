#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
int x,m;bool flag;
void work(int n,int m)
{
	int ans=0;
	so(i,n,m,1)
	{
		//cout<<i<<" ";
		//if(i==153) cout<<i<<" "<<a<< " "<<b<<" "<<c; 
		int a=i/100,b=(i/10)%10,c=i%10;
		if(a*a*a+b*b*b+c*c*c==i) //cout<<i<<" ",flag=1;
		{
			if(flag==0) cout<<i,flag=1;
			else cout<<" "<<i;
		}
	} 
	//return ans;
}
int main()
{
	cout<<"del";
	while(~scanf("%d%d",&x,&m))
	//cin>>x>>m;
	{
		flag=0;
		work(x,m);
		if(!flag) cout<<"no";
		cout<<endl;
	}
	
} 
