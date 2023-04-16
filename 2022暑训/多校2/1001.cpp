#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 50;

int n, m, A, B, C;
int dfn, in[N], out[N];

namespace Seg
{
    int rt[N], lc[N * 20], rc[N * 20], top, t[N * 20];
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
    int merge(int u, int v, int l, int r, int p=1)
	{
		if (!u || !v)
		{
			if (p) return u | v;
			return 0;
		}
		if (l == r) return u;
		int mid = l + r >> 1;
		u = ++top;
		lc[u] = merge(lc[u], lc[v], l, mid);
		rc[u] = merge(rc[u], rc[v], mid + 1, r);
		t[u] = t[lc[u]] + t[rc[u]];
		return u;
	}
    void merge(int u,int v, int p=1)
    {
        rt[u] = merge(rt[u], rt[v], 1, n, p);
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
    
    void dfs(int u, int l, int r)
    {
    	if (!u) return ;
    	cout<<u<<" "<<l<<" "<<r<<" "<<t[u]<<endl;
    	int mid = l + r >> 1;
    	dfs(lc[u], l, mid);
    	dfs(rc[u], mid + 1, r);
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

int ttt = 0;
void dfs(int u, int fa)
{
    //printf("%d %d %d %d\n", ++ttt, u, fa, Seg::top);
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
    //freopen("A.in", "r", stdin);
    //freopen("A.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        init();
        for (int f, i = 2; i <= n; i++)
        {
            scanf("%d", &f);
            add(f, i);
        }
        dfs(1, 0);
        int sttop = Seg::top;
        while (m--)
        {
            int x;
            scanf("%d%d%d", &A, &B, &C);
            //printf("%d %d %d\n", A, B, C);
            Seg::rt[n + 1] = Seg::rt[n + 2] = 0;
            for (int i = 1; i <= A; i++)
            {
                scanf("%d", &x);
                //printf("%d %d %d\n", i, x, Seg::top);
                Seg::merge(n + 1, x);
            }
            for (int i = 1; i <= B; i++)
            {
                scanf("%d", &x);
                Seg::merge(n + 2, x);
            }
            Seg::merge(n + 1, n + 2, 0);
            
            for (int i = 1; i <= C; i++)
            {
                scanf("%d", &x);
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
            printf("ans: %d\n", ans);
        }
    }
    return 0;
}
