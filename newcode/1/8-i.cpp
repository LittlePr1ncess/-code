#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
#define MN 100005
int T,x[MN],y[MN],z[MN*2],ans,n,num[MN*2],fa[MN*2],bu[2*MN];
int find(int x)
{
    return (fa[x]!=x)?fa[x]=find(fa[x]):x;
}
int main()
{
    cin>>T;
    for(int emm=1;emm<=T;emm++)
    {
        cin>>n;
        so(i,1,2*n,1) num[i]=0,fa[i]=i,bu[i]=0;
        ans=0;
        so(i,1,n,1) 
        {
            cin>>x[i]>>y[i];
            z[i]=x[i],z[i+n]=y[i];
        }
        sort(z+1,z+1+n+n);
        int size = unique(z+1,z+1+n+n)-z-1;
        //cout<<size<<endl;
        //so(i,1,size,1) cout<<z[i]<<" ";cout<<endl;
        so(i,1,n,1) x[i]=lower_bound(z+1,z+1+size,x[i])-z,y[i]=lower_bound(z+1,z+1+size,y[i])-z;
        //so(i,1,n,1) cout<<x[i]<<" "<<y[i]<<endl;
        so(i,1,n,1)
        {
            if(find(x[i])==find(y[i])) num[find(x[i])]++;
            else num[find(y[i])]+=num[find(x[i])]+1,fa[find(x[i])]=find(y[i]);
            /*cout<<i<<endl;
            so(i,1,2*n,1)
            {
                cout<<fa[i]<<" "<<num[i]<<endl;
            }
            cout<<endl;*/
        }
        so(i,1,2*n,1) {bu[find(i)]++;}
        so(i,1,2*n,1)
        {
            //cout<<fa[i]<<" "<<num[i]<<endl;
            if(fa[i]==i) ans+=min(num[i],bu[i]);
        }
        cout<<"Case #"<<emm<<": "<<ans<<endl;
    }
    system("pause");
    return 0;
}
/*
1
6
1 2
1 3
3 2
2 4
2 5
2 6

1
6
11 22
11 33
33 22
22 44
22 55
22 66
*/