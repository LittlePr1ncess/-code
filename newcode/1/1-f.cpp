#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a,b;
    while(cin>>a>>b)
    {
        string c="",d="";
        a=a+a,b=b+b;
        int la=a.size(),lb=b.size();
        if(la>lb){
            for(int i=0;i<la;i++)
            d+=(b[i%lb]);
            c=a;
        }
        else{
            for(int i=0;i<lb;i++)
            c+=a[i%la];
            d=b;
        }
        //cout<<c<<endl<<d<<endl;
        if(c>d)  cout<<">"<<endl;
        if(c<d)  cout<<"<"<<endl;
        if(c==d) cout<<"="<<endl;
    }
}