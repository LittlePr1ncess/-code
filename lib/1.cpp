#include<bits/stdc++.h>
#include <tr1/unordered_map>
using namespace std;
#define so(i, j, k, l) for (int i = j; i <= k;i+=l)
#define LL long long
//std::tr1::unordered_map<int, int> dic;
map<int, int> dic;
int a[1000005],n,tot,ans1[100],x,ans2[100];
int main()
{
    freopen("emm.in", "r", stdin);
   // freopen("a.txt", "w", stdout);
    int T = 18;
    while(T--)
    {
        cin >> n;
        ans1[++tot] = n;
        so(i, 1, n, 1) cin >> a[i]>>x,dic[a[i]]=x;
        int start = clock();
        so(i, 1, n, 1) x = dic[a[i]];
        int end = clock();
        ans2[tot] = end - start;
    }
    so(i, 1, tot, 1) cout << ans1[i] << " " << ans2[i]<< endl;
    system("pause");
}
