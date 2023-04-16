#include <bits/stdc++.h>
using namespace std;
const int P = 998244353;

int power(int x, int k)
{
    int ret = 1;
    for (; k; k >>= 1, x = 1LL * x * x % P)
        if (k & 1) ret = 1LL * x * ret % P;
    return ret;
}
int ans = 0, fa;
int main()
{
    int n;
    scanf("%d", &n);
    for (int a, b, i = 1; i <= n; i++)
    {
        scanf("%d%d", &a, &b);
        if (a >= n) ans += 1;
        else if (b > n)
        {
            int cur = 0;
            int ed = b - a + 1, st = b - n + 1;
            cur = 1LL * (st + ed) * (ed - st + 1) % P * power(2, P - 2) % P;

            cur = 1LL * cur * power(b - a + 1, P - 2) % P;

            cur = 1LL * (cur + a - 1) * power(n, P - 2) % P;
            ans = (ans + cur) % P;
        }
        else
        {
            int cur = 1LL * (a + b) * power(2 * n, P - 2) % P;
            ans = (ans + cur) % P;
        }
    }
    printf("%d\n", ans);
    return 0;
}
/*
5
1 8
1 8
1 8
1 8
1 8
*/