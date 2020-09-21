#include<iostream>
#include<cstring>
#include<string>
using namespace std;
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
string s[20][2000];
int T,n;
string doo(string s)
{
    so(i,0,s.size()-1,1)
    if(s[i]=='C') s[i] = 'P';
    else s[i] = 'C';
    return s;
}
int main()
{
    s[1][1] = "CC";
    s[1][2] = "PC";
    so(i,2,10,1)
    {
        so(j,1,1<<(i-1),1)
        {
            s[i][j] += s[i-1][j]+s[i-1][j]; 
        }
        so(j,(1<<(i-1))+1,1<<i,1)
        {
            s[i][j] += doo(s[i-1][j-(1<<(i-1))])+s[i-1][j-(1<<(i-1))]; 
        }
    }
    cin>>T;
    while(T--)
    {
        cin>>n;
        so(i,1,1<<(n),1)
        cout<<s[n][i]<<endl;
    }
    //cin>>n;
}