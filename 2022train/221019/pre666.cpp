#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 50, D = 20;
namespace Seg
{
    int lc[N * D], rc[N * D], top;
    struct Ele
    {
        int pos, cnt;
        Ele (int _pos=1e9, int _cnt=0) {pos = _pos; cnt = _cnt;}
        inline bool operator >(const Ele &t) const
        {
            return cnt == t.cnt ? pos < t.pos : cnt > t.cnt;
        }
        friend inline Ele max(Ele a, Ele b) {return (a > b) ? a : b;}
    }t[N * D];
    void add(int &u, int l, int r, int pos)
    {
        if (!u) u = ++top;
        if (l == r) {++t[u].cnt; t[u].pos = pos; return ;}
        int mid = l + r >> 1;
        if (pos <= mid) add(lc[u], l, mid, pos);
        else add(rc[u], mid + 1, r, pos);
        t[u] = max(t[lc[u]], t[rc[u]]);
    }
    int merge(int x, int y)
    {
        if (!x || !y) return x + y;
        int u = ++top;
        if (!lc[x] && !rc[x])
        {
            t[u] = t[x];
            t[u].cnt += t[y].cnt;
        }
        else
        {
            lc[u] = merge(lc[x], lc[y]);
            rc[u] = merge(rc[x], rc[y]);
            t[u] = max(t[lc[u]], t[rc[u]]);
        }
        return u;
    }
    Ele query(int u, int st, int ed, int l, int r)
    {
        if (st == l && ed == r) return t[u];
        int mid = l + r >> 1;
        Ele ret;
        if (st <= mid) ret = max(ret, query(lc[u], st, min(mid, ed), l, mid));
        if (ed > mid) ret = max(ret, query(rc[u], max(st, mid + 1), ed, mid + 1, r));
        return ret;
    }
    void query(int u, int l, int r, int n)
    {
        Ele ans = Seg::query(u, l, r, 1, n);
        if (ans.cnt == 0) ans.pos = l;
        printf("%d %d\n", ans.pos, ans.cnt);
    }
}

int ch[N][26], mx[N], fa[N], last, top = 1, t[N], rk[N];
int rt[N];

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

int anc[N][D];
void merge()
{
    for (int i = 1; i <= top; i++) ++t[mx[i]];
    for (int i = 1; i <= top; i++) t[i] += t[i - 1];
    for (int i = top; i >= 1; i--) rk[t[mx[i]]--] = i;
    for (int i = top; i >= 2; i--)
    {
        int u = rk[i];
        rt[fa[u]] = Seg::merge(rt[fa[u]], rt[u]);
        anc[u][0] = fa[u];
    }
    for (int j = 1; j < D; j++)
        for (int i = 1; i <= top; i++)
            anc[i][j] = anc[anc[i][j - 1]][j - 1];
}

char s[N], ta[N];
int n, q, id[N], lim[N];
void find()
{
    int u = 1, dep = 0;
    for (int c, len = strlen(s + 1), i = 1; i <= len; i++) 
    {
        c = s[i] - 'a';
        while (u > 1 && !ch[u][c]) {u = fa[u]; dep = mx[u];}
        if (ch[u][c]) u = ch[u][c], ++dep;
        id[i] = u;
        lim[i] = dep;
    } 
}

int main()
{
    scanf("%s%d", s + 1, &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", ta);
        last = 1;
        for (int len = strlen(ta), j = 0; j < len; j++)
        {
            last = add(last, ta[j] - 'a');
            Seg::add(rt[last], 1, n, i);
        }
    }
    merge(); //线段树合并 //倍增处理每个点往上跳2^j方步的节点是多少
    find(); //s串每个前缀代表的点id
    scanf("%d", &q);
    for (int l, r, pl, pr; q--;)
    {
        scanf("%d%d%d%d", &l ,&r, &pl, &pr);
        int u = id[pr], len = pr - pl + 1;
        if (len > lim[pr]) {printf("%d 0\n", l); continue;}
        for (int j = D - 1; ~j; j--)
            if (mx[anc[u][j]] >= len)
                u = anc[u][j];
        if (u == 1) printf("%d 0\n", l);
        Seg::query(rt[u], l, r, n);
    }
    return 0;
}