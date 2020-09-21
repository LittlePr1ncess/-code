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
char s[1003][1003];
int poww(int n)
{
    int ans=1;
    for(int i=1; i<=n; i++)
        ans*=3;
    return ans;
}
void dfs(int n,int x,int y)
{
    if(n==1)
    {
        s[x][y]='X';
        return;
    }
    int d=poww(n-2);
    dfs(n-1,x,y);
    dfs(n-1,x,y+2*d);
    dfs(n-1,x+d,y+d);
    dfs(n-1,x+2*d,y);
    dfs(n-1,x+2*d,y+2*d);
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        if(n==-1)
            break;
        int d=poww(n-1);
        for(int i=0;i<d;i++)
        {
            for(int j=0;j<d;j++)
                s[i][j]=' ';
        }
        dfs(n,0,0);
        for(int i=0;i<d;i++)
        {
            for(int j=d;j>=0;j--)
            {
                if(s[i][j]=='X')
                {
                    s[i][j+1]='\0';
                    break;
                }
            }
        }
        for(int i=0;i<d;i++)
            printf("%s\n",s[i]);
        printf("-\n");
    }
}
