#include<bits/stdc++.h>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
#define LL long long 
#define db double
int T,a,b;
int f(int x)
{return min(a+b-2*x,x);}

int main()
{
    cin>>T;
    while(T--)
    {
        cin>>a>>b;
        //int rwz=max(a,b);
        if(a>b) swap(a,b);
        int rwz=0;rwz=max(rwz,min(b-a,a));
        if(a>=(a+b)/3)rwz=max(rwz,f((a+b)/3));
        if(a>=((a+b)/3+1)) rwz=max(rwz,f((b+a)/3+1));
        cout<<rwz<<endl;
    }
   //system("pause");
}