#include<bits/stdc++.h>
using namespace std;
#define LL long long 
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
#define MN 100005
int T,n,bu[MN],a[MN][5],b[MN],x[MN],y[MN],z[MN],tot[MN],cnt;
void work(int zu,int p,int qd)
{
	cout<<p<<" ";cnt++;
	if(cnt==n-2)
	{
		cout<<qd<<" ";
		if(p!=x[zu]&&x[zu]!=qd) cout<<x[zu]<<" "; 
		if(p!=y[zu]&&y[zu]!=qd) cout<<y[zu]<<" "; 
		if(p!=z[zu]&&z[zu]!=qd) cout<<z[zu]<<" "; 
	}
	/*cout<<endl;
	cout<<zu<<" "<<x[zu]<<" "<<y[zu]<<" "<<z[zu]<<" "<<qd<<endl;
	so(i,1,n,1) cout<<b[i]<<" ";
	cout<<endl;
	cout<<endl; */
	b[zu]=1;
	bu[x[zu]]--;bu[y[zu]]--;bu[z[zu]]--;
	if(bu[x[zu]]==1) 
	{
		so(i,1,tot[x[zu]],1) 
		if(!b[a[x[zu]][i]]&&(qd==0||x[zu]==qd)) 
		work(a[x[zu]][i],x[zu],((y[zu]==p)?z[zu]:y[zu]));
	}
	
	if(bu[y[zu]]==1) 
	{
		so(i,1,tot[y[zu]],1) 
		if(!b[a[y[zu]][i]]&&(qd==0||y[zu]==qd)) 
		work(a[y[zu]][i],y[zu],((x[zu]==p)?z[zu]:x[zu]));
	}
	
	if(bu[z[zu]]==1) 
	{
		so(i,1,tot[z[zu]],1) 
		if(!b[a[z[zu]][i]]&&(qd==0||z[zu]==qd)) 
		work(a[z[zu]][i],z[zu],((y[zu]==p)?x[zu]:y[zu]));
	}
} 
int main()
{
	int last;
	cin>>n;
	so(i,1,n-2,1) 
	{
		cin>>x[i]>>y[i]>>z[i];
		a[x[i]][++tot[x[i]]]=i;
		a[y[i]][++tot[y[i]]]=i;
		a[z[i]][++tot[z[i]]]=i;
		bu[x[i]]++;bu[y[i]]++;bu[z[i]]++;
	}
	so(i,1,n,1) if(bu[i]==1) {last=i;break;}
	work(a[last][1],last,0);
} 
/*
7
1 2 7
2 4 5
7 2 4
4 5 3
3 5 6

 
*/ 
