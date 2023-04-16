#include <bits/stdc++.h>
using namespace std;
const int N = 35, P = 1e9 + 7;

void div(int n, int &top, int a[])
{
    memset(a, 0, sizeof(int) * N);
    top = 0;
    while (n)
    {
        a[++top] = n & 1;
        n >>= 1;
    }
}

void add(int &x, int y)
{
    x += y;
    if (x >= P) x -= P;
}

int f[N][2][2][2], a[N], b[N], an, bn, n;
int dp(int u, int lim1, int lim2, int lead)
{
    if (u == n + 1) return 1;
    if (~f[u][lim1][lim2][lead]) return f[u][lim1][lim2][lead];
    int ret = 0;

    for (int i = 0; i <= (lim1 ? a[u] : 1); i++)
        for (int j = 0; j <= (lim2 ? b[u] : 1); j++)
        {
            if (i && j) continue;
            int mul = (lead && (i || j)) ? n - u + 1 : 1;
            add(ret, 1LL * mul * dp(u + 1, lim1 && a[u] == i, lim2 && b[u] == j, lead && !i && !j) % P);
        }
    return f[u][lim1][lim2][lead] = ret;
}
int work(int x, int y)
{
    div(x, an, a);
    div(y, bn, b);
    n = max(an, bn);
    reverse(a + 1, a + n + 1);
    reverse(b + 1, b + n + 1);
    memset(f, -1, sizeof(f));
    return (dp(1, 1, 1, 1) - 1 + P) % P;
}
int main()
{
    int T, x, y;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &x, &y);
        printf("%d\n", work(x, y));
    }
    return 0;
}