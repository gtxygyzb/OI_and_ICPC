#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int P = 1e9 + 7, N = 5e5 + 50;
ll power(ll x, ll k)
{
    ll ret = 1;
    for (; k; k >>= 1, x = x * x % P)
        if (k & 1) ret = ret * x % P;
    return ret;
}
ll n, m, rb, cb, rd, cd, p, q, ans, a[N];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld%lld%lld%lld%lld%lld%lld", &n, &m, &rb, &cb, &rd, &cd, &p);

        p = p * power(100, P - 2) % P;
        q = (1 - p + P) % P;


        ans = 0;
        ll C = 2 * (n - 1) * (m - 1) / __gcd(n - 1, m - 1);
        ll dx = 1, dy = 1, x = rb, y = cb;
        ll b = (rb == rd || cb == cd) ? q : 1;
        a[0] = (rb == rd || cb == cd) ? p : 0;

        if (x == n) dx *= -1;
        if (y == m) dy *= -1;

        for (int i = 1; i < C; i++)
        {
            x += dx; y += dy;
            if (x == rd || y == cd)
            {
                a[i] = b * p % P;
                b = b * q % P;
            }
            else a[i] = 0;
            if (x == n || x == 1) dx *= -1;
            if (y == m || y == 1) dy *= -1;
        }
        ll jb = power((1 - b + P) % P, P - 2);
        for (int i = 0; i < C; i++)
        {
            //cout<<a[i]<<" "<<b<<endl;;
            ll zkh = (i * jb % P + b * C % P * jb % P * jb % P) % P;
            ans += a[i] * zkh % P;
            ans %= P;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
/*
1
10 10 10 10 1 1 75
*/