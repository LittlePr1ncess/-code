#include<bits/stdc++.h>
using namespace std;
struct lll{
    int a;int b;int c;
};
int main()
{
    struct lll s[100]={1,2,3};
    cout<<s[0].c;
    int x=1,a=0,b=0;
    switch(x)
    {
        case 2:a++;b++;
        case 1:++a;b--;break;
    }
    cout<<x<<" "<<a<<" "<<b;
    system("pause");
}