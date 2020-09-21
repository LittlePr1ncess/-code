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
const int maxn=10005;
int a[maxn];
int main()
{
    int n,m;
    scanf("%d",&n);
    so(k,0,n-1,1)
    {
        int sum=0;
        scanf("%d",&m);
        so(i,1,m,1)
        scanf("%d",&a[i]);
        sort(a+1,a+m+1);
        for(int i=m;i>=1;i-=2)
        {
            if(i==3)
            {
                sum+=a[1]+a[2]+a[3];
                break;
            }
            if(i==2)
            {
                sum+=a[2];
                break;
            }
            if(i==1)
            {
                sum+=a[1];
                break;
            }
            else sum+=min(a[1]+2*a[2]+a[i],2*a[1]+a[i]+a[i-1]);
        }
        printf("%d\n",sum);
    }
}
