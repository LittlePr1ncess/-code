#include<bits/stdc++.h>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
#define LL long long
int T,a,b,c,d,x,y,x1,y11,x2,y2,l,r,u,dd;
bool check()
{
	x+=(b-a); //cout<<x<<endl;
	if(l-r==0&&b+a!=0) return 0;
	if(x<l||x>r) return 0;
	y+=(d-c);//cout<<y<<endl;
	if(u-dd==0&&d+c!=0) return 0;
	if(y<dd||y>u) return 0;
	return 1;
}

int main()
{
	cin>>T;
	while(T--)
	{
		cin>>a>>b>>c>>d;
		cin>>x>>y>>x1>>y11>>x2>>y2;
		l=min(x1,x2);
		r=max(x1,x2);
		dd=min(y11,y2);
		u=max(y11,y2);
		//cout<<l<<" "<<r<<" "<<" "<<dd<<" "<<u<<" "<<x<<" "<<y<<endl;
		if(check())cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
} 
