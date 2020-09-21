#include<bits/stdc++.h>
using namespace std;
#define MN 100005 
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
struct lll{
	string name;int k1,k2,k3,k4;
}a[MN];
int n,bu[20];string s;
void sortt(int x)
{
	a[x].k1=a[x].k2=a[x].k3=a[x].k4=0; 
	bool flag =0;
	if(bu[10]&&bu[11]&&bu[12]&&bu[13]&&bu[1])
	{
		a[x].k1=8;return ;
	}
//---------------------------	
	so(i,1,9,1)
	{
		so(j,0,4,1)
		{
			if(!bu[i+j]) break;
			if(j==4) a[x].k1=7,a[x].k2=i+j,flag=1; 
		} 
	}
	if(flag ) return ;
//-------------------------------
	so(i,1,13,1) 
	if(bu[i]>=4) a[x].k1=6,a[x].k2=i,a[x].k3=0,flag=1;
	if(flag)  
	{
		so(i,1,13,1) a[x].k3+=i*bu[i];
		a[x].k3-=4*a[x].k2;
		return ;	
	}
//--------------------------------	
	int tr=0;
	so(i,1,13,1) 
	if(bu[i]>=3) tr=i;
	if(tr) {
		so(i,1,13,1) if(i!=tr&&bu[i]>=2)
		a[x].k1=5,a[x].k2=tr,a[x].k3=i,a[x].k4=0,flag=1;
	}
	if(flag){
		so(i,1,13,1) a[x].k4+=bu[i]*i;
		a[x].k4-=3*a[x].k2;
		a[x].k4-=2*a[x].k3;
		return ;
	}	
//----------------------------------
	so(i,1,13,1)
	if(bu[i]>=3) a[x].k1=4,a[x].k2=i,a[x].k3=0,flag=1;
	if(flag){
		so(i,1,13,1) a[x].k3+=bu[i]*i;
		a[x].k3-=3*a[x].k2;
		return ;
	}	
//-------------------------------------
	int db=0;
	so(i,1,13,1) 
	if(bu[i]>=2) db = i;
	if(db)
	{
		so(i,1,13,1) if(i!=db&&bu[i]>=2) 
		a[x].k1=3,a[x].k2=db,a[x].k3=i,a[x].k4=0,flag=1;
	}
	if(flag){
		so(i,1,13,1) a[x].k4+=bu[i]*i;
		a[x].k4-=2*a[x].k2;
		a[x].k4-=2*a[x].k3;
		return ;
	}
//---------------------------------------
	so(i,1,13,1) if(bu[i]>=2) a[x].k1=2,a[x].k2=i,a[x].k3=0,flag=1;
	if(flag )
	{
		so(i,1,13,1) a[x].k3+=bu[i]*i;
		a[x].k3-=2*a[x].k2;
		return ;
	}
//--------------------------------------
	a[x].k1=1;	so(i,1,13,1) a[x].k2+=bu[i]*i;
}
bool cmp(lll a,lll b)
{
	if(a.k1==b.k1)
	{
		if(a.k2==b.k2)
		{
			if(a.k3==b.k3)
			{
				if(a.k4==b.k4)
				{
					return a.name<b.name;
				}
				return a.k4>b.k4;
			}
			return a.k3>b.k3;
		}
		return a.k2>b.k2;
	}
	return a.k1>b.k1;
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(~scanf("%d",&n))
	{
		so(i,1,n,1)
		{
			cin>>a[i].name>>s;
			memset(bu,0,sizeof(bu));
			so(j,0,s.size()-1,1)
			{
				if(s[j]=='1') {
					bu[10]++;j++;continue;
				}
				if(s[j]=='A') s[j]=1+'0';
				if(s[j]=='J') s[j]=11+'0';
				if(s[j]=='Q') s[j]=12+'0';
				if(s[j]=='K') s[j]=13+'0';
				bu[s[j]-'0']++;
			}
			sortt(i);
		}
		sort(a+1,a+1+n,cmp);
		so(i,1,n,1) cout<<a[i].name<<endl;
		
		/*so(i,1,n,1) 
		cout<<a[i].name,
		printf(" %d %d %d %d\n",a[i].k1,a[i].k2,a[i].k3,a[i].k4); */
	}
} 
