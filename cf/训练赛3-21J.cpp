#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define MN 100005 
int ispp[MN+5],pp[MN+5],tot,n,m,xgz;
void OLS()
{
	for(int i=2;i<=MN;i++)
	{
		if(ispp[i]) pp[++tot]=i;
		for(int j=1;j<=tot;j++)
		{
			if(i*pp[j]>MN) break;
			ispp[i*pp[j]]=0;
			if(i%pp[j]==0) break;
		}
	}
	ispp[1]=0;
}
int main()
{
	//cin>>n>>m;
	//string s[10];//s[1]="Yes",s[0]="No";
	//memset(ispp,1,sizeof(ispp));
	for(int i=1;i<=MN;i++) ispp[i]=1;
	OLS();
	cin>>n;
	for(int i=1;i<=tot;i++)
	{
		//cout<<pp[i]<<endl; 
		if(n%pp[i]) 
		{
			cout<<pp[i];
			break;
		}
	}
	//while(m--)
	//{
	//	cin>>xgz;cout<<s[ispp[xgz]]<<endl;
	//}
	return 0;
}
