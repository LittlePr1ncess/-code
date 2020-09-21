#include<bits/stdc++.h>
using namespace std;
#define db double
#define MN 10000010
const db pi=acos(-1.0);
struct cpx{
	db x,y;
	cpx(db xx=0,db yy=0){x=xx,y=yy;}
}a[MN],b[MN];
int limit=1,r[MN],rwz[MN],l;
cpx operator + (cpx a,cpx b){ return cpx(a.x+b.x , a.y+b.y);}
cpx operator - (cpx a,cpx b){ return cpx(a.x-b.x , a.y-b.y);}
cpx operator * (cpx a,cpx b){ return cpx(a.x*b.x-a.y*b.y , a.x*b.y+a.y*b.x);}
void FFT(cpx *a,int emm)
{

	for(int i=0;i<limit;i++) if(i<r[i]) swap(a[i],a[r[i]]);
	for(int i=1;i<limit;i<<=1)
	{
		cpx wn(cos(pi/i),emm*sin(pi/i));
		// w_{2n}
		for(int R=(i<<1),j=0;j<limit;j+=R)
		{
			cpx w(1,0);
			for(int k=0;k<i;k++,w=w*wn)
			{
				cpx x=a[j+k],y=w*a[j+i+k];
				a[j+k]=x+y;
				a[j+i+k]=x-y;
			}
		}
	}
}
int btfl(int x)
{
    int ans = 0,tt = 0;
    for(int i=1;i<=l;i++)
    {
        rwz[i]=x&1;
        x>>=1;
    }
    for(int i=1;i<=l;i++)
    ans<<=1,ans+=rwz[i];
    return ans;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	so(i,0,n,1) cin>>a[i].x;//scanf("%lf",&a[i].x);
	so(i,0,m,1) cin>>b[i].x;//scanf("%lf",&b[i].x);
	while(limit<=n+m) limit<<=1,l++;
	for(int i=0;i<limit;i++) r[i]=btfl(i);
	//rev[i]=(rev[i>>1]>>1)|((i&1)<<(l-1));
	FFT(a,1);FFT(b,1);
	for(int i=0;i<=limit;i++) a[i]=a[i]*b[i];
	FFT(a,-1);
	for(int i=0;i<=n+m;i++) printf("%d ",(int)(a[i].x/limit+0.5));
	
   // cin>>n;
    return 0;
} 