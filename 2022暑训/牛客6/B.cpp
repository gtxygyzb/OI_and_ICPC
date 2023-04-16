#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 2e6 + 50;
vector <int> e[N];

int n, dep[N], d[N], in[N], out[N], tot;
int a[N], rt[N], dfm[N], top;

struct Tree
{
    int l, r, sum;
}t[N*30];
void add(int &u, int pre, int l, int r, int pos)
{
    t[u = ++top] = t[pre]; ++t[u].sum;
    if (l == r) return ;
    int mid = l + r >> 1;
    if (pos <= mid) add(t[u].l, t[pre].l, l, mid, pos);
    else add(t[u].r, t[pre].r, mid + 1, r, pos);
}
int query(int u, int pre, int st, int ed, int l, int r)
{
    if (st == l && ed == r)
        return t[u].sum - t[pre].sum;
    int mid = l + r >> 1, ret = 0;
    if (st <= mid) ret += query(t[u].l, t[pre].l, st, min(mid, ed), l, mid);
    if (ed > mid) ret += query(t[u].r, t[pre].r, max(mid + 1, st), ed, mid + 1, r);
    return ret;
}

void dfs(int u, int fa)
{
    if (fa == 0) dep[u] = 0;
    else dep[u] = dep[fa] + 1;
    in[u] = ++tot;
    dfm[tot] = u;
    for (int siz = e[u].size(), i = 0; i < siz; i++)
    {
        int v = e[u][i];
        if (v == fa) continue;
        dfs(v, u);
    }
    out[u] = tot;
}
int main()
{
    scanf("%d", &n);
    for (int u, v, i = 1; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        e[u].pb(v); e[v].pb(u);
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", a+i);
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
        add(rt[i], rt[i - 1], -n, n, a[dfm[i]] - dep[dfm[i]]);
    for (int i = 1; i <= n; i++)
    {
        int l = in[i], r = out[i];
        int ans = query(rt[r], rt[l - 1], -dep[i], n, -n, n);
        printf("%d ", ans);
    }
    puts("");
    return 0;
}
/*
10
1 2
2 3
2 4
3 5
4 6
4 7
1 8
8 9
8 10
0 0 1 2 2 5 3 1 0 2
*/