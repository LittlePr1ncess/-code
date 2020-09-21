#include<bits/stdc++.h>
using namespace std;
#define MN 20
#define INF 100000000
string s;
int b1[MN],b2[MN],bb[MN],ans[MN][MN][MN][MN],c1[MN],c2[MN],jz[MN][MN];
int main()
{
	cin>>s;
	/*------------------------------------
	for(int i=0;i<10;i++)
	 for(int j=0;j<10;j++)
	  for(int k=1;k<2;k++)
	   for(int l=1;l<2;l++)
	   {
	   		ans[i][j][k][l]=10000000;
	   		for(int a=0;a<10;a++) b1[a]=b2[a]=0,c1[a]=c2[a]=bb[a]=1000;
			for(int a=0;a<10;a++) 
			b1[(a*k)%10]=1,c1[(a*k)%10]=min(c1[(a*k)%10],a),
			b2[(a*l)%10]=1,c2[(a*l)%10]=min(c2[(a*l)%10],a);
			for(int a=0;a<10;a++)
			for(int b=0;b<10;b++)
			if(b1[a]==1&&b2[b]==1) bb[(a+b)%10]=min(bb[(a+b)%10],c1[a]+c2[b]);
			for(int a=0;a<10;a++) 
			{
				if((i+a)%10==j) ans[i][j][k][l]=min(ans[i][j][k][l],bb[a]);
			}
	   }
	*///-------------------------------------------------------
	for(int i=0;i<10;i++)
	 for(int j=0;j<10;j++)
	  for(int k=0;k<10;k++)
	   for(int l=0;l<10;l++)
	   {
	   		ans[i][j][k][l]=INF;
	   		for(int a=0;a<10;a++) b1[a]=b2[a]=0,c1[a]=c2[a]=bb[a]=INF;
			for(int a=0;a<10;a++) 
			b1[(a*k)%10]=1,c1[(a*k)%10]=min(c1[(a*k)%10],a),
			b2[(a*l)%10]=1,c2[(a*l)%10]=min(c2[(a*l)%10],a);
			for(int a=0;a<10;a++)
			for(int b=0;b<10;b++)
			if(b1[a]==1&&b2[b]==1) bb[(a+b)%10]=min(bb[(a+b)%10],c1[a]+c2[b]);
			for(int a=0;a<10;a++) 
			{
				if((i+a)%10==j) ans[i][j][k][l]=min(ans[i][j][k][l],bb[a]);
			}
	   }
	for(int i=0;i<10;i++) 
	{
		for(int j=0;j<10;j++)
		cout<<ans[i][j][1][1]<<" ";cout<<endl;
	}
	//for(int i=0;i<10;i++) for(int j=0;j<10;j++) jz[i][j]=-1;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
	 	{
		 	//if(jz[j][i]) {jz[i][j]=jz[j][i];continue;} 
		 	int len=s.size();
		 	for(int k=0;k<len;k++)
		 	{
	 			if(k==0) continue;
		 		if(ans[s[k-1]-'0'][s[k]-'0'][i][j]==INF) {
		 			jz[i][j]=-1;break;
		 		}
		 		if(ans[s[k-1]-'0'][s[k]-'0'][i][j]!=0)
				 jz[i][j]+=ans[s[k-1]-'0'][s[k]-'0'][i][j]-1;
		 	}
	 	
		 }	
	}
	 
	 for(int i=0;i<10;i++)
	 {
	 	 for(int j=0;j<10;j++)
	 	 cout<<jz[i][j]<<" ";cout<<endl;
	 }
	return 0;
} 
