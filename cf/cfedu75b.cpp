#include<bits/stdc++.h>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
int T,n,bu[10],l[60];string s[60];
int main()
{
	cin>>T;
	while(T--)
	{
		int ans=0,need=0,con1=0,con0=0,db=0;memset(bu,0,sizeof(bu));
		cin>>n;so(i,1,n,1) {cin>>s[i];so(j,0,s[i].size()-1,1) bu[s[i][j]-'0']++;l[i]=s[i].size();};
		sort(l+1,l+1+n);con0=bu[0]%2;con1=bu[1]%2;db=bu[0]/2+bu[1]/2;
		//cout<<db<<endl;
		so(i,1,n,1)
		{
			if(l[i]%2) need++;
			db-=l[i]/2;
			if(db*2+con0+con1<need) break;
			if(db<0) break;
			ans++;
		}
		cout<<ans<<endl;
	}
} 
