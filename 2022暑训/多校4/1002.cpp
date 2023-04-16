#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 50, M = 6e5 + 50;

const ll inf = 1e18;
int n, m;

int bl[N], cnt;

struct Data
{
    int u;
    ll w, p;
	Data (int _u, ll _w, ll _p) {u = _u; w = _w; p = _p;}
	bool operator <(const Data &t) const
	{
		return w == t.w ? p < t.p : w > t.w;
	}
};

struct Graph
{
    int head[N], etop;
    int low[N], dfn[N], num, st[N], top, vis[N];
    ll dis[N], pp[N];
    void init()
    {
        for (int i = 0; i <= n + n; i++)
            vis[i] = head[i] = dfn[i] = st[i] = low[i] = 0;
        etop = num = top = 0;
    }
    struct Edge
    {
        int v, nxt;
        ll w, p;
    }e[M];
    void add(int u, int v, ll w, ll p)
    {
        e[++etop].v = v;
        e[etop].w = w;
        e[etop].p = p;
        e[etop].nxt = head[u];
        head[u] = etop;
    }

    void dij(int st, int ed)
    {
        priority_queue <Data> q;
        for (int i = 1; i <= n + n; i++)
            {dis[i] = inf; vis[i] = pp[i] = 0;}
        q.push(Data(st, dis[st]=0, pp[st]=0));
        while (!q.empty())
        {
            int u = q.top().u; q.pop();
            if (vis[u]) continue;
            vis[u] = 1;
            for (int v, i = head[u]; i; i = e[i].nxt)
            {
                v = e[i].v;
                if (dis[v] > dis[u] + e[i].w || (dis[v] == dis[u] + e[i].w && pp[v] < pp[u] + e[i].p))
                {
                    dis[v] = dis[u] + e[i].w;
                    pp[v] = pp[u] + e[i].p;
                    q.push(Data(v, dis[v], pp[v]));
                }
            }
        }
        printf("%lld %lld\n", dis[ed], pp[ed]);
    }

    void tarjan(int u)
    {
        dfn[u] = low[u] = ++num;
        st[++top] = u;
        for (int v, i = head[u]; i; i = e[i].nxt)
        {
            v = e[i].v;
            if (!dfn[v])
            {
                tarjan(v);
                low[u] = min(low[u], low[v]);
            }
            else if (!bl[v]) low[u] = min(low[u], dfn[v]);
        }
        if (low[u] == dfn[u])
        {
            ++cnt;
            while (st[top + 1] != u)
            {
                int x = st[top--];
                bl[x] = cnt;
            }
        }
    }
}ta, di;

void init()
{
    ta.init();
    di.init();
    cnt = 0;
    for (int i = 0; i <= n; i++) bl[i] = 0;
}

int u[M], v[M];
ll w[M], p[M];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        init();
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d%lld%lld", &u[i], &v[i], &w[i], &p[i]);
            if (w[i] == 0)
                ta.add(u[i], v[i], w[i], p[i]);
        }
        for (int i = 1; i <= n; i++)
            if (!ta.dfn[i]) ta.tarjan(i);
        
        for (int i = 1; i <= m; i++)
            if (bl[u[i]] != bl[v[i]])
            {
                //cout<<"ad: "<<bl[u[i]]<<" "<<bl[v[i]]<<endl;
                di.add(bl[u[i]], bl[v[i]], w[i], p[i]);
            }

        di.dij(bl[1], bl[n]);
    }   
    return 0;
}
/*
2
2 1
1 2 0 1
2 2
1 2 1 1
2 1 0 1

1
2 2
1 2 1 1
2 1 0 1
*/