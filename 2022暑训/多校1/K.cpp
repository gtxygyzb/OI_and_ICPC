#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int P = 1e9 + 7;
ll n, m;

ll power(ll x, ll k)
{
    ll ret = 1;
    for (; k; k >>= 1, x = x * x % P)
        if (k & 1) ret = ret * x % P;
    return ret;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld%lld", &n, &m);
        printf("%lld\n", power(2, P - 2) * (n - m) % P);
    }
    return 0;
}