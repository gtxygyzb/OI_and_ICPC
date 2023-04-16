#include<iostream>
#include<cstdio>
#include<set>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<bitset>
#include<stack>
#include<queue>
#include<cmath>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e6 + 10;
const int mod = 1e9 + 7;

ll k, b, d, l, r;
ll a[100];
ll dp[65][2][2][65];

ll ksm(ll x, ll y)
{
    ll ans = 1;
    while (y)
    {
        if (y & 1)
        {
            ans *= x;
            ans %= mod;
        }
        x = x * x % mod;
        y >>= 1;
    }
    if (x == 0) return 0;
    return ans;
}

ll dfs(int now, bool f,bool ld, int num)
{
    if (ld) num = 0;
    if (dp[now][f][ld][num] != -1) return dp[now][f][ld][num];
    if (now == 0)
    {
        if (ld) return dp[now][f][ld][num] = 0;
        return dp[now][f][ld][num] = ksm(num, k);
    }
    ll up = b - 1;
    if (f) up = a[now];
    ll ans = 0;
    if (up < d)
    {
        if (f)
        {
            ans += dfs(now - 1, 1, 0, num) % mod;
            ans %= mod;
            if (up != 0)
            {
                ans+= (up - 1) * dfs(now - 1, 0, 0, num) % mod + dfs(now - 1, 0, ld, num) % mod;
            }
            ans %= mod;
        }
        else ans += up % mod * dfs(now - 1, 0, 0, num) % mod + dfs(now - 1, 0, ld, num) % mod;
        ans %= mod;
    }
    else
    {
        if (f)
        {
            if (up == 0)
            {
                ans += dfs(now - 1, 1, 0, num + 1) % mod;
                ans %= mod;
            }
            else
            {
                if (up == d)
                {
                    ans += dfs(now - 1, 1, 0, num + 1) % mod;
                    ans %= mod;
                    ans += dfs(now - 1, 0, ld, num) % mod + (up - 1) * dfs(now - 1, 0, 0, num) % mod;
                    ans %= mod;
                }
                else
                {
                    if (d == 0) ans += dfs(now - 1, 1, 0, num) % mod + dfs(now - 1, 0, ld, num + 1) % mod + (up - 1) * dfs(now - 1, 0, 0, num) % mod;
                    else ans += dfs(now - 1, 1, 0, num) % mod + dfs(now - 1, 0, ld, num) % mod + dfs(now - 1, 0, 0, num + 1) % mod + (up - 2) * dfs(now - 1, 0, 0, num) % mod;
                    ans %= mod;
                }
            }

        }
        else
        {
            if (d == 0)
            {
                ans += dfs(now - 1, 0, ld, num + 1) % mod;
                ans %= mod;
                ans += up * dfs(now - 1, 0, 0, num) % mod;
                ans %= mod;
            }
            else
            {
                ans += dfs(now - 1, 0, 0, num + 1) % mod;
                ans %= mod;
                ans += dfs(now - 1, 0, ld, num) % mod;
                ans %= mod;
                ans += (up - 1) * dfs(now - 1, 0, 0, num) % mod;
                ans %= mod;
            }
        }
    }
    return dp[now][f][ld][num] = ans % mod;
}


ll calcu(ll x)
{
    if (x == 0) return 0;
    memset(dp, -1, sizeof(dp));
    int now = 0;
    while (x)
    {
        a[++now] = x % b;
        x /= b;
    }
    return dfs(now, 1, 1, 0);
}


void solve()
{
    scanf("%lld%lld%lld%lld%lld", &k, &b, &d, &l, &r);
    ll ans = calcu(r) - calcu(l - 1);
    ans %= mod; ans = (ans + mod) % mod;
    printf("%lld\n", ans);
}


int main()
{
    int T = 1;
    scanf("%d", &T);
    while (T--)
    {
        solve();
    }

    return 0;
}
