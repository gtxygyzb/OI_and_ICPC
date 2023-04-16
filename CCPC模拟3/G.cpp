#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 50, seed = 13331;
const ll P = 1e9 + 7, mod = 65536; //P自定义哈希模数, mod题目模数

ll p[N], a[N];
int n, q;

void init()
{
    p[0] = 1;
    for (int i = 1; i <= n; i++)
        p[i] = p[i-1] * seed % P;
}

struct Tree
{
    ll base[N<<2], lazy[N<<2], mx[N<<2], h[N<<2];
    #define lc u<<1
    #define rc u<<1|1
    void pu(int u)
    {
        mx[u] = max(mx[lc], mx[rc]);
        h[u] = (h[lc] + h[rc]) % P;
    }
    void tag(int u, int val)
    {
        lazy[u] += val;
        mx[u] += val;
        h[u] = (h[u] + base[u] * val % P) % P;
    }
    void pd(int u)
    {
        if (lazy[u])
        {
            tag(lc, lazy[u]);
            tag(rc, lazy[u]);
            lazy[u] = 0;
        }
    }
    void build(int u, int l, int r)
    {
        if (l == r)
        {
            mx[u] = a[l];
            base[u] = p[l];
            h[u] = a[l] * base[u] % P;
            return ;
        }
        int mid = l + r >> 1;
        build(lc, l, mid);
        build(rc, mid + 1, r);
        base[u] = (base[lc] + base[rc]) % P;
        pu(u);
    }
    void add(int u, int st, int ed, int l, int r)
    {
        if (l == r)
        {
            mx[u] = (mx[u] + 1) % mod;
            h[u] = mx[u] * base[u] % P;
            lazy[u] = 0;
            return ;
        }
        if (st == l && ed == r && mx[u] + 1 < mod)
        {
            ++mx[u]; ++lazy[u];
            h[u] = (h[u] + base[u]) % P;
            return ;
        }
        pd(u); int mid = l + r >> 1;
        if (st <= mid) add(lc, st, min(mid, ed), l, mid);
        if (ed > mid) add(rc, max(st, mid + 1), ed ,mid + 1, r);
        pu(u);
    }
    ll query(int u, int st, int ed, int l, int r)
    {
        if (st == l && ed == r) return h[u];
        ll ret = 0; pd(u);
        int mid = l + r >> 1;
        if (st <= mid) ret += query(lc, st, min(mid, ed), l, mid);
        if (ed > mid) ret += query(rc, max(st, mid + 1), ed, mid + 1, r);
        return ret % P;
    }
}T;
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%lld", a+i);
    init();
    T.build(1, 1, n);
    for (int opt, x, y, len; q--; )
    {
        scanf("%d%d%d", &opt, &x, &y);
        if (opt == 1)
            T.add(1, x, y, 1, n);
        else
        {
            scanf("%d", &len);
            if (x > y) swap(x, y);
            ll ans1 = T.query(1, x, x + len - 1, 1, n);
            ll ans2 = T.query(1, y, y + len - 1, 1, n);
            ans1 = ans1 * p[y - x] % P;
            puts(ans1 == ans2 ? "yes" : "no");
        }
    }
    return 0;
}
/*
3 3
1 2 1
2 1 1 1
1 1 1
2 1 1 1
*/