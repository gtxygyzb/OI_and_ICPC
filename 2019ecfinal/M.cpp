#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 50;
int n, vis[N], t[N], top, bin[30];
ll a[N], b[N], ans;
int p[N];
int main()
{
    bin[0] = 1;
    for (int i = 1; i <= 25; i++)
        bin[i] = bin[i - 1] << 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", a + i);
    for (int i = 1; i <= n; i++)
        scanf("%lld", b + i);
    ans += a[1];
    for (int i = 2; i <= n; i++)
    {
        if (vis[i]) continue;
        t[0] = i; top = 1;
        for (ll j = 1LL * i * i; j <= 1LL * n; j *= 1LL * i)
        {
            vis[j] = 1;
            t[top++] = j;
        }
        ll cur = 0;
        for (int x, s = 1; s < bin[top]; s++)
        {
            ll ans1 = 0;
            for (int j = 0; j < top; j++)
                if (bin[j] & s)
                {
                    x = t[j];
                    for (ll k = 1LL * x * x; k <= 1ll * n; k *= 1ll * x)
                        ++p[k];
                    ans1 += a[x];
                    if (p[x]) ans1 -= b[x] * p[x];
                }

            for (int j = 0; j < top; j++) // p[k]复原
                if (bin[j] & s)
                {
                    x = t[j];
                    for (ll k = 1LL * x * x; k <= 1ll * n; k *= 1ll * x)
                        p[k] = 0;
                }
            
            cur = max(cur, ans1);
        }
        ans += cur;
    }
    cout<<ans<<endl;
    return 0;
}
/*
10
8 4 9 6 3 5 4 3 7 9 
6 6 2 10 3 5 3 4 3 1 
*/