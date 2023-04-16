#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3050;
ll f[N][N];
int n;
struct Data
{
    ll x, y;
    void input() {scanf("%lld%lld", &x, &y);}
    bool operator <(const Data &t) const {return x == t.x ? y < t.y : x < t.x;}
}a[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        a[i].input();
    sort(a + 1, a + n + 1);
    memset(f, -0x3f, sizeof(f));
    f[0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= i; j++) //j个x商品
        {
            if (j > 0) f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1LL * j * a[i].x); //当前选x商品
            if (j != i) f[i][j] = max(f[i][j], f[i - 1][j] + 1LL * (i - j) * a[i].y); //当前给y商品
        }
    ll ans = -1e18;
    for (ll j = 0; j <= n; j++)
        ans = max(ans, f[n][j] - 1LL * (j + j - n) * (j + j - n));
    printf("%lld\n", ans);
    return 0;
}
/*
64
*/