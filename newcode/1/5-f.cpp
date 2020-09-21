#include<bits/stdc++.h>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
int n;long long a[200];long long M=0;
void work(int a,int s)
{
    cout<<"+";so(i,1,s,1) cout<<"-";cout<<"+"<<endl;
    if(a!=M){cout<<"|";so(i,1,s,1) cout<<" ";cout<<"|"<<a<<endl;}
    else {cout<<"|";so(i,1,s-1,1) cout<<" ";cout<<"*"<<"|"<<a<<endl;}
    cout<<"+";so(i,1,s,1) cout<<"-";cout<<"+"<<endl;
    //cout<<s<<endl;
}
int main()
{
    cin>>n;
    so(i,1,n,1)cin>>a[i],M=max(M,a[i]);
    so(i,1,n,1) work(a[i],ceil(50.0*a[i]/M));
    //system("pause");
}