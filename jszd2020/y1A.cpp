#include<bits/stdc++.h>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
#define MN 30
int a[MN][MN],con,tot,bu[10],emm;
string s;
struct lll{
    int x, y;
}ans[MN*MN];
bool cmp (lll a,lll b)
{
    if(a.x == b.x) return a.y<b.y;
    else return a.x<b.x;
}
int parse(char c)
{
    if(c=='.') return 2;
    if(c=='o') return 0;
    if(c=='x') return 1;
}
int heng(int x,int y)
{
    int l=0,r=0;
    so(i,1,5,1)
    {
        if(x-i<0||i==5) {l=i-1;break;}
        if(a[x-i][y]!=con) {l = i-1;break;}
    }
    so(i,1,5,1)
    {
        if(x+i>24||i==5) {r=i-1;break;}
        if(a[x+i][y]!=con) {r = i-1;break;}
    }
    return l+r;
}
int zong(int x,int y)
{
    int l=0,r=0;
    so(i,1,5,1)
    {
        if(y-i<0||i==5) {l=i-1;break;}
        if(a[x][y-i]!=con) {l = i-1;break;}
    }
    so(i,1,5,1)
    {
        if(y+i>24||i==5) {r=i-1;break;}
        if(a[x][y+i]!=con) {r = i-1;break;}
    }
    return l+r;
}
int xie1(int x,int y)
{
    int l=0,r=0;
    so(i,1,5,1)
    {
        if(x+i>24||y-i<0||i==5) {l=i-1;break;}
        if(a[x+i][y-i]!=con) {l = i-1;break;}
    }
    so(i,1,5,1)
    {
        if(x-i<0||y+i>24||i==5) {r=i-1;break;}
        if(a[x-i][y+i]!=con) {r = i-1;break;}
    }
    //if(x==7&&y==10) cout<<l<<" "<<r<<endl;
    return l+r;
}
int xie2(int x,int y)
{
    int l=0,r=0;
    so(i,1,5,1)
    {
        if(x-i<0||y-i<0||i==5) {l=i-1;break;}
        if(a[x-i][y-i]!=con) {l = i-1;break;}
    }
    so(i,1,5,1)
    {
        if(x+i>24||y+i>24||i==5) {r=i-1;break;}
        if(a[x+i][y+i]!=con) {r = i-1;break;}
    }
    //if(x==7&&y==10) cout<<l<<" "<<r<<endl;
    return l+r;
}
int main()
{
    so(i,0,24,1)
    {
        cin>>s;
        so(j,0,24,1)
        a[i][j]=parse(s[j]);
    }
   // so(i,0,24,1) {so(j,0,24,1) cout<<a[i][j];cout<<endl;}
    so(i,0,24,1) so(j,0,24,1) bu[a[i][j]]++;
    if(bu[0]<bu[1]) con = 0;
    else con = 1;
    //cout<<con<<endl;
    so(i,0,24,1) so(j,0,24,1)
    {
        int emm;
        if(a[i][j]!=2) continue;
        emm = heng(i,j);
        if(emm>=4) {ans[++tot].x=i,ans[tot].y=j;continue;}
        emm = zong(i,j);
        if(emm>=4) {ans[++tot].x=i,ans[tot].y=j;continue;}
        emm = xie1(i,j);
        if(emm>=4) {ans[++tot].x=i,ans[tot].y=j;continue;}
        emm = xie2(i,j);
        if(emm>=4) {ans[++tot].x=i,ans[tot].y=j;continue;}
    }
    sort(ans+1,ans+1+tot,cmp);
    so(i,1,tot,1) cout<<ans[i].x<<" "<<ans[i].y<<endl;
    if(tot==0) cout<<"tie"<<endl;
    //cin>>s;
}
/*
xxxx...xxxx...............
.........................
...........o.o.o.o.......
................oo.......
...............o..o......
.........................
...........o.............
..........xo.............
.........x.oo............
...........o.............
.......x.................
......x..................
.....x...................
.........................
.........................
.........................
.........................
.........................
.........................
.........................
.........................
.........................
.........................
.........................
.........................
*/