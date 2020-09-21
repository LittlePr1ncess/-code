#include<bits/stdc++.h>
using namespace std;
#define MN 100005
int n,a[MN],b[2][MN],tot,cnt,flag,con;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),b[0][i]=a[i];
	con=0;tot=n;
	while(1)
	{
		cnt=0;
		sort(b[con]+1,b[con]+1+tot);
		for(int i=tot;i>tot/2;i--) 
		if(i!=tot-i+1)b[con^1][++cnt]=abs(b[con][i]-b[con][tot-i+1]); 
		else b[con^1][++cnt]=b[con][i];
		
		con^=1;tot=cnt;
		if(tot<=1&&b[con][1]==0){
			flag=1;break;
		}
		if(tot<=1&&b[con][1]!=0){
			flag=0;break;
		}
	}
	if(flag==0) cout<<"NO";
	else cout<<"YES";
	
	return 0;
} 
