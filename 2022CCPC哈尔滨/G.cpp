#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 50, M = 2e5 + 50;
const double inf = 1e18;

int head[N], etop;
struct Edge
{
    int v, nxt;
    double w;
}e[M];
void add(int u, int v, double w)
{
    e[++etop].v = v;
    e[etop].w = w;
    e[etop].nxt = head[u];
    head[u] = etop;
}

struct Data
{
    int u;
    double w;
    Data (int _u, double _w) {u = _u, w = _w;}
    bool operator <(const Data &t) const {return w > t.w;}
};

int vis[N];
int n, m, k, id[20];

void dij(double *dis, int S)
{
    for (int i = 1; i <= n; i++)
        dis[i] = inf, vis[i] = 0;
    priority_queue <Data> q;
    q.push(Data(S, dis[S]=0));
    while (!q.empty())
    {
        int u = q.top().u; q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int v, i = head[u]; i; i = e[i].nxt)
        {
            v = e[i].v;
            if (dis[v] > dis[u] + e[i].w)
            {
                dis[v] = dis[u] + e[i].w;
                q.push(Data(v, dis[v]));
            }
        }
    }
}

double dis[N], dk[20][N];
int bin[25] = {1};
double t, r, p[20], f[19][N * 6];
int main()
{
    scanf("%lf%lf", &t, &r);
    scanf("%d%d", &n, &m);
    for (int u, v, w, i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
        add(v, u, w);
    }
    scanf("%d", &k);
    for (int i = 1; i <= k; i++)
        bin[i] = bin[i - 1] << 1;
    for (int i = 0; i < k; i++)
    {
        scanf("%d%lf", id+i, &p[i]);
        p[i] /= 100.0;
    }

    dij(dis, n);
    if (dis[1] == inf) return 0 * puts("-1");
    for (int i = 0; i < k; i++)
        dij(dk[i], id[i]);
    
    for (int i = 0; i < k; i++)
        f[i][0] = dis[id[i]] / t;

    for (int u = 1; u < bin[k]; u++)
        for (int i = 0; i < k; i++)
        {
            f[i][u] = dis[id[i]] / t;
            for (int j = 0; j < k; j++)
            {
                if (bin[j] & u)
                {
                    f[i][u] = min(f[i][u], dk[j][id[i]] / t + p[j] * f[j][u ^ bin[j]] + (1 - p[j]) * 1.0 * dis[id[j]] / r);
                }
            }
        }
    double ans = dis[1] / t;
    for (int i = 0; i < k; i++)
        ans = min(ans, dk[i][1] / t + f[i][bin[k] - 1]);
    printf("%.8lf\n", ans);
    return 0;
}
/*
3 15
4 3
1 2 600
1 3 300
2 4 900
0
*/