#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
ll n, m, k;
int main()
{
    scanf("%d", &T);
    for (int cs = 1; cs <= T; cs++)
    {
        scanf("%lld%lld%lld", &n, &m, &k);
        ll ans = -1;
        if (m <= k)
        {
            for (int i = 1; i <= m; i++)
                ans = (ans + k) % (n - m + i);
        }
        else
        {
            if (k == 1) ans = m - 1;
            else
            {
                ll st = n - m, x = (st - ans) / (k - 1);
                if ((st - ans) % (k - 1)) ++x;
                while (st + x <= n)
                {
                    ans += k * x; st += x;
                    ans %= st;
                    x = (st - ans) / (k - 1);
                    if ((st - ans) % (k - 1)) ++x;
                }
                ans += (n - st) * k;
                ans %= n;
            }
        }
        //if (ans == 999999999999987237) cout<<n<<" "<<m<<" "<<k<<endl;
        printf("Case #%d: %lld\n", cs, ans + 1);
    }
    return 0;
}
/*
1
10 7 3
*/