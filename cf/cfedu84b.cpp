#include<bits/stdc++.h>
using namespace std;
#define MN 100005
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
int T,n,b[MN],bb[MN],ans,y,x,wz1,wz2;
vector<int> a[MN];
int main()
{
	cin>>T;
	while(T--)
	{
		ans=0;
		//memset(b,0,sizeof(b));
		//memset(bb,0,sizeof(bb));
		
		cin>>n;
		so(i,1,n,1) {
			cin>>x;
			so(j,1,x,1)
			{
				cin>>y;
				a[i].push_back(y);
			}
			b[i]=bb[i]=0;
		}
		so(i,1,n,1){
			if(!a[i].empty()){
			int len=a[i].size()-1;
			so(j,0,len,1)
			{
				if(b[a[i][j]]==0){
					b[a[i][j]]=1;
					bb[i]=1;
					break;
				}
			}
			}//so(i,1,n,1) cout<<b[i]<< " ";cout<<endl;
		}
		so(i,1,n,1) {
			if(bb[i]==0) wz1=i;
			if(b[i]==0) wz2=i;
			//b[i]=bb[i]=0;
			if(bb[i]==1) ans++;
			while(!a[i].empty()) a[i].pop_back();
		}
		
		if(ans<n){
			cout<<"IMPROVE"<<endl<<wz1<<" "<<wz2<<endl;
		}
		else cout<<"OPTIMAL"<<endl;
	}
} 
