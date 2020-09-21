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
struct node{
	int l,w,m;
}p[10000];
int cmp(node a,node b)    
{
	if(a.l==b.l) 
	return a.w<b.w;
	else
	return a.l<b.l;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,ans,x;
		ans=x=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d %d",&p[i].l,&p[i].w);
			p[i].m=0;
		}
		sort(p,p+n,cmp);
	    	for(int i=0;i<n;i++)
	    	{
	    		if(p[i].m==1) continue;   
	    		node p1;
	    		p1.l=p[i].l,p1.w=p[i].w;    
				p[i].m=1;                
	    		ans++;                   
	    		for(int j=i;j<n;j++)
	    		{
	    			if(p[j].l>=p1.l&&p[j].w>=p1.w&&p[j].m==0)
	    			{
	    				p[j].m=1;
	    				p1.l=p[j].l;
	    				p1.w=p[j].w;
					}
				}
		    }
		    printf("%d\n",ans);
	}
}
