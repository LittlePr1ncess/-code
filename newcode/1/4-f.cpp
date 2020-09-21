#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T,a,b,c,d;

    cin>>T;
    while(T--)
    {
        cin>>a>>b>>c>>d;
        if(a<b){
            if(d>b&&c<d) cout<<"AB//DC"<<endl;
            else cout<<"AB//CD"<<endl;
        }
        else{
            if(c>a&&d<c) cout<<"AB//CD"<<endl;
            else cout<<"AB//DC"<<endl;
        }
    }
}