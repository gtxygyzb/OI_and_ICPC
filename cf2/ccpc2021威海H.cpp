#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50, inf = 0x3f3f3f3f;

int n, ans, dw[N], dv[N];
vector <int> vec[N];
vector <int> dep[N];

int lid(int i, int j) {return (i - 1) * n + j + 1;}
int rid(int i) {return n * n + i;}
namespace Net
{
    int S, T, etop = 1, head[N], cur[N];
    int dis[N], vis[N], tim;
    struct Edge
    {
        int v, r, nxt;
    }e[N<<1];
    void addedge(int u, int v, int r)
    {
        e[++etop] = {v, r, head[u]};
        head[u] = etop;
    }
    void add(int u, int v, int r)
    {
        addedge(u, v, r);
        addedge(v, u, 0);
    }
    int bfs()
    {
        for(int i = 1; i <= T; i++)
            cur[i] = head[i];
        ++tim;
        dis[S] = 0; vis[S] = tim;
        queue <int> q;
        q.push(S);
        while (!q.empty())
        {
            int u = q.front(); q.pop();
            for (int v, i = head[u]; i; i = e[i].nxt)
            {
                v = e[i].v;
                if (vis[v] != tim && e[i].r)
                {
                    vis[v] = tim;
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
            }
            if (vis[T] == tim) break;
        }
        return vis[T] == tim;
    }
    int dfs(int u, int lim)
    {
        if (u == T) return lim;
        if (dis[u] >= dis[T]) return 0;
        for (int i = cur[u]; i && lim; i = e[i].nxt)
        {
            cur[u] = i;
            int v = e[i].v, flow;
            if (e[i].r && dis[v] == dis[u] + 1 && (flow = dfs(v, min(lim, e[i].r))))
            {
                e[i].r -= flow;
                e[i ^ 1].r += flow;
                return flow;
            }
        }
        dis[u] = -1;
        return 0;
    }
    int dinic()
    {
        int ret = 0, flow;
        while (bfs())
            while (flow = dfs(S, inf))
                ret += flow;
        return ret;
    }

    void init(int u, int fa, int d)
    {
        dep[d].push_back(u);
        for (int i = 0; i < vec[u].size(); i++)
            if (vec[u][i] != fa) init(vec[u][i], u, d + 1);
    }
    void build()
    {
        S = n * n + n + 1; T = S + 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int u = lid(i, j);
                if (j == 0) add(S, u, dv[0]);
                else
                {
                    add(S, u, dv[j] - dv[j - 1]);
                    add(u, u - 1, inf);
                }
            }
            for (int j = 0; j < n; j++)
                dep[j].clear();
            
            init(i, 0, 0);
            for (int j = 0; j < n; j++)
                for (int k = 0; k < dep[j].size(); k++)
                {
                    int v = dep[j][k];
                    add(lid(i, j), rid(v), inf);
                }
        }
        for (int i = 1; i <= n; i++)
            add(rid(i), T, dw[i]);
        printf("%d\n", ans - dinic());
    }
}


int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", dw+i);
    for (int i = 0; i < n; i++)
        scanf("%d", dv+i);
    ans = dv[n - 1] * n;
    for (int u, v, i = 1; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    Net::build();
    return 0;
}
/*
*/