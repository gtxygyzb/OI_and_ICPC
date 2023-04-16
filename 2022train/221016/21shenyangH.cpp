#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 50;
const ll inf = 1e18;
int head[N], etop;
struct Edge
{
    int v, nxt, id;
}e[N];
void add(int u, int v, int id)
{
    e[++etop] = Edge{v, head[u], id};
    head[u]= etop;
}

int n, m, x[N], y[N], isb[N];
ll w[N], ans;

int dfn[N], low[N], top, siz[N], dep[N];
void tarjan(int u, int fa)
{
    dfn[u] = low[u] = ++top;
    dep[u] = dep[fa] + 1;
    int son = 0;
    for (int v, i = head[u]; i; i = e[i].nxt)
    {
        v = e[i].v;
        if (!dfn[v]) //树边
        {
            ++siz[u];
            ++son;
            tarjan(v, u);
            siz[u] += siz[v];
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u])
                isb[e[i].id] = 1;
        }
        else if (v != fa)
        {
            low[u] = min(low[u], dfn[v]);
            if (dep[u] <= dep[v]) ++siz[u];
        }
    }
    //cout<<u<<":"<<u<<" "<<siz[u]<<endl;
}
int csiz(int u, int v)
{
    if (dep[u] > dep[v]) swap(u, v);
    return siz[v] % 2 == 0;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%lld", x+i, y+i, w+i);
        add(x[i], y[i], i); add(y[i], x[i], i);
        ans += w[i];
    }
    tarjan(1, 0);
    if (m & 1)
    {
        ll mi = inf;
        for (int i = 1; i <= m; i++)
            if (isb[i])
            {
                if (csiz(x[i], y[i]))
                    mi = min(mi, w[i]);
            }
            else mi = min(mi, w[i]);

        printf("%lld\n", ans - mi);
    }
    else printf("%lld\n", ans);

    return 0;
}