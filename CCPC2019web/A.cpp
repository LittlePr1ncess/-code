#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#define MN 200
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
#define LL long long
#define db double
using namespace std;
struct lll{
    db m[MN][MN];
}a,k;
int n,T;
db sum;
lll work(lll a)
{
    lll temp;
    so(x,1,n,1) so(y,1,n,1)
    {
        LL ans = 1;
        so(i,1,min(3,n-x+1),1) so(j,1,min(n-y+1,3),1)
        ans += a.m[x+i-1][y+i-1]*k.m[i][j];
        ans/=sum;
        temp.m[x][y] = ans;
    }
    return temp;
}
int main()
{
    cin>>n>>T;
    so(i,1,n,1) so(j,1,n,1) cin>>a.m[i][j];
    so(i,1,3,1) so(j,1,3,1) cin>>k.m[i][j],sum+=k.m[i][j];
    //so(i,1,T,1) sum[i] = sum[i-1]*sum[0];
    so(rwz,1,T,1)
    {
        a=work(a); 
        so(i,1,n,1) {so(j,1,n,1) printf("%.6f ",(1.0*a.m[i][j]));cout<<endl;}cout<<endl;
    }
    system("pause");
    return 0;
}
/*
3 10
9 9 9
 

3 10
1 2 3
4 5 6
7 8 9
0 0 0
0 3 0
0 0 0

3 10
3 3 3
3 3 3
3 3 3
1 1 1
1 1 1
1 1 1

*/