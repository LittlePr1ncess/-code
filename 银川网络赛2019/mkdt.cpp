#include<bits/stdc++.h>
using namespace std;
int n,t,q,wmax,mapp[205][205];
int main()
{
	srand((unsigned )time(0));
	freopen("a.txt","w",stdout);
	cin>>t>>n>>q>>wmax;
	cout<<t<<endl;
	for(int ha=1;ha<=t;ha++)
	{
		cout<<n<<" "<<q<<endl;
		for(int i=1;i<=n;i++) cout<<rand()%wmax+1<<" ";cout<<endl;
		for(int i=1;i<=n;i++) 
		{
			for(int j=i+1;j<=n;j++) 
			mapp[i][j]=rand()%wmax+1;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(mapp[j][i]) cout<<mapp[j][i]<<" ";
				else cout<<mapp[i][j]<<" ";
			}
			cout<<endl;
		}
		for(int i=1;i<=q;i++)
		{
			cout<<rand()%n+1<<" "<<rand()%n+1<<" "<<rand()%wmax<<endl;
		}
	} 
}
