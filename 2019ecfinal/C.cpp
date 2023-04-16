#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50, P = 998244353;
int power(int x, int k)
{
    int ret = 1;
    for (; k; k >>= 1, x = 1LL * x * x % P)
        if (k & 1) ret = 1LL * x * ret % P;
    return ret;
}

int n, m, t[N];

void mul(int f[], int g[])
{
    for (int i = 1; i <= n; i++)
        t[i] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j += i)
            t[j] = (t[j] + 1LL * f[i] * g[j / i]) % P;
    for (int i = 1; i <= n; i++)
        f[i] = t[i];
}

int c[N];
void cpow(int a[], int k)
{
    for (int i = 1; i <= n; i++)
        c[i] = a[i];
    for (--k; k; k >>= 1, mul(a, a))
        if (k & 1) mul(c, a);
    for (int i = 1; i <= n; i++)
        a[i] = c[i];
}
int a[N];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", a+i);
    cpow(a, power(m, P - 2));
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    return 0;
}
/*
5 2
1 4 2 5 3
*/