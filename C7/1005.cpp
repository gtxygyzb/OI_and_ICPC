#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50, P = 1e9 + 7;

int f[N], s[N];

int power(int x, int k)
{
    int ret = 1;
    for (; k; k >>= 1, x = 1LL * x * x % P)
        if (k&1) ret = 1LL * ret * x % P;
    return ret;
}

int dfs(int n)
{
    if (n == 0) return 0;
    if (f[n]) return f[n];
    if (n & 1)
    {
        f[n] = 2*dfs(n + 1 >> 1) - 1;
    }
    else
        f[n] = dfs(n >> 1) + dfs(n/2 + 1) - 1;
    return f[n];
}
int main()
{
    int T;
    scanf("%d", &T);
    f[1] = f[2] = 1; f[3] = f[4] = 2;
    for (int i = N - 50; i >= 5; i--)
        if (f[i] == 0) f[i] = dfs(i);
    for (int i = 1; i <= N-50; i++)
        s[i] = (s[i-1] + f[i]) % P;
    while (T--)
    {
        int n;
        scanf("%d", &n);
        printf("%lld\n", 1LL * ((s[n] + s[n] - n) % P + P) % P * power(n, P-2) % P);
    }
    return 0;
}