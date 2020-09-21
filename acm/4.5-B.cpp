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
db x,y,l,d;int T;
db random()
{
    return 0.01*(rand()%100+1);
}
db F(db t)
{
    return -(l*cos(t)+(d-x*cos(t))/sin(t));
}
db mnth()
{
    db tem=1,r=0.8;
    db pos=0;
    while(tem>=1e-4)
    {
        db next=pos+pow(-1,rand()%2)*tem;
        if(next>=0&&next<=3.14/2.0)
        {
            if(F(next)<=F(pos)) pos=next;
            /*else {
                db gayl=pow(2.7,(-F(next)+F(pos)));
                if(random()<gayl) pos=next;
            }*/
        }
        next=pos-pow(-1,rand()%2)*tem;
        if(next>=0&&next<=3.14/2.0)
        {
            if(F(next)<=F(pos)) pos=next;
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
    while(cin>>x>>y>>l>>d)
    {
        db haha=0;
        int wo=100;
        while(wo--)
        haha=min(haha,mnth());
        haha*=-1;
        //cout<<haha<<":";
        if(haha>y) cout<<"no"<<endl;
        else cout<<"yes"<<endl;
    }
    return 0;
}
