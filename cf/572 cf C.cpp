#include<bits/stdc++.h>
using namespace std;
int n,q;
vector<int>v[18][100005],sum[18][100005];
void init()
{
	v[1][1].push_back(0);
	for(int i=1;i<=n;i++) 
	{
		int x;cin>>x;
		v[1][1].push_back(x);
	} 
	int xx=(log10(n)/log10(2));
	int ceng=1;
	while(ceng<xx)
	{
		int ha=pow(2,ceng-1);
		for(int i=1;i<=ha;i++)
		{
			for(int j=1;j<v[ceng][i].size();j+=2)
			{
				v[ceng+1][2*i-1].push_back(0);
				sum[ceng+1][2*i-1].push_back(0);
				if(j+1<v[ceng][i].size())
				{
					v[ceng+1][2*i-1].push_back((v[ceng][i][j]+v[ceng][i][j+1])%10);
					if(v[ceng][i][j]+v[ceng][i][j+1]>=10) sum[ceng+1][2*i-1].push_back(1);
					else sum[ceng+1][2*i-1].push_back(0);
					for(int k=1;k<sum[ceng+1][2*i-1].size();k++) 
					sum[ceng+1][2*i-1][k]+=sum[ceng+1][2*i-1][k-1];
				} 	
			}
			for(int j=2;j<v[ceng][i].size();j+=2)
			{
				v[ceng+1][2*i-0].push_back(0);
				sum[ceng+1][2*i-0].push_back(0);
				if(j+1<v[ceng][i].size())
				{
					v[ceng+1][2*i-0].push_back((v[ceng][i][j]+v[ceng][i][j+1])%10);
					if(v[ceng][i][j]+v[ceng][i][j+1]>=10) sum[ceng+1][2*i-0].push_back(1);
					else sum[ceng+1][2*i-0].push_back(0);
					for(int k=1;k<sum[ceng+1][2*i-0].size();k++) 
					sum[ceng+1][2*i-0][k]+=sum[ceng+1][2*i-0][k-1];
				} 	
			}
		}
		ceng++;
	}
}
void work(int l,int r)
{
	int ceng=1,ans=0,ha=1;
	while(l<r)
	{
		int con=l%2;
		if(!con) ans+=sum[ceng+1][ha*2][l/2]-sum[ceng+1][ha*2][r/2-1],ha=ha*2,l/=2,r/=2;
		else ans+=sum[ceng+1][ha*2-1][(l+1)/2]-sum[ceng+1][ha*2-1][(r+1)/2-1],
		ha=ha*2-1
		,l=(l+1)/2,r=(r+1)/2;
		ceng++;
	}
	cout<<ans<<endl;
}
int main()
{
	cin>>n;
	init(); 
	cin>>q;
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		work(l,r);
	}
	return 0;
}
