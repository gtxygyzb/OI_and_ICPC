#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 50;
int n, k, a[N];
ll ans;
vector <int> e[N];
int rt[N], lc[N * 30], rc[N * 30], sum[N * 30], top;
int siz[N], dep[N], son[N];

void update(int &u, int l, int r, int pos, int val)
{
    if (!u) u = ++top;
    sum[u] += val;
    if (l == r) return;
    int mid = l + r >> 1;
    if (pos <= mid) update(lc[u], l, mid, pos, val);
    else update(rc[u], mid + 1, r, pos, val);
}
int query(int u, int st, int ed, int l, int r)
{
    if (!u) return 0;
    if (st == l && ed == r) return sum[u];
    int ret = 0, mid = l + r >> 1;
    if (st <= mid) ret += query(lc[u], st, min(mid, ed), l, mid);
    if (ed > mid) ret += query(rc[u], max(st, mid + 1), ed, mid + 1, r);
    return ret;
}

void dfs1(int u)
{
    siz[u] = 1;
    for (int v, i = 0; i < e[u].size(); i++)
    {
        v = e[u][i];
        dep[v] = dep[u] + 1;
        dfs1(v);
        siz[u] += siz[v];
        if (siz[v] > siz[son[u]])
            son[u] = v;
    }
}

void add(int u, int val)
{
    update(rt[a[u]], 1, n, dep[u], val);
    for (int i = 0; i < e[u].size(); i++)
        add(e[u][i], val);
}

void qry(int u, int rd, int rv)
{
    int qd = min(k + 2 * rd - dep[u], n);
    int qv = 2 * rv - a[u];
    if (qd >= 1 && qv >= 0 && qv <= n)
        ans += 2LL * query(rt[qv], 1, qd, 1, n);

    for (int i = 0; i < e[u].size(); i++)
        qry(e[u][i], rd, rv);
}
void dfs2(int u)
{
    for (int v, i = 0; i < e[u].size(); i++)
    {
        v = e[u][i];
        if (v == son[u]) continue;
        dfs2(v);
        add(v, -1);
    }
    if (son[u]) dfs2(son[u]);
    for (int v, i = 0; i < e[u].size(); i++)
    {
        v = e[u][i];
        if (v == son[u]) continue;
        qry(v, dep[u], a[u]);
        add(v, 1);
    }
    update(rt[a[u]], 1, n, dep[u], 1);
}
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", a+i);
    for (int u, i = 2; i <= n; i++)
    {
        scanf("%d", &u);
        e[u].push_back(i);
    }
    dep[1] = 1;
    dfs1(1);
    dfs2(1);
    printf("%lld\n", ans);
    return 0;
}