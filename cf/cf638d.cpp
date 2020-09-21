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
#define LL long long
LL T,n,a[35];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n;
		LL rwz=n;
		LL bit=0;
		while(rwz)
		{
			bit++;
			rwz>>=1;
		}
		bit-=1;
		//cout<<bit;
		LL sum=bit+1;
		a[0]=1;
		so(i,1,bit,1)
		{
			/*so(j,1,a[i-1]+1,1)
			{
				//cout<<i<<":"<<sum<<" "<<j<<endl;
				
				if((sum+j*(bit-i+1)>n)||(j==a[i-1]+1)) 
				{sum+=(j-1)*(bit-i+1),a[i]=a[i-1]+j-1;break;}
			}
			*/
			if(sum+a[i-1]*(bit-i+1)<=n) sum+=a[i-1]*(bit-i+1),a[i]=2*a[i-1];
			else{
				LL ww=(n-sum)/(bit-i+1);
				sum+=ww*(bit-i+1),a[i]=a[i-1]+ww;
			}
		}
		if(sum==n)
		{
			cout<<bit<<endl;
			so(i,1,bit,1) cout<<a[i]-a[i-1]<<" ";cout<<endl;
		}
		else cout<<-1<<endl;
		//so(i,1,bit,1) cout<<a[i]<<" ";cout<<endl;
	}
	return 0;

}

