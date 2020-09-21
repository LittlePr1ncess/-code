#include<bits/stdc++.h>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
#define MN 100005
int T,n,a[MN],b[MN],key,zero,tot,f;
int main()
{
    //freopen("a.txt","r",stdin);
    cin>>T;
    while(T--)
    {
        cin>>n;
        zero = 0,tot=0,f=0;b[0]=0;
        so(i,1,n,1) cin>>a[i];
        sort(a+1,a+1+n);
        so(i,1,n,1)
        {
            if(!a[i]) tot = i;
        }
        swap(a[1],a[tot+1]);swap(a[2],a[tot+2]);
        key = a[1];
        int yu = 0;
        a[1]=0;
        for(int i=n;i>=1;i--)
        {
            int tmp = a[i];
            a[i]=(tmp*key+yu)%10;
            yu = (tmp*key+yu)/10;
        }
        so(i,1,n,1)
        {
            if(i==1&&a[i]==0) continue; 
            cout<<a[i];
        }
        //so(i,1,zero,1) cout<<0;
        cout<<endl;
    }
    //system("pause");
}