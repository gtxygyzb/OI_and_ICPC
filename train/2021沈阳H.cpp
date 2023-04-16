#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;
typedef long long ll;
int head[N], etop = 1, d[N], top;
int dfn[N], low[N], cut[N];
struct Edge
{
    int u, v, w, nxt;
}e[N];
void add(int u, int v, int w)
{
    e[++etop].u = u;
    e[etop].v = v;
    e[etop].w = w;
    e[etop].nxt = head[u];
    head[u] = etop;
    ++d[u];
}

void tarjan(int u, int fa)
{
    dfn[u] = low[u] = ++top;
    int son = 0;
    for (int v, i = head[u]; i; i = e[i].nxt)
    {
        v = e[i].v;
        if (!dfn[v])
        {
            ++son;
            tarjan(v, u);
            d[u] += d[v];
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u])
                cut[i] = cut[i ^ 1] = 1;
        }
        else if (v != fa) low[u] = min(low[u], dfn[v]);
    }
}
int n, m;
ll ans, mi = 1e18;
int main()
{
    scanf("%d%d", &n, &m);
    for (int u, v, w, i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w); add(v, u, w);
        ans += w;
    }
    if ((m & 1) == 0) printf("%lld\n", ans);
    else
    {
        tarjan(1, 0);
        for (int u, v, i = 2; i <= etop; i++)
        {
            u = e[i].u;
            v = e[i].v;
            if (!cut[i]) mi = min(mi, 1ll*e[i].w);
            else
            {
                int e1 = min(d[u], d[v]);
                e1 = (e1 - 1) / 2;
                int e2 = m - e1 - 1;
                if (!((e1&1) && (e2&1))) mi = min(mi, 1ll*e[i].w);
            }
        }
        cout<<ans-mi<<endl;
    }
    return 0;
}