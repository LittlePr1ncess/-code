#include<bits/stdc++.h>
using namespace std;
#define LL long long
int main()
{
    LL a, b;
    int T;
    cin >> T;
    while(T--)
    {
        cin >> a >> b;
        if(a>b)
            swap(a, b);
        if(b%a) {
            cout << -1 << endl;
            continue;
        }
        LL c = b / a;
        LL ans = 0;
        int flag = 0;
        while(c>1)
        {
            //cout << c << " ";
            if(c%8==0)
            {c /= 8, ans++;}
            else if(c%4==0){
                c /= 4, ans++;
            }
            else if(c%2==0){
                c /= 2;
                ans++;
            }
            else {
                cout << -1 << endl;
                flag = 1;
                break;
            }
        }
        if(!flag)
            cout << ans << endl;
    }
   system("pause");
}