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
int sum;char s[100];int ans[100],b[100];int rwz[10];
int main()
{
	while(~scanf("%d%s",&sum,&s))
	{
		//cout<<s;
		if(sum==0) break;
		so(i,'A','Z',1) b[i]=0;so(i,1,5,1) ans[i]=0;
		so(i,0,strlen(s)-1,1) b[s[i]]=1;
		//so(i,'A','Z',1) cout<<b[i]<<" ";
		so(vv,'A','Z',1)so(ww,'A','Z',1)so(xx,'A','Z',1)so(yy,'A','Z',1)so(zz,'A','Z',1)
		{
			int v=vv-'A'+1;int w=ww-'A'+1;int x=xx-'A'+1;int y=yy-'A'+1;int z=zz-'A'+1;
			//rwz[1]=vv;rwz[2]=ww;rwz[3]=xx;rwz[4]=yy;rwz[5]=zz;
			//sort(rwz+1,rwz+6);int flag=0;so(i,1,5,1) if(rwz[i]==rwz[i-1]) flag=1;
			//if(flag) continue;
			if(ww==vv) continue;if(ww==xx||xx==vv) continue;if(yy==xx||yy==ww||yy==vv) continue;
			if(zz==vv||zz==ww||zz==yy||zz==xx) continue;
			if(b[vv]==0) continue;if(b[ww]==0) continue;if(b[xx]==0) continue;if(b[yy]==0) continue;if(b[zz]==0) continue;	
			if(v-w*w+x*x*x-y*y*y*y+z*z*z*z*z==sum) ans[1]=vv,ans[2]=ww,ans[3]=xx,ans[4]=yy,ans[5]=zz;
		}
		
		if(ans[1]==0) {
			cout<<"no solution"<<endl;
			continue;
		}
		so(i,1,5,1) cout<<char(ans[i]);cout<<endl;
	}
	return 0;

}

