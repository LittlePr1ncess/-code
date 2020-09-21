#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,l,r;
    scanf("%d:%d:%d",&a,&b,&c);
    l=a*3600+b*60+c;
    scanf("%d:%d:%d",&a,&b,&c);
    r=a*3600+b*60+c;
    if(l>r) swap(l,r);
    cout<<r-l;
   // system("pause");
}