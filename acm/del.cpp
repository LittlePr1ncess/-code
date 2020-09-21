#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll pp(ll a,ll b,ll mod)
{
    a%=mod;
    b%=mod;
    ll sum=0;
    while(b)
    {
        if(b&1)
        {
            sum=(sum+a)%mod;
        }
        b>>=1;
        a=a*2%mod;
    }
    sum%=mod;
    return sum;
}//a*b%m
ll ff(ll a,ll b,ll mod)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
            ans=pp(ans,a,mod);
        a=pp(a,a,mod);
        b>>=1;
    }
    return ans;
}//a^b%m
bool isPrime_3( ll num )
{
        //������С�����⴦��
                 if(num ==2|| num==3 )return 1 ;
        //����6�ı��������һ����������
                 if(num %6!= 1&&num %6!= 5)return 0 ;
                 ll tmp =sqrt( num);
        //��6�ı��������Ҳ���ܲ�������
                 for(ll i= 5;i <=tmp; i+=6 )
                    if(num %i== 0||num %(i+ 2)==0 )return 0 ;
         //�ų����У�ʣ���������
                 return 1 ;
}//��������
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        ll w,p,q,z=1,ny;
        scanf("%lld", &p);
        w=p;
        while(w--)
        {
            if(isPrime_3(w)){q=w;break;}
        }
        for(ll i=q+1;i<=p-2;i++)
        {
            z=pp(z,i,p);
        }
        z%=p;
        ny=ff(z,p-2,p)%p;///��Ԫ%p
        printf("%lld\n",ny);
    }
    return 0;
}


