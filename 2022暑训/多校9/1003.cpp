#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 50;

int n, q, a[N], rt[N], top;
struct Tree
{
    int l, r, sum;
}t[N*20];
void add(int &u, int pre, int l, int r, int pos, int val)
{
    t[u = ++top] = t[pre]; t[u].sum += val;
    if (l == r) return ;
    int mid = l + r >> 1;
    if (pos <= mid) add(t[u].l, t[pre].l, l, mid, pos, val);
    else add(t[u].r, t[pre].r, mid + 1, r, pos, val);
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

int st[N], stp, nxt[N], sum[N];
void init()
{
    stp = top = 0;
    memset(sum, 0, sizeof(sum));
    memset(t, 0, sizeof(t));
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        init();
        scanf("%d%d", &n, &q);
        for (int i = 1; i <= n; i++)
            scanf("%d", a+i);
        for (int i = n; i; i--)
        {
            while (stp && a[st[stp]] < a[i]) --stp;
            nxt[i] = stp ? st[stp] : n + 1;
            st[++stp] = i;
            add(rt[i], rt[nxt[i]], 1, n, i, nxt[i] != i + 1);
        }

        for (int i = 1; i < n; i++)
            if (nxt[i] == i + 1) ++sum[i];
        for (int i = 1; i < n; i++)
            sum[i] += sum[i - 1];
        

        for (int l, r; q--;)
        {
            scanf("%d%d", &l, &r);
            int ans = query(rt[l], rt[r + 1], l, r, 1, n) - /*- sum[r - 1] + sum[l - 1] - */query(rt[l], rt[r + 1], r, r, 1, n);
            //cout<<query(rt[l], rt[r + 1], l, r, 1, n)<<" "/*<< sum[r - 1] - sum[l - 1] <<" "*/<<query(rt[l], rt[r + 1], r, r, 1, n)<<endl;
            printf("%d\n", ans);
        }
    }
    return 0;
}