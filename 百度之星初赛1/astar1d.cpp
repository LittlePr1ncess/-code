#include<bits/stdc++.h>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
int init[5][5],T,ans,x,y,mapp[510][510],wz[30],tot;int n;
int work(int i)
{
    int t=1,sum=0,p=1;
    while(1)
    {
        sum+=i;
        so(i,1,p-1,1) sum+=-wz[i];
        if(sum>=8*p*p) p++;
        if(p>=9) return t;
        //if(sum>=512) return t;
        t++;
    }
}
int main()
{
    //so(i,1,3,1) so(j,1,3,1) init[i][j]=work(i,j);
    //so(i,1,3,1) {so(j,1,3,1) cout<<init[i][j]<<" ";cout<<endl;}
    //freopen("a.txt","r",stdin);
    cin>>T;
    while(T--)
    {
        ans=2100000000;
        cin>>n>>x>>y;
        so(i,1,n,1) so(j,1,n,1) cin>>mapp[i][j];
        so(i,1,n,1) so(j,1,n,1) if(mapp[i][j]==0) cout<<"???";
        so(i,1,n,1) so(j,1,n,1)
        {
            tot=0;
            so(a,max(1,i-3),min(i+3,n),1) so(b,max(1,j-3),min(j+3,n),1) 
            {
                if(abs(a-i)+abs(b-j)>3) continue;
                if(a==i&&b==j) continue;
                wz[++tot]=-mapp[a][b];
            }
            sort(wz+1,wz+1+tot);
            //if(i==54&&j==54) cout<<mapp[i][j]<<"#"<<int((abs(i-x)+abs(j-y)+1)/2)<<"$"<<init[mapp[i][j]][wz]<<"%"; 
            //if(init[mapp[i][j]][wz]<=0) cout<<i<<" "<<j<<" "<<mapp[i][j]<<" "<<wz<<endl;
            ans=min(ans,work(mapp[i][j])+int((abs(i-x)+abs(j-y)+1)/2));
        }
        cout<<ans<<endl;
    }
    //while(1) cin>>x;
}
/*
1
10 9 9
1 2 2 1 2 3 1 1 2 1
2 1 3 3 3 2 3 2 3 1
1 1 3 1 1 3 2 2 1 2
3 1 3 1 3 3 1 3 1 3
3 2 3 1 3 1 2 2 2 1
2 3 2 3 2 2 3 1 2 3
3 1 3 3 2 2 3 2 3 3
1 3 3 2 3 2 2 2 1 1
3 3 1 2 3 2 1 2 1 2
1 1 3 1 3 1 1 1 3 3
*/