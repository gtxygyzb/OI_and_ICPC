#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 50;

int head[N], etop;
struct Edge
{
    int v, w, nxt;
}e[N << 1];
void add(int u, int v, int w)
{
    e[++etop] = {v, w, head[u]};
    head[u] = etop;
}

int dfn[N], tim, f[N], cost[N];

int cnt, isring[N], ring[N], rdis[N];

void dfs(int u)
{
    dfn[u] = ++tim;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v == f[u]) continue;
        if (!dfn[v])
        {
            f[v] = u;
            cost[v] = e[i].w;
            dfs(v);
        }
        else if (dfn[v] > dfn[u])
        {
            for (; v != u; v = f[v])
            {
                isring[v] = 1;
                ring[++cnt] = v;
                rdis[cnt] = cost[v];
            }
            isring[u] = 1;
            ring[++cnt] = u;
            rdis[cnt] = e[i].w;
        }
    }
}

ll ans;
ll dis[N]; //不经过环的子树最大深度
void work(int u, int fa)
{
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (isring[v] || v == fa) continue;
        work(v, u);
        ans = max(ans, dis[u] + dis[v] + e[i].w);
        dis[u] = max(dis[u], dis[v] + e[i].w);
    }
}
int n;
ll A[N], B[N], C[N], D[N];
/*
前缀+dis 前缀两个dis+两点距离
后缀+dis 后缀缀两个dis+两点距离
*/
int main()
{
    scanf("%d", &n);
    for (int u, v, w, i = 1; i <= n; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
        add(v, u, w);
    }
    dfs(1); //找环
    for (int i = 1; i <= cnt; i++) //不经过环的子树直径
        work(ring[i], 0);

    ll sum = 0, mx = 0;
    for (int i = 1; i <= cnt; i++)
    {
        A[i] = max(A[i - 1], dis[ring[i]] + sum);
        B[i] = max(B[i - 1], sum + dis[ring[i]] + mx);
        mx = max(mx, dis[ring[i]] - sum); //disx - prex + prey + disy，若更新即为最大的x + 当前的y
        sum += rdis[i];
    }
    ll tmp = rdis[cnt]; //切开环
    rdis[cnt] = 0;
    sum = 0, mx = 0;
    for (int i = cnt; i; i--)
    {
        sum += rdis[i];
        C[i] = max(C[i + 1], dis[ring[i]] + sum);
        D[i] = max(D[i + 1], sum + dis[ring[i]] + mx);
        mx = max(mx, dis[ring[i]] - sum);
    }
    ll ans2 = B[cnt];
    for (int i = 1; i < cnt; i++)
    {
        ll t = max(B[i], D[i + 1]);
        t = max(t, A[i] + C[i + 1] + tmp);
        ans2 = min(ans2, t);
    }
    printf("%.1lf\n", (double) (1.0 * max(ans, ans2) / 2.0));
    return 0;
}
/*
4 
1 2 1 
1 4 2 
1 3 2 
2 4 1
*/