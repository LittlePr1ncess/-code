#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<list>
#include<vector>
#include<set>
using namespace std;
typedef long long LL;
typedef pair<int,int>pii;
const int maxn=10010;
char s[maxn];
char MaxPal[maxn];
char str[55][maxn];
int ans=0;
void rev(char *a){
    int len=strlen(a);
    for(int i=0;i<len/2;++i){
        char temp=a[i];a[i]=a[len-i-1];
        a[len-i-1]=temp;
    }
}
void Sub(char *a,char *b){
    int lena=strlen(a),lenb=strlen(b);
    rev(a);rev(b);int q=0;
    for(int i=lenb;i<=lena;++i){b[i]='0';}
    for(int i=0;i<lena;++i){
        if((a[i]-'0'-q)>=(b[i]-'0')){
            a[i]=((a[i]-'0')-q-(b[i]-'0'))+'0';q=0;
        }
        else {
            a[i]=((a[i]-'0')+10-q-(b[i]-'0'))+'0';q=1;
        }
    }int i;
    for(i=lena-1;i>=0;--i){
        if(a[i]!='0'){a[i+1]=0;break;}
    }rev(a);
}
void Find(char *temp){
    int len=strlen(temp);bool sign=true;
    for(int i=0;i<len/2;++i){
        if(temp[i]!=temp[len-i-1]){
            sign=false;break;
        }
    }
    if(sign){strcpy(MaxPal,temp);return ;}
    if(len&1){
        for(int i=len/2-1;i>=0;--i){
            if(temp[i]!=temp[len/2+len/2-i]){
                if(temp[i]<temp[len/2+len/2-i]){
                    for(int j=0;j<len/2+len/2-i;++j){
                        MaxPal[j]=temp[j];
                    }
                    for(int j=len/2+len/2-i;i>=0;++j,--i){
                        MaxPal[j]=temp[i];
                    }MaxPal[len]=0;
                    return ;
                }
                else {
                    int k;
                    for(k=len/2;k>=0;--k){
                        if(temp[k]!='0'){break;}
                    }
                    for(int j=0;j<k;++j){
                        MaxPal[j]=temp[j];
                    }MaxPal[k]=MaxPal[len-k-1]=temp[k]-1;
                    for(int j=k+1;j<len-k-1;++j){
                        MaxPal[j]='9';
                    }k-=1;
                    for(int j=len-k-1;k>=0;--k,++j){
                        MaxPal[j]=temp[k];
                    }MaxPal[len]=0;
                    if(MaxPal[0]=='0'){
                        for(int j=0;j<len-1;++j){
                            MaxPal[j]='9';
                        }
                        MaxPal[len-1]=0;
                    }
                    return ;
                }
            }
        }
    }
    else {
        for(int i=len/2-1;i>=0;--i){
            if(temp[i]!=temp[len-i-1]){
                if(temp[i]<temp[len-i-1]){
                    for(int j=0;j<len-i-1;++j){
                        MaxPal[j]=temp[j];
                    }
                    for(int j=len-i-1;i>=0;++j,--i){
                        MaxPal[j]=temp[i];
                    }MaxPal[len]=0;
                    return ;
                }
                else {
                    int k;
                    for(k=len/2-1;k>=0;--k){
                        if(temp[k]!='0'){break;}
                    }
                    for(int j=0;j<k;++j){
                        MaxPal[j]=temp[j];
                    }MaxPal[k]=MaxPal[len-k-1]=temp[k]-1;
                    for(int j=k+1;j<len-k-1;++j){
                        MaxPal[j]='9';
                    }k-=1;
                    for(int j=len-k-1;k>=0;--k,++j){
                        MaxPal[j]=temp[k];
                    }MaxPal[len]=0;
                    if(MaxPal[0]=='0'){
                        for(int j=0;j<len-1;++j){
                            MaxPal[j]='9';
                        }MaxPal[len-1]=0;
                    }
                    return ;
                }
            }
        }
    }
}
void Solve(char *temp){
    Find(temp);strcpy(str[ans++],MaxPal);
    if(strcmp(temp,MaxPal)==0)return ;
    Sub(temp,MaxPal);Solve(temp);
}
int main()
{
    int t,Test=1;cin>>t;
    while(t--){
        scanf("%s",s);
        Find(s);
        ans=0;Solve(s);
        printf("Case #%d:\n%d\n",Test++,ans);
        for(int i=0;i<ans;++i){
            printf("%s\n",str[i]);
        }
    }
    return 0;
}
