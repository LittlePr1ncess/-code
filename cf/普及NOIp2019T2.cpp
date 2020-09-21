#include<bits/stdc++.h>
using namespace std;
#define LL long long 
#define MN 100005
LL n,ans1,ans2,m,cha,a[MN],s2,s1,p1,x1,x2;
LL f(LL x)
{`
	return s2*(m-x)+cha;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cin>>m>>p1>>s1>>s2; a[p1]+=s1;
	for(int i=1;i<m;i++) ans1+=a[i]*(m-i);
	for(int i=m+1;i<=n;i++) ans2+=a[i]*(i-m);
	//for(int i=1;i<=n ;i++) cout<<a[i];cout<<endl;
	//cout<<ans1<<endl<<ans2<<endl;
	cha=ans1-ans2;
	if(f(1)<=0) cout<<1;
	else if(f(n)>=0) cout<<n;
	else
	{ 
		//cout<<cha<<" "<<m<<" "<<s2<<endl;
		if(cha>=0)  x1=cha/s2+m,x2=(cha+s2-1)/s2+m;
		else  x1=-(-cha/s2)+m,x2=-(-cha+s2-1)/s2+m;
		//cout<<x1<<" " <<x2<<endl;
		if(abs(f(x1))<=abs(f(x2))) cout<<x1;
		else cout<<x2;
	} 
} 
/*
6 
2 3 2 3 2 3 
4 6 5 2 
*/
