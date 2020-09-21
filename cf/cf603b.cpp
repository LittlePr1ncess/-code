#include<bits/stdc++.h>
using namespace std;
#define MN 200005 
#define LL long long 
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
int T,n,a[MN],t[MN],b[MN],endd[MN],ans[MN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n;
		so(i,1,n,1) cin>>a[i],t[a[i]]=i,b[i]=0,endd[i]=0,ans[i]=0;
		/*so(j,1,n,1)
			{
				cout<<t[j]<<" ";
				
			}cout<<endl; */
		int duan = 1;
		endd[1]=endd[n]=1;b[0]=1;b[n+1]=1;
		for(int i=n;i>=1;i--)
		{
			if(duan==1) ans[i]=1;
			if(b[t[i]-1]==1&&b[t[i]+1]==1) duan-=1;
			else if(endd[t[i]]==1)
			{
				if(b[t[i]-1]==1) endd[t[i]+1]=1;
				else endd[t[i]-1]=1;
			}
			else {
				duan++;
				endd[t[i]-1]=1;endd[t[i]+1]=1;
			}
			b[t[i]]=1;		
			/*cout<<duan<<endl;
			so(j,1,n,1)
			{
				cout<<b[j]<<" ";
				
			}cout<<endl; */
		}
		so(i,1,n,1)
		cout<<ans[i];cout<<endl;
	}
} 
