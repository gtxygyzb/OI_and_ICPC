#include <bits/stdc++.h>
using namespace std;

const int N = 2E5 + 50, P = 998244353;

int n, c, vis[N], tot, pri[N], mi[N];
void init()
{
    for (int i = 2; i <= c; i++)
    {
        if (!vis[i]) {pri[++tot] = i; mi[i] = i;}
        for (int j = 1; i * pri[j] <= c; j++)
        {
            vis[i * pri[j]] = 1;
            mi[i * pri[j]] = pri[j];
            if (i % pri[j] == 0)
                break;
        }
    }
}
int fac[N], inv[N];
int C(int x, int y)
{
    return 1LL * fac[x] * inv[y] % P * inv[x - y] % P;
}
int power(int x, int k)
{
    int ret = 1;
    for (; k; k >>= 1, x = 1LL * x * x % P)
        if (k & 1) ret = 1LL * ret * x % P;
    return ret;
}
int main()
{
    scanf("%d%d", &n, &c);
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= n + c; i++)
    {
        fac[i] = 1LL * fac[i - 1] * i % P;
        inv[i] = power(fac[i], P - 2);
    }
    init();
    int ans = 1;
    for (int i = 2; i <= c; i++)
    {
        int pre = -1, t = i, cnt = 0;
        int cur = 1;
        while (t > 1)
        {
            if (mi[t] != pre)
            {
                cur = 1LL * cur * C(n + cnt - 1, n - 1) % P;
                pre = mi[t];
                cnt = 1;
            }
            else ++cnt;
            t /= mi[t];
        }
        //cout<<cnt<<endl;
        cur = 1LL * cur * C(n + cnt - 1, n - 1) % P;
        ans = (ans + cur) % P;
    }
    printf("%d\n", ans);
    return 0;
}
