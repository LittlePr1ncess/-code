#include<bits/stdc++.h>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
int T,n,x,a[105],b[105];
int main() {
	cin>>T;
	while(T--)
	{
		int cnt=0,Max=0;
		cin>>n>>x;
		memset(b,0,sizeof(b));
		so(i,1,n,1) cin>>a[i],Max=max(Max,a[i]);
		so(i,1,n,1) b[a[i]]=1;
		so(i,1,Max,1){
			if(b[i]==0) {
				cnt++;
			}
			if(cnt>x)
			{
				cout<<i-1<<endl;break;
			}
			if(i==Max) {
				cout<<Max+x-cnt<<endl;break;
			}
		}
	}
}
