#include<bits/stdc++.h>
using namespace std;
#define M(x,y) make_pair(x,y)
pair<int,int>a[100];
int lk[1000];
int check()
{
    int sum = 0;
    for(int i=0,j=1;j<=10;i=lk[i],j++)
    {
        cout<<a[lk[i]].first<<" "<<a[lk[i]].second<<endl;
    }
    system("pause");
    for(int x=1;x<=5;x++){
        int e =0,s=0;
        for(int i=0,j=1;j<=10;i=lk[i],j++)
        {
            if(a[lk[i]].first==x||a[lk[i]].second==x) {s = j;break;}
        }
        for(int i=0,j=1;j<=10;i=lk[i],j++)
        {
            if(a[lk[i]].first==x||a[lk[i]].second==x) {e = j;}
        }
        sum+=e-s+1;
        cout<<1+e-s<<" "<<x<<endl;
    }
    //cout<<sum<<" ";
    system("pause");
    exit(0);
    return sum;
}
int main()
{
    a[1] = M(1,2);a[2] = M(1,3);a[3] = M(1,4);a[4] = M(2,3);a[5] = M(2,4);a[6] = M(3,4);
    a[7] = M(1,5);a[8] = M(2,5);a[9]=M(3,5);a[10]=M(4,5);
    lk [1] = 2;lk[2]=3;lk[3]= 4;lk[4]=5;lk[5]=6;lk[0]=1;
    for (int i=0;i<=5;i++)
    {
        lk[7]=lk[i];lk[i]=7;
        
        for(int j=0;j<=6;j++)
        {   
            lk[8] = lk[j];lk[j]=8;
            for(int k=0;k<=7;k++)
            {
                lk[9]= lk[k];lk[k]=9;
                for(int l =0;l<=8;l++)

                {   
                    lk[10]=lk[l];lk[l]=10;
                    if(i==0&&j==1&&k==2&&l==0) check();// {cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl;break;}
                    lk[l]=lk[10];
                }
            }
            lk[j]=lk[8];
        }
        lk[i] = lk[7];
    }
    system("pause");
}
/*
1 2
1 3
2 3

4 5
1 5
2 5
3 5
1 2
1 3
1 4
2 3
2 4
3 4
*/