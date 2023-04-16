#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50, maxn=100;

template<class T>void read(T &x)
{
    x=0;int f=0;char ch=getchar();
    while(ch<'0'||ch>'9')  {f|=(ch=='-');ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    x=f?-x:x;
    return;
}

int n, m, A, B, C;
int dfn, in[N], out[N];

namespace Seg
{
    int rt[N], lc[N * 40], rc[N * 40], top, t[N * 40];
    void init()
    {
        for (int i = 0; i <= top; i++)
            t[i] = lc[i] = rc[i] = 0;
        top = 0;
        for (int i = 0; i <= n + 50; i++)
            rt[i] = 0;
    }
	void add(int &u, int l, int r, int pos)
	{
		u = ++top; ++t[u];
		if (l == r) return ;
		int mid = l + r >> 1;
		if (pos <= mid) add(lc[u], l, mid, pos);
		else add(rc[u], mid + 1, r, pos);
        
	}
	void add(int id,int pos)
	{
		add(rt[id], 1, n, pos);
	}
    int work(int x, int y)
	{
        if (x == y) return x;
		if (!x || !y) return x|y;
		int u = ++top;
		lc[u] = work(lc[x], lc[y]);
		rc[u] = work(rc[x], rc[y]);
        t[u] = t[lc[u]] + t[rc[u]];
		return u;
	}
    void merge(int u,int v)
	{
		rt[u] = work(rt[u], rt[v]);
	}

    int hb(int x, int y)
	{
        if (x == y) return x;
		if (!x || !y) return 0;
		int u = ++top;
		lc[u] = hb(lc[x], lc[y]);
		rc[u] = hb(rc[x], rc[y]);
        t[u] = t[lc[u]] + t[rc[u]];
		return u;
	}
    void inter(int u,int v)
	{
		rt[u] = hb(rt[u], rt[v]);
	}
    int query(int u, int st, int ed, int l, int r)
    {
        if (!u) return 0;
        if (st == l && ed == r) return t[u];
        int mid = l + r >> 1, ret = 0;
        if (st <= mid) ret += query(lc[u], st, min(mid, ed), l, mid);
        if (ed > mid) ret += query(rc[u], max(st, mid + 1), ed, mid + 1, r);
        return ret;
    }
    int query(int u, int st, int ed)
    {
        return query(rt[u], st, ed, 1, n);
    }
}

int head[N], etop;
struct Edge
{
    int v, nxt;
}e[N];
void add(int u, int v)
{
    e[++etop].v = v;
    e[etop].nxt = head[u];
    head[u] = etop;
}

void dfs(int u, int fa)
{
    in[u] = ++dfn;
    Seg::add(u, in[u]);
    Seg::merge(u, fa);
    for (int v, i = head[u]; i; i = e[i].nxt)
    {
        v = e[i].v;
        dfs(v, u);
    }
    out[u] = dfn;
}

void init()
{
    dfn = etop = 0;
    for (int i = 1; i <= n; i++)
        head[i] = 0;
    Seg::init();
}

struct Query
{
    int l, r;
}q[N];
bool cmp(Query q1, Query q2)
{
    return q1.l == q2.l ? q1.r > q2.r : q1.l < q2.l;
}
int main()
{
	freopen("A.in", "r", stdin); 
    int T;
    scanf("%d", &T);
    while (T--)
    {
        read(n); read(m);
        init();
        for (int f, i = 2; i <= n; i++)
        {
            read(f);
            add(f, i);
        }
        dfs(1, 0);
        int sttop = Seg::top;
        while (m--)
        {
            int x;
            read(A); read(B); read(C);
            Seg::rt[n + 1] = Seg::rt[n + 2] = 0;
            for (int i = 1; i <= A; i++)
            {
                read(x);
                printf("%d %d\n", i, Seg::top);
                Seg::merge(n + 1, x);
            }
            for (int i = 1; i <= B; i++)
            {
                read(x);
                Seg::merge(n + 2, x);
            }

            Seg::inter(n + 1, n + 2);
            for (int i = 1; i <= C; i++)
            {
                read(x);
                q[i].l = in[x]; q[i].r = out[x];
            }
            sort(q + 1, q + C + 1, cmp);

            int st = q[1].l, ed = q[1].r, ans = 0;
            for (int i = 2; i <= C; i++)
            {
                if (q[i].l == st) continue;
                if (q[i].l > ed)
                {
                    ans += Seg::query(n + 1, st, ed);
                    st = q[i].l; ed = q[i].r;
                }
                else ed = q[i].r;
            }
            ans += Seg::query(n + 1, st, ed);
            printf("%d\n", ans);

            for (int i = sttop + 1; i <= Seg::top; i++)
                Seg::lc[i] = Seg::rc[i] = Seg::t[i] = 0;

            Seg::top = sttop;
        }
    }
    return 0;
}
