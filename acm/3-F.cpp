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
struct lll{
int r;
char c;
}p[900];
int r,c;
int flag=0;

int vis[30][30];

const int dx[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
const int dy[8] = {-2, -2, -1, -1, 1, 1, 2, 2};

void dfs(int si,int sj,int dep)
{
    p[dep].r=si;
    p[dep].c='A'+sj-1;
    if(dep==r*c){
        flag=1;
        return;
    }
    for(int i=0;i<8;i++)
	{
            int sii=si+dx[i];
            int sjj=sj+dy[i];
            if(sii>0&&sii<=r&&sjj>0&&sjj<=c&&vis[sii][sjj]==0&&flag==0){
            vis[sii][sjj]=1;
            dfs(sii,sjj,dep+1);
            vis[sii][sjj]=0;
    }

    }

}
int main()
{
    int n,num=1;
    scanf("%d",&n);
    while(n){
        scanf("%d%d",&r,&c);
        memset(vis,0,sizeof(vis));
        vis[1][1]=1;
        dfs(1,1,1);
        printf("Scenario #%d:\n",num);
        if(flag==1){
            for(int i=1;i<=r*c;i++){
            printf("%c%d",p[i].c,p[i].r);
        }
        printf("\n\n");
        }
        else{
            printf("impossible\n\n");
        }
        flag=0;
        n--;
        num++;
    }
    return 0;
}

