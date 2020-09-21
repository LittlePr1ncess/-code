#include<bits/stdc++.h>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
#define MN 	200005
int T,n,a[MN],b[MN],c[MN],l[5],r[5],Max,tot,wz;
bool check()
{
	b[0]=2;	
	if(b[1]==1) return 0;
	so(i,1,Max,1) 
	{
	//cout<<"sb"<<endl;
		if((b[i]!=1)&&(b[i]!=2)) return 0;
		//cout<<i<<endl;
	}
	//cout<<"sv"<<endl;
	so(i,1,Max,1) if((b[i]==2)&&(b[i-1]!=2)) return 0;
	
	so(i,1,Max,1){
		if(b[i]==1) {
			wz=i-1;return 1;
		}
		if(i==Max)
		{
			wz=i;return 1;
		}
	}
	//cout<<"qq"<<wz<<endl;
}
bool work(int l,int r)
{
	memset(c,0,sizeof(c));
	so(i,1,l,1) c[a[i]]=1;
	
	//so(i,1,l,1) cout<<c[i]<<" ";cout<<endl;
	so(i,1,l,1) if(c[i]!=1) return 0;
	memset(c,0,sizeof(c));
	so(i,l+1,n,1) c[a[i]]=1;
	//so(i,1,r,1) cout<<c[i]<<" ";cout<<endl;
	so(i,1,r,1) if(c[i]!=1) return 0;
	return 1;
}
int main() {
	cin>>T;
	while(T--)
	{
		Max=0,tot=0;
		memset(b,0,sizeof(b));
		memset(l,0,sizeof(l));
		memset(r,0,sizeof(r));
		cin>>n;
		so(i,1,n,1) cin>>a[i],b[a[i]]++,Max=max(a[i],Max);
		//so(i,1,n,1) cout<<b[i]<<" ";cout<<endl;
		//cout<<Max<<endl;
		
		if(!check()){
			cout<<0<<endl;continue;
		}
		//cout<<wz;
		if(work(wz,n-wz)) l[++tot]=wz,r[tot]=n-wz;
		if(work(n-wz,wz)) l[++tot]=n-wz,r[tot]=wz;
		cout<<tot<<endl;
		so(i,1,tot,1)
		{
			cout<<l[i]<<" "<<r[i]<<endl;
		}
	}
}
/*
1
6
2 4 1 3 2 1
*/
