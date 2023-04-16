#include <bits/stdc++.h>
using namespace std;
const int N = 550;
const double eps = 1e-6;
int mp[N][N], n, m, d[N];
double a[N][N], f[N], ans;

void mul(int j, int i, double t)
{
    for (int k = 1; k <= n + 1; k++)
        a[j][k] -= a[i][k] * t;
}
void gauss()
{
    for (int i = 1; i <= n; i++)
    {
        int maxk = i;
        for (int j = i + 1; j <= n; j++)
            if (fabs(a[maxk][i]) - fabs(a[j][i]) < eps)
                maxk = j;
        swap(a[i], a[maxk]);
        for (int j = 1; j <= n; j++)
            if (i != j) mul(j, i, a[j][i] / a[i][i]);
    }
    for (int i = 1; i <= n; i++)
        f[i] = a[i][n + 1] / a[i][i];
}

struct Edge
{
    int u, v;
    double w;
    bool operator <(const Edge &t) const
    {
        return w > t.w;
    }
}e[N * N];

int main()
{
    scanf("%d%d", &n, &m);
    for (int u, v, i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        e[i] = {u, v, 0};
        mp[u][v] = mp[v][u] = 1;
        ++d[u]; ++d[v];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j) {a[i][j] = 1; continue;}
            if (i == n || j == n) continue;
            if (mp[i][j]) a[i][j] = -1.0 / d[j];
        }
        a[i][n + 1] = (i == 1 ? 1 : 0);
    }
    gauss();
    for (int u, v, i = 1; i <= m; i++)
    {
        u = e[i].u; v = e[i].v;
        e[i].w = f[u] / d[u] + f[v] / d[v];
    }
    sort(e + 1, e + m + 1);
    for (int i = 1; i <= m; i++)
        ans += 1.0 * i * e[i].w;
    printf("%.3lf\n", ans);
    return 0;
}