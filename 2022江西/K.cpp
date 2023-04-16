#include <bits/stdc++.h>
#define lc (u << 1)
#define rc (u << 1 | 1)
using namespace std;
typedef long long ll;
const int N = 1e6 + 50;

ll sum[N], mi[N], mx[N], ad[N], clr[N];
void cler(int u) {mi[u] = mx[u] = sum[u] = ad[u] = 0; clr[u] = 1;}
void tag(int u, ll siz, ll val)
{
    mi[u] += val; mx[u] += val; ad[u] += val;
    sum[u] += siz * val;
}
void pd(int u, int l, int r)
{
    if (clr[u])
    {
        cler(lc); cler(rc);
        clr[u] = 0;
    }
    if (ad[u])
    {
        int mid = l + r >> 1;
        tag(lc, mid - l + 1, ad[u]);
        tag(rc, r - mid, ad[u]);
        ad[u] = 0;
    }
}
void pu(int u)
{
    sum[u] = sum[lc] + sum[rc];
    mi[u] = min(mi[lc], mi[rc]);
    mx[u] = max(mx[lc], mx[rc]);
}
void change(int u, int st, int ed, int l, int r, int val)
{
    printf("%d %d %d\n", u, l, r);
    if (st <= l && r <= ed)
    {
        if (mi[u] + val >= 0) //区间最小都够减
        {
            tag(u, r - l + 1, val);
            return ;
        }
        if (mx[u] + val <= 0) //区间最大都不够减，直接清零
        {
            cler(u);
            return ;
        }
        printf("%d %d %d\n", u, l, r);
    }
    pd(u, l, r);
    int mid = l + r >> 1;
    if (st <= mid) change(lc, st, ed, l, mid, val);
    if (ed > mid) change(rc, st, ed, mid + 1, r, val);
    pu(u);
}

ll query(int u, int st, int ed, int l, int r)
{
    if (st == l && ed == r) return sum[u];
    pd(u, l, r);
    ll ret = 0; int mid = l + r >> 1;
    if (st <= mid) ret += query(lc, st, min(mid, ed), l, mid);
    if (ed > mid) ret += query(rc, max(st, mid + 1), ed, mid + 1, r);
    return ret;
}

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for (int m, a, b; q--; )
    {
        scanf("%d%d%d", &m, &a, &b);
        if (m) change(1, a, b, 1, n, m);
        else printf("%lld\n", query(1, a, b, 1, n));
    }
    return 0;
}
/*
5 7
-8 1 5
2 1 5
-3 1 3
0 1 5
*/