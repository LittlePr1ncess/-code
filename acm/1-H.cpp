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
int cl[20],cc[20];string ans="999999999999999999999999999999999999";int tot;
int mapp[10][10]
={  0,0,0,0,0,0,0,0,0,0,
    0,1,1,0,1,1,0,0,0,0,
    0,1,1,1,0,0,0,0,0,0,
    0,0,1,1,0,1,1,0,0,0,
    0,1,0,0,1,0,0,1,0,0,
    0,0,1,0,1,1,1,0,1,0,
    0,0,0,1,0,0,1,0,0,1,
    0,0,0,0,1,1,0,1,1,0,
    0,0,0,0,0,0,0,1,1,1,
    0,0,0,0,0,1,1,0,1,1
};
bool check(int a,int b,int c,int d,int e,int f,int g,int h,int j)
{
	so(i,1,9,1) cc[i]=cl[i];
	//so(i,1,9,1) cout<<cc[i]<<" ";cout<<endl;
 	so(i,1,9,1 ) cc[i]+=a*mapp[1][i]+b*mapp[2][i]+c*mapp[3][i]+d*mapp[4][i]
					  +e*mapp[5][i]+f*mapp[6][i]+g*mapp[7][i]+h*mapp[8][i]+j*mapp[9][i];
	//so(i,1,9,1) cout<<cc[i]<<" ";cout<<endl;
	so(i,1,9,1) if(cc[i]%4) return 0;
	return 1;
}
int main()
{
	so(i,1,9,1) cin>>cl[i];
	//cout<<check(0,0,0,1,1,0,0,1,1); 
	so(a,0,3,1)so(b,0,3,1)so(c,0,3,1)so(d,0,3,1)so(e,0,3,1)so(f,0,3,1)so(g,0,3,1)so(h,0,3,1)so(i,0,3,1)
	{
		if(check(a,b,c,d,e,f,g,h,i)) 
		{
			//cout<<"wdnmd";
			//printf("%d %d %d %d %d %d %d %d %d\n",a,b,c,d,e,f,g,h,i);
			string s;
			so(j,1,a,1) s+='1';
			so(j,1,b,1) s+='2';
			so(j,1,c,1) s+='3';
			so(j,1,d,1) s+='4';
			so(j,1,e,1) s+='5';
			so(j,1,f,1) s+='6';
			so(j,1,g,1) s+='7';
			so(j,1,h,1) s+='8';
			so(j,1,i,1) s+='9';
			//cout<<s;
			if(s<ans) ans = s;
		}
	}
	//cout<<ans;
	so(i,0,ans.size()-1,1) cout<<ans[i]<<" ";
	return 0;

}

