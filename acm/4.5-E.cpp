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
using namespace std;
#define db double
db y,kk;int T;
db random()
{
    return 0.01*(rand()%100+1);
}
db F(db x)
{
    return 6*pow(x,7)+8*pow(x,6)+7*pow(x,3)+5*pow(x,2)-y*x;
}
db mnth()
{
    db tem=100,r=0.97;
    db pos=0;
    while(tem>=1e-8)
    {
        db next=pos+pow(-1,rand()%2)*tem;
        if(next>=0&&next<=100)
        {
            if(F(next)+1e-8<=F(pos)) pos=next;
            /*else {
                db gayl=pow(2.7,(-F(next)+F(pos)));
                if(random()<gayl) pos=next;
            }*/
        }
        next=pos-pow(-1,rand()%2)*tem;
        if(next>=0&&next<=100)
        {
            if(F(next)+1e-8<=F(pos)) pos=next;
            /*else {
                db gayl=pow(2.7,(-F(next)+F(pos)));
                if(random()<gayl) pos=next;
            }*/
        }
        tem*=r;
    }
    return F(pos);
}
int main()
{
    scanf("%d",&T);
     kk=random();
    while(T--)
    {
        scanf("%lf",&y);
        db haha=11000000000000;
        int wo=1000;
        //while(wo--)
        haha=min(haha,mnth());
        printf("%.4lf\n",haha);
    }
    return 0;
}
