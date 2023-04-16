#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 50;
ll a[N];
int n;
struct Tree
{
    #define lc (u<<1)
    #define rc (u<<1|1)

    ll t[N << 2];
    void build(int u, int l, int r, int opt)
    {
        if (l == r)
        {
            if (opt == 1) t[u] = a[l];
            else t[u] = 1LL * (n - l + 1) * a[l];
            return ;
        }
        int mid = l + r >> 1;
        build(lc, l, mid, opt);
        build(rc, mid + 1, r, opt);
        t[u] = t[lc] + t[rc];
    }

    void change(int u, int l, int r, int pos, int val, int opt)
    {
        if (l == r)
        {
            if (opt == 1) t[u] = val;
            else t[u] = 1LL * (n - l + 1) * val;
            return ;
        }
        int mid = l + r >> 1;
        if (pos <= mid) change(lc, l, mid, pos, val, opt);
        else change(rc, mid + 1, r, pos, val, opt);
        t[u] = t[lc] + t[rc];
    }
    ll query(int u, int st, int ed, int l, int r)
    {
        if (st == l && ed == r) return t[u];
        ll ret = 0;
        int mid = l + r >> 1;
        if (st <= mid) ret += query(lc, st, min(mid, ed), l, mid);
        if (ed > mid) ret += query(rc, max(mid + 1, st), ed, mid + 1, r);
        return ret;
    }

}T1, T2;
int main()
{
    int m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", a+i);
    T1.build(1, 1, n, 1);
    T2.build(1, 1, n, 2);
    for (int opt, x, y; m--;)
    {
        scanf("%d%d%d", &opt, &x, &y);
        if (opt == 1)
        {
            T1.change(1, 1, n, x, y, 1);
            T2.change(1, 1, n, x, y, 2);
        }
        else
        {
            ll sum = T1.query(1, x, y, 1, n);
            ll mol = T2.query(1, x, y, 1, n);
            printf("%lld\n", mol - sum * (n - y));
        }
    }
    return 0;
}
/*
3 3
1 2 3
2 1 3
1 2 1
2 1 3
*/