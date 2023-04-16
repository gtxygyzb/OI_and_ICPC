#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 50, D = 20;
//同一个子串出现在不同位置算多个
//询问第k个串几次出现在[l, r]串里
namespace Seg
{
    int lc[N * D], rc[N * D], sum[N * D], top;
    void add(int &u, int l, int r, int pos, int val)
    {
        if (!u) u = ++top;
        sum[u] += val;
        if (l == r) return ;
        int mid = l + r >> 1;
        if (pos <= mid) add(lc[u], l, mid, pos, val);
        else add(rc[u], mid + 1, r, pos, val);
    }
    int merge(int x, int y)
    {
        if (!x || !y) return x + y;
        int u = ++top;
        sum[u] = sum[x] + sum[y];
        lc[u] = merge(lc[x], lc[y]);
        rc[u] = merge(rc[x], rc[y]);
        return u;
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
}

int ch[N][26], mx[N], fa[N], last, top = 1, t[N], rk[N];

int add(int last, int c)
{
    if (ch[last][c] && mx[last] + 1 == mx[ch[last][c]])
        return ch[last][c];
    int p = last, np = ++top;
    mx[np] = mx[p] + 1;
    for (; p && !ch[p][c]; p = fa[p]) ch[p][c] = np;
    if (!p) fa[np] = 1;
    else
    {
        int q = ch[p][c];
        if (mx[q] == mx[p] + 1) fa[np] = q;
        else
        {
            int nq = p == last ? np : ++top;
            mx[nq] = mx[p] + 1;
            memcpy(ch[nq], ch[q], sizeof(ch[q]));
            for (; p && ch[p][c] == q; p = fa[p])
                ch[p][c] = nq;
            fa[np] = nq;
            fa[nq] = fa[q];
            fa[q] = nq;
        }
    }
    return np;
}

int id[N], rt[N];
char s[N];

void work()
{
    for (int i = 1; i <= top; i++) ++t[mx[i]];
    for (int i = 1; i <= top; i++) t[i] += t[i - 1];
    for (int i = top; i >= 1; i--) rk[t[mx[i]]--] = i;
    for (int i = top; i >= 2; i--)
    {
        int u = rk[i];
        rt[fa[u]] = Seg::merge(rt[fa[u]], rt[u]);
    }
}
int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s);
        last = 1;
        for (int len = strlen(s), j = 0; j < len; j++)
        {
            last = add(last, s[j] - 'a');
            Seg::add(rt[last], 1, n, i, 1);
        }
        id[i] = last;
    }
    work();
    for (int l, r, k; q--;)
    {
        scanf("%d%d%d", &l, &r, &k);
        printf("%d\n", Seg::query(rt[id[k]], l, r, 1, n));
    }
    return 0;
}
/*
5 1
a
ab
abab
ababab
b
1 5 1
*/