#include<bits/stdc++.h>
using namespace std;
#define LL long long 
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
struct lll{
	int x,y;
}a[1005];
int T,n,m;
bool cmp(lll a,lll b)
{
	return a.x<b.x;
}
int main()
{
	cin>>T;
	while(T--)
	{
		LL sum = 0,ans;
		cin>>n>>m;
		so(i,1,n,1) {
			cin>>a[i].x;sum+=a[i].x;a[i].y=i;
			//if(x<=Min) Min2=Min,Min2i=Mini,Min=x,Mini=i;
			//else if(x<=Min2) Min2=x,Min2i=i;
		}
		//cout<<endl<<sum<<endl;
		if(m<n||n==2){
			cout<<-1<<endl;continue;
		}
		sort(a+1,a+1+n,cmp);
		ans = sum*2+(a[1].x+a[2].x)*(m-n);
		cout<<ans<<endl;
		so(i,1,n-1,1) cout<<i<<" "<<i+1<<endl;
		cout<<n<<" "<<1<<endl;
		so(i,1,m-n,1) cout<<a[1].y<<" "<<a[2].y<<endl; 
	} 
} 
