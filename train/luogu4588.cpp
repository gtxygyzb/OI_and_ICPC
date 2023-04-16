#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
int q, P, pos[N];
struct Tree
{
    int t[N<<2];
    #define lc u<<1
    #define rc u<<1|1
    void pu(int u) {t[u] = 1LL * t[lc] * t[rc] % P;}
    void build(int u, int l, int r)
    {
        if (l == r)
        {
            t[u] = 1;
            return ;
        }
        int mid = l + r >> 1;
        build(lc, l ,mid);
        build(rc, mid + 1, r);
        pu(u);
    }
    void modify(int u, int l, int r, int pos, int val)
    {
        if (l == r)
        {
            t[u] = val;
            return ;
        }
        int mid = l + r >> 1;
        if (pos <= mid) modify(lc, l, mid, pos, val);
        else modify(rc, mid + 1, r, pos, val);
        pu(u);
    }
}T;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &q, &P);
        T.build(1, 1, q);
        int n = 0;
        for (int opt, x, i = 1; i <= q; i++)
        {
            scanf("%d%d", &opt, &x);
            if (opt == 1)
            {
                ++n;
                pos[i] = n;
                T.modify(1, 1, q, n, x);
            }
            else
                T.modify(1, 1, q, pos[x], 1);
            printf("%d\n", T.t[1]);
        }
    }
    return 0;
}