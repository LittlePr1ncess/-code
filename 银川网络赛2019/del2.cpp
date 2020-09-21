#include<bits/stdc++.h>
using namespace std;
#define MN 100050
int n,pp[MN],ans,ol[MN],bb[MN],tot;bool ispp[MN];
int main()
{
	n=MN;memset(ispp,1,sizeof(ispp));
	for(int i=2;i<=n;i++)
	{
		if(ispp[i]) pp[++tot]=i,ol[i]=i-1;
		for(int j=1;j<=tot;j++)
		{
			if(i*pp[j]>n) break;
			ispp[i*pp[j]]=0;
			if(i%pp[j]==0){
				ol[i*pp[j]]=ol[i]*(pp[j]) ;break;
			}
			ol[i*pp[j]]=ol[i]*(pp[j]-1);
		}
	}
	for(int i=1;i<6;i++) cout<<ol[5]<<" ";
	cout<<ans;
}
