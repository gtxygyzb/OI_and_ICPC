#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;
int n, m;
double a[N];

int head[N], etop;
struct Edge
{
    int v, nxt;
}e[N];
void add(int u, int v)
{
    e[++etop].v = v;
    e[etop].nxt = head[u];
    head[u] = etop;
}

int id[N], top, du[N], cnt[N];
double sum[N];
void dfs(int u)
{
    id[u] = top;
    for (int i = head[u]; i; i = e[i].nxt)
        if (!id[e[i].v]) dfs(e[i].v);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        etop = top = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%lf", &a[i]);
            du[i] = 1; id[i] = cnt[i] = sum[i] = head[i] = 0;
        }
        for (int u, v, i = 1; i <= m; i++)
        {
            scanf("%d%d", &u, &v);
            add(u, v);
            add(v, u);
            ++du[u];
            ++du[v];
        }
        for (int i = 1; i <= n; i++)
        {
            if (!id[i]) {++top; dfs(i);}
            cnt[id[i]] += du[i];
            sum[id[i]] += du[i] * a[i];
        }
        for (int i = 1; i <= n; i++)
            printf("%.6lf\n", sum[id[i]] / cnt[id[i]]);
    }
    return 0;
}