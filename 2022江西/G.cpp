#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;
int n, a[N], p[N], e[10][10], cnt[10];

int check(int x)
{
    if (x <= 0 || x > 1e6) return 0;
    return p[x];
}
int pd(int x, int u, int v)
{
    int pro = -1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] % 3 != x) continue;
        if ((a[i] + 2) % 3 == u && (check(a[i] - 1) || check(a[i] + 2)))
            {pro = i; break;}
        if ((a[i] + 1) % 3 == u && (check(a[i] - 2) || check(a[i] + 1)))
            {pro = i; break;}
    }
    if (~pro)
    {
        int flag = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] % 3 != x || i == pro) continue;
            if ((a[i] + 2) % 3 == v && (check(a[i] - 1) || check(a[i] + 2)))
                {flag = 1; break;}
            if ((a[i] + 1) % 3 == v && (check(a[i] - 2) || check(a[i] + 1)))
                {flag = 1; break;}
        }
        if (flag) return 1;
    }
    return 0;
}
int find(int x, int u, int v)
{
    return pd(x, u, v) | pd(x, v, u);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        cnt[0] = cnt[1] = cnt[2] = 0;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                e[i][j] = 0;

        for (int i = 1; i <= n; i++)
        {
            scanf("%d", a+i);
            ++cnt[a[i] % 3];
            ++p[a[i]];
        }

        for (int i = 1; i <= n; i++)
        {
            int u = a[i] % 3;
            if (check(a[i] - 1) || check(a[i] + 2)) e[u][(u + 2) % 3] = 1;
            if (check(a[i] - 2) || check(a[i] + 1)) e[u][(u + 1) % 3] = 1;
        }
        if ((cnt[0] + cnt[1] + cnt[2]) & 1)
            puts("His little girlfriend");
        else
        {
            if (cnt[0] % 2 == 0 && cnt[1] % 2 == 0 && cnt[2] % 2 == 0)
                puts("rqd");
            else if (cnt[0] % 2 && cnt[1] % 2)
            {
                if (e[0][1] || find(2, 0 ,1)) puts("rqd");
                else puts("His little girlfriend");
            }
            else if (cnt[1] % 2 && cnt[2] % 2)
            {
                if (e[1][2] || find(0, 1, 2)) puts("rqd");
                else puts("His little girlfriend");
            }
            else if (cnt[0] % 2 && cnt[2] % 2)
            {
                if (e[0][2] || find(1, 0, 2)) puts("rqd");
                else puts("His little girlfriend");
            }
        }
        for (int i = 1; i <= n; i++)
            p[a[i]] = 0;
    }
    return 0;
}