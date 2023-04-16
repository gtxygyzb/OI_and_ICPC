#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 50, M = 65, P = 998244353;
char s[N];
int n, t[M], top;
ll ans, sum, ij[M], cnt[M], l[M], f[M], tot, pre[M];
int id(char c)
{
    if (c >= 'a' && c <= 'z') return c - 'a';
    if (c >= 'A' && c <= 'Z') return 26 + c - 'A';
    return 52 + c - '0';
}
inline ll C(int x)
{
    return cnt[x] * (cnt[x] - 1) >> 1;
}
inline ll calc(int x, int b, int i)
{
    ll m = i - cnt[x] - cnt[b];
    return  ((m * (m - 1) >> 1)  - (sum - C(x) - C(b))) % P;
}
int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int b = 0; b < 62; b++)
    {
        sum = tot = top = 0;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++)
            ++cnt[id(s[i])];
        if (cnt[b] <= 1) continue;
        for (int i = 0; i < 62; i++)
            sum += C(i);
        memset(f, 0, sizeof(f));
        memset(l, 0, sizeof(f));
        memset(pre, 0, sizeof(pre));
        memset(ij, 0, sizeof(ij));
        for (int x, i = n; i >= 1; i--)
        {
            x = id(s[i]);
            sum -= C(x);
            --cnt[x];
            sum += C(x);
            if (x == b)
            {
                ++tot;
                for (int j = 1; j <= top; j++)
                {
                    x = t[j];
                    f[x] = (l[x] * l[b] + (tot - pre[x]) * ij[x] + f[x]) % P;
                    ij[x] = (ij[x] + l[x] * l[b]) % P;
                    l[x] = 0;
                    pre[x] = tot;
                }
                top = 0;
                ++l[b];
            }
            else
            {
                ans += (f[x] + (tot - pre[x]) * ij[x] % P) * calc(x, b, i - 1) % P;
                if (ans >= P) ans -= P;
                ++l[x];
                if (l[x] == 1)
                    t[++top] = x;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}