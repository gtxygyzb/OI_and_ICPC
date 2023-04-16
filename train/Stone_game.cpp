#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 50;
typedef long long ll;
int n, q, rt[N], top;
ll ans;
struct Tree
{
    int lc, rc;
    ll sum;
}t[N * 35];

void add(int &u, int pre, int l, int r, int pos)
{
    u = ++top;
    t[u] = t[pre];
    t[u].sum += pos;
    if (l == r) return ;
    int mid = l + r >> 1;
    if (pos <= mid) add(t[u].lc, t[pre].lc, l, mid, pos);
    else add(t[u].rc, t[pre].rc, mid + 1, r, pos);
}

int query1(int u, int pre, int st, int ed, int l, int r)
{
    if (st > ed || !u || t[u].sum - t[pre].sum == 0) return -1;
    if (l == r) return l;
    int mid = l + r >> 1;
    if (ed <= mid) return query1(t[u].lc, t[pre].lc, st, ed, l, mid);
    else if (st > mid) return query1(t[u].rc, t[pre].rc, st, ed, mid + 1, r);
    else
    {
        int ret = query1(t[u].lc, t[pre].lc, st, mid, l, mid);
        if (~ret) return ret;
        return query1(t[u].rc, t[pre].rc, mid + 1, ed, mid + 1, r);
    }
}

ll query2(int u, int pre, int st, int ed, int l, int r)
{
    if (st > ed) return 0;
    if (st == l && ed == r) return t[u].sum - t[pre].sum;
    int mid = l + r >> 1;
    ll ret = 0;
    if (st <= mid) ret += query2(t[u].lc, t[pre].lc, st, min(mid, ed), l, mid);
    if (ed > mid) ret += query2(t[u].rc, t[pre].rc, max(st, mid + 1), ed, mid + 1, r);
    return ret;
}
int main()
{
    scanf("%d%d", &n, &q);
    for (int x, i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        add(rt[i], rt[i - 1], 1, 1e9, x);
    }
    for (int lp, rp, l, r; q--; )
    {
        scanf("%d%d", &lp, &rp);
        l = min((lp + ans) % n + 1, (rp + ans) % n + 1);
        r = max((lp + ans) % n + 1, (rp + ans) % n + 1);
        //cout<<"true:  "<<l<<" "<<r<<endl;
        ll x = query2(rt[r], rt[l - 1], 1, 1, 1, 1e9);
        while (1)
        {
            ll ad = query2(rt[r], rt[l - 1], 1, min(x + 1, (ll)(1e9)), 1, 1e9) - x;
            if (ad == 0) break;
            x = x + ad;
        }
        ans = x + 1;
        printf("%lld\n", ans);
    }
    return 0;
}
/*
5 1
1 4 2 1 6
1 3
*/