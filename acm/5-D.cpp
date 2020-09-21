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
const int kRoot = 1000;
int N,K, P; 
bool dfs(int i,int a,int p)
{
	if(p != kRoot){
		if(--K == 0){
			printf("Process ID=%d, A=%d\n",p,a);
			return 1;
		}
	}
	while(i < N){
		if(--K == 0){
			printf("Loop %d: Process ID=%d\n",i,p);
			return 1;
		}
		a+=7;
		if(dfs(++i,a,++P)) return 1;
	}
	return 0;
}
 
int main()
{
	int t;
	for(scanf("%d",&t);t--;){
		scanf("%d%d",&N,&K);
		dfs(0,0,P=kRoot);
	}
	return 0;
}

