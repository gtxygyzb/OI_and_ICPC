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
#include<unordered_map>
#include<cmath>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e6 + 10;
const int mod = 998244353;

ll a[MAXN];
ll dp[5010][5010];
int pre[5010];
void solve()
{
    int n, k, r;
    scanf("%d%d%d", &n, &k, &r);
    int now = 1;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", a + i);
        if (i == now || a[i] < a[now] + r) pre[i] = 0;
        else
        {
            while (now < i && a[i] >= a[now] + r)
            {
                pre[i] = now;
                now++;
            }
            now--;
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            dp[i][j] = 0;
        }
    }
    dp[1][1] = dp[0][0] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= k && j <= i; j++)
        {
            if (i - pre[i] - 1 <= j)
            {
                dp[i][j] += dp[i - 1][j] * (j - (i - pre[i] - 1)) % mod;
                dp[i][j] %= mod;
            }
            dp[i][j] += dp[i - 1][j - 1];
            dp[i][j] % mod;
        }
    }
    printf("%lld\n", dp[n][k]);
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