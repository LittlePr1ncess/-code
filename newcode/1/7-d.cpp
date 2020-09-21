#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;long long n;
    for(int i=1;i<=10000;i++)
    {
        if(int(sqrt(i*(i+1)*(2*i+1)/6))*int(sqrt(i*(i+1)*(2*i+1)/6))==i*(i+1)*(2*i+1)/6)
        printf("%d\n",i);
    }
    cin>>T;
    while(T--)
    {
        scanf("%lld",&n);
        if(n==1) printf("Fake news!\n");
        else printf("Nobody knows it better than me!\n");
    }
}