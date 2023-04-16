#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 50;
int n, q, a[N];
ll ans, val[N];
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    ans += 1ll * n * (n + 1) / 2;
    for (int i = 1; i < n; i++)
    {
        val[i] = 1ll * i * (n - i);
        if (a[i] != a[i + 1]) ans += val[i];
    }
    for (int pos, x; q--;)
    {
        scanf("%d%d", &pos, &x);
        if (pos != n && a[pos] != a[pos + 1]) ans -= val[pos];
        if (pos != 1 && a[pos - 1] != a[pos]) ans -= val[pos - 1];
        a[pos] = x;
        if (pos != n && a[pos] != a[pos + 1]) ans += val[pos];
        if (pos != 1 && a[pos - 1] != a[pos]) ans += val[pos - 1];
        printf("%lld\n", ans);
    }
    return 0;
}