#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 50, B = 21;

int sa[N], sb[N], t[N], n;
void tsort(int a[], int b[], int rk[])
{
    int m = 150000;
    memset(t, 0, sizeof(int) * (m + 5));
    for (int i = 0; i < n; i++) ++t[b[i]];
    for (int i = 1; i <= m; i++) t[i] += t[i - 1];
    for (int i = n - 1; ~i; i--) sb[t[b[i]]--] = i;

    memset(t, 0, sizeof(int) * (m + 5));
    for (int i = 1; i <= n; i++) ++t[a[sb[i]]];
    for (int i = 1; i <= m; i++) t[i] += t[i - 1];
    for (int i = n; i; i--) sa[t[a[sb[i]]]--] = sb[i];

    int cnt = 1; rk[sa[1]] = cnt;
    for (int i = 2; i <= n; i++)
        rk[sa[i]] = (a[sa[i]] == a[sa[i - 1]] && b[sa[i]] == b[sa[i - 1]] ? cnt : ++cnt);
}

int f[N][B], g[N][B], bin[B] = {1};
char s[N];
int a[N], b[N], rk[N], cur[N];

int main()
{
    for (int i = 1; i < B; i++)
        bin[i] = bin[i - 1] << 1;
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; cs++)
    {
        scanf("%d%s", &n, s);
        for (int i = 0; i < n; i++)
        {
            f[i][0] = (1LL * i * i + 1) % n;
            g[i][0] = 9 - (s[i] - '0');
            b[i] = g[i][0];
        }

        for (int j = 1; j <= 20; j++)
            for (int i = 0; i < n; i++)
                f[i][j] = f[f[i][j - 1]][j - 1];

        for (int j = 1; j <= 20; j++)
        {
            for (int i = 0; i < n; i++)
            {
                a[i] = g[i][j - 1];
                b[i] = g[f[i][j - 1]][j - 1];
            }
            tsort(a, b, rk);
            for (int i = 0; i < n; i++)
                g[i][j] = rk[i];
        }

        for (int i = 0; i < n; i++)
            cur[i] = i;
        
        int flag = 0;
        for (int j = 20; ~j; j--)
        {
            if ((n & bin[j]) == 0) continue;
            if (flag == 0)
            {
                for (int i = 0; i < n; i++)
                    a[i] = g[i][j];
                flag = 1;
            }
            else
            {
                for (int i = 0; i < n; i++)
                    b[i] = g[cur[i]][j];
                tsort(a, b, a);
            }
            for (int i = 0; i < n; i++)
                cur[i] = f[cur[i]][j];
        }

        printf("Case #%d: ", cs);
        for (int i = 0; i < n; i++)
            if (a[i] == 1)
            {
                int u = i;
                for (int j = 1; j <= n; j++)
                {
                    printf("%c", s[u]);
                    u = f[u][0];
                }
                break;
            }
        puts("");
    }
    return 0;
}
/*
1
3
149
*/