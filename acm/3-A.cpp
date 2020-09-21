#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<cmath>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
int T;string s[5][5];int b[10];
bool check(char x,int rwz)
{
	so(i,1,3,1)
	
	{
		if(b[i]==2)
		{
			if((s[i][0].find(x)!=s[i][0].npos)||(s[i][1].find(x)!=s[i][1].npos))
			return 0;
		}
		if(b[i]==1)
		{
			if(s[i][rwz].find(x)==s[i][rwz].npos)return 0;
		}
		if(b[i]==0)
		{
			if(s[i][rwz^1].find(x)==s[i][rwz^1].npos) return 0;
		}
	}
	return 1;
}
int main()
{
	cin>>T;
	while(T--)
	{
		so(i,1,3,1) 
		{
			cin>>s[i][0]>>s[i][1]>>s[i][3];
			if(s[i][3]=="even") b[i]=2;
			else if(s[i][3]=="up") b[i]=0;
			else b[i]=1;
		}
		so(i,'A','L',1)
		{
			if(check(i,0)) 
			{
				cout<<char(i)<<" is the counterfeit coin and it is light. "<<endl;
				break;
			}	
			if(check(i,1))
			{
				cout<<char(i)<<" is the counterfeit coin and it is heavy. "<<endl;
				break;
			}
		}
	} 
	return 0;

}
/*
2 
ABCD EFGH even 
ABCI EFJK up
ABIJ EFGH even 
ABCD EFGH even 
IJKL ABCD up
IJKA BCDE even

*/

