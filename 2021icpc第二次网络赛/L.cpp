#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 50, P = 998244353, all = (1<<25) - 1;
int n, m, a[N];

int vis[105], pri[105], tot, inv[105];
int mp = 1, v0 = 1, id;

int b[N];
int lo[N * 400];
int power(int x, int k)
{
    int ret = 1;
    for (; k; k >>= 1, x = 1LL * x * x % P)
        if (k & 1) ret = 1LL * ret * x % P;
    return ret;
}
void prime()
{
    inv[1] = 1;
    for (int i = 2; i <= 100; i++)
    {
        if (!vis[i])
        {
            b[i] = 1<<tot;
            pri[tot++] = i;
        }
        for (int j = 0; j < tot; j++)
        {
            if (i * pri[j] > 100) break;
            b[i * pri[j]] = b[i] | b[pri[j]];
            vis[i * pri[j]] = 1;
            if (i % pri[j] == 0) break;
        }
        inv[i] = power(i, P - 2);
    }
    for (int i = 0; i < tot; i++)
    {
        mp = 1LL * mp * (pri[i] - 1) % P;
        v0 = 1LL * v0 * inv[pri[i] - 1] % P;
    }
    for (int i = 2; i <= 4e7; i *= 2)
        lo[i] = lo[i /2] + 1;
}

int t[N<<2], tb[N<<2], lazy[N<<2];
void pu(int u)
{
    t[u] = t[u<<1] + t[u<<1|1];
    tb[u] = tb[u<<1] & tb[u<<1|1];
    if (t[u] >= P) t[u] -= P;
}
void build(int u, int l, int r)
{
    //printf("%d %d %d\n", u, l, r);
    lazy[u] = 1;
    if (l == r)
    {
        t[u] = 1LL * v0 * a[l] % P;
        tb[u] = b[a[l]];
        int x = tb[u];
        for (int i = x; i; i -= i&-i)
        {
            int cur = i & -i;
            t[u] = 1LL * t[u] * (pri[lo[cur]] - 1) % P * inv[pri[lo[cur]]] % P;
        }
        return ;
    }
    int mid = l + r >> 1;
    build(u<<1, l, mid);
    build(u<<1|1, mid + 1, r);
    pu(u);
}

void tag(int u, int val)
{
    lazy[u] = 1LL * lazy[u] * val % P;
    t[u] = 1LL * t[u] * val % P;
}
void pd(int u)
{
    if (lazy[u] > 1)
    {
        tag(u<<1, lazy[u]);
        tag(u<<1|1, lazy[u]);
        lazy[u] = 1;
    }
}
void mul(int u, int st, int ed, int l, int r, int w)
{
    if (l == r)
    {
        t[u] = 1LL * t[u] * w % P;

        int x = b[w];
        for (int i = x; i; i -= i & -i)
        {
            int cur = i & -i;
            if ((tb[u] & cur) == 0)
            {
                t[u] = 1LL * t[u] * (pri[lo[cur]] - 1) % P * inv[pri[lo[cur]]] % P;
            }
        }
        tb[u] |= b[w];
        return ;
    }
    if (st == l && ed == r && ((tb[u] & b[w]) == b[w]) )
    {
        lazy[u] = 1LL * lazy[u] * w % P;
        t[u] = 1LL * t[u] * w % P;
        return ;
    }
    pd(u);
    int mid = l + r >> 1;
    if (st <= mid) mul(u<<1, st, min(mid, ed), l, mid, w);
    if (ed > mid) mul(u<<1|1, max(mid + 1, st), ed, mid + 1, r, w);
    pu(u);
}
int query(int u, int st, int ed, int l, int r)
{
    if (st == l && ed == r)
        return t[u];
    pd(u);
    int mid = l + r >> 1, ret = 0;
    if (st <= mid) ret += query(u<<1, st, min(mid, ed), l, mid);
    if (ed > mid) ret += query(u<<1|1, max(mid + 1, st), ed, mid + 1, r);
    return ret % P;
}
int main()
{
    //freopen("L.in", "r", stdin);
    //freopen("L.out", "w", stdout);
    prime();
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", a+i);
    build(1, 1, n);
    for (int opt, x, y, w; m--; )
    {
        scanf("%d%d%d", &opt, &x, &y);
        if (opt == 0)
        {
            scanf("%d", &w);
            mul(1, x, y, 1, n, w);
        }
        else
            printf("%lld\n", 1LL * mp * query(1, x, y, 1, n) % P);
    }
    return 0;
}
/*
5 5
5 4 3 2 1
1 1 5
0 3 5 2
1 1 5
0 1 4 6
1 1 5
*/
