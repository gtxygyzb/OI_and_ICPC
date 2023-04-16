#include <bits/stdc++.h>
using namespace std;
const int N = 25, P = 998244353;
int n, all, a[N][N], ans[N][N];
int f[1<<21], cnt[1<<21], bin[25];
int fm[1<<20];
int power(int x, int k)
{
    int ret = 1;
    for (; k; k >>= 1, x = 1LL * x * x % P)
        if (k & 1) ret = 1LL * ret * x % P;
    return ret;
}
void add(int &x, int y)
{
    x += y;
    if (x >= P) x -= P;
}
int main()
{
    scanf("%d", &n);
    all = 1<<n;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    for (int i = 1; i < all; i++)
        cnt[i] = cnt[i ^ (i & -i)] + 1;
    for (int i = 0; i < n; i++)
        bin[i] = 1<<i;
    for (int u = 0; u < all - 1; u++)
    {
        int i = cnt[u] + 1;
        for (int j = 0; j < n; j++)
            if ((u & bin[j]) == 0)
                fm[u] += a[i][j];
        fm[u] = power(fm[u], P - 2);
    }
    
    f[0] = 1;
    for (int v, i = 1; i < all; i++)
    {
        for (int j = 0; j < n; j++)
            if (i & bin[j])
            {
                v = i ^ bin[j];
                add(f[i], 1LL * f[v] * fm[v] % P * a[cnt[i]][j] % P);
            }
        //cout<<i<<":"<<f[i]<<endl;
    }
    for (int i = 0; i < all - 1; i++)
    {
        for (int j = 0; j < n; j++)
            if ((i & bin[j]) == 0)
            {
                add(ans[cnt[i] + 1][j], 1LL * f[i] * fm[i] % P * a[cnt[i] + 1][j] % P);
            }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d", ans[i][j]);
            if (j == n - 1) printf("\n");
            else printf(" ");
        }
    }
    return 0;
}
/*
2
2 1
2 1
*/