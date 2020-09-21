#include<bits/stdc++.h>
using namespace std;
bool iff(int x)
{
    for (int i=2;i*i<=x;i++)
    if(x%i==0) return 0;
    return 1;
}
int b[1000000];
int main()
{
    for(int n=3;n<=100000;n++)
    {
        memset(b,0,sizeof(b));
        if(!iff(n)) continue;
        int emm = 1;
        b [1] = 1;
        for(int j=2;j<=n;j++)
        {
            if(b[(emm*3%n)]) {
                cout<<n<<endl;
                system("pause");
                cout<<"123213iojcjwd"<<endl;
            }
            b[(emm *3)%n]=1;
        }
    }
}