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
LL A,B,C,k,g,x,y;
void exgcd(LL a,LL b,LL &d,LL &x,LL &y)
{
	if(!b) {
		d=a;x=1;y=0;
	}
	else exgcd(b,a%b,d,y,x),y-=x*(a/b);

}
int main()
{
	while(cin>>A>>B>>C>>k)
	{
		if(!k) break;
		exgcd(C,1<<k,g,x,y);
		if(((B-A)%g)!=0) {
			cout<<"FOREVER"<<endl;
			continue;
		}
		 LL x0=(B-A)/g*x;
		 
		LL bg=(1<<k)/g;
		if(bg<0) bg*=-1;//cout<<bg<<endl;
		x0=(x0%bg+bg)%bg;
		cout<<x0<<endl;
	}
	return 0;

}

