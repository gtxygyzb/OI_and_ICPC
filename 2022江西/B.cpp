#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5 + 50;
ll n, k;
char s[N];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld%lld", &n, &k);
        scanf("%s", s);
        ll len = 0, ans = (n + (n - k)) * (k + 1) / 2;
        //cout<<"ans:"<<ans<<endl;
        s[n] = '1'; ++n;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0') ++len;
            else
            {
                ll d = min(k, len - 1);
                ans -= (len + (len - d)) * (d + 1) / 2;
                len = 0;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}