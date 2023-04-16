#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int P = 998244353;

ll fac[31] = {1}, f[31][2][2][2][2][2][31][2];
ll l1, r1, l2, r2, k;

ll dp(int i, int xl, int xr, int yl, int yr, int lim, int w, int pre)
{
    if (i < 0) return fac[w];
    if (~f[i][xl][xr][yl][yr][lim][w][pre])
        return f[i][xl][xr][yl][yr][lim][w][pre];
    int a = xl ? (l1 >> i & 1) : 0;
    int b = xr ? (r1 >> i & 1) : 1;
    int c = yl ? (l2 >> i & 1) : 0;
    int d = yr ? (r2 >> i & 1) : 1;
    ll ret = 0;
    for (int x = a; x <= b; x++)
        for (int y = c; y <= d; y++)
        {
            int u = x ^ y, ki = k >> i & 1, huo = x | y;
            if (u < ki)
                ret += dp(i - 1, xl && x == a, xr && x == b, yl && y == c, yr && y == d, 0, w + (pre && huo), huo);
            else if (u == ki)
                ret += dp(i - 1, xl && x == a, xr && x == b, yl && y == c, yr && y == d, lim, w + (pre && huo), huo);
            else
            {
                if (lim == 1) continue;
                ret += dp(i - 1, xl && x == a, xr && x == b, yl && y == c, yr && y == d, lim, w + (pre && huo), huo);
            }
        }
    return f[i][xl][xr][yl][yr][lim][w][pre] = ret % P;
}
int main()
{
    int T;
    for (int i = 1; i <= 30; i++)
        fac[i] = fac[i - 1] * i % P;
    scanf("%d", &T);
    while (T--)
    {
        memset(f, -1, sizeof(f));
        scanf("%d%d%d%d%d", &l1, &r1, &l2, &r2, &k);
        printf("%lld\n", dp(30, 1, 1, 1, 1, 1, 0, 0));
    }
    return 0;
}