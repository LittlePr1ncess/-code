#include<bits/stdc++.h>
#include<hash_map>
using namespace std;
#define LL long long
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
#define MN 200005
map<LL,LL>b;
//map<int, string>::iterator iter;  
LL n ,a[MN],p,ans,sum[MN],p1=1;
int main()
{
	//freopen("a.txt","r",stdin);
	cin>>n;
	so(i,1,n,1) scanf("%lld",&a[i]);
	while(p1<=n)
	{
		if(p<p1)
		{
			so(i,p1,n,1)
			{
				sum[i]=sum[i-1]+a[i];
				b[sum[i]]=i;
				if(a[i]==0) continue;
				
				p=p1=i;break;
			}
			if(p<p1) break;
		}//cout<<p1<<" "<<p<<endl;
		//b[0]=n;
		while(1)
		{
			//so(i,1,n,1) cout<<sum[i]<<" ";cout<<endl;
			if(p1==1 ){
			 if(b[(sum[p]+a[p+1])]!=0||sum[p]+a[p+1]==0) break;}
			else {
			if(b[(sum[p]+a[p+1])]>=p1-1) break;}
			if(p>=n) break;
			p++;
			sum[p]=sum[p-1]+a[p];
			b[sum[p]]=p;
			
		}
		ans+=p-p1+1;
		p1++;
		//cout<<p1<<" "<<p<<endl;
	}
	cout<<ans;
} 
