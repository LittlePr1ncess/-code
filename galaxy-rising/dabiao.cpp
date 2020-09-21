#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define MN 10000005 
int ispp[MN],pp[MN],tot,n,m,xgz;
void OLS()
{
	for(int i=2;i<=n;i++)
	{
		if(ispp[i]) pp[++tot]=i;
		for(int j=1;j<=tot;j++)
		{
			if(i*pp[j]>n) break;
			ispp[i*pp[j]]=0;
			if(i%pp[j]==0) break;
		}
	}
	ispp[1]=0;
}
int main()
{
	cin>>n>>m;
    freopen()
	//string s[10];s[1]="Yes",s[0]="No";
	//memset(ispp,1,sizeof(ispp));
	for(int i=1;i<=n;i++) ispp[i]=1;
	OLS();
    cout<<"{";
    for(int i=1;i<=tot;i++)
    {
        if(i!=tot) cout<<pp[i]<<",";
        else cout<<pp[i]<<"}";
    }
    cout<<";";
	/*while(m--)
	{
		cin>>xgz;cout<<s[ispp[xgz]]<<endl;
	}*/
    cin>>n;
	return 0;
}