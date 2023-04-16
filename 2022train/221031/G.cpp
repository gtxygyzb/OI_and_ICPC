#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 50;

int etop, head[N];
struct Edge
{
    int v, nxt;
}e[N];
void add(int u, int v)
{
    e[++etop] = Edge{v, head[u]};
    head[u] = etop;
}

int n;
ll a[N], f[N][5], g[N], h[N], down[N], ans;

void cmax(ll &x, ll y) {x = max(x, y);}
void dfs(int u, int fa)
{
    f[u][1] = down[u] = a[u];
    for (int v, i = head[u]; i; i = e[i].nxt)
    {
        v = e[i].v;
        if (v == fa) continue;
        dfs(v, u);

        cmax(f[u][2], f[v][2]);
        cmax(f[u][2], f[u][1] + f[v][1]);
        cmax(f[u][2], down[u] + g[v]);
        cmax(f[u][2], g[u] + down[v]);

        cmax(f[u][1], f[v][1]);
        cmax(f[u][1], down[u] + down[v]);

        cmax(g[u], g[v] + a[u]);
        cmax(g[u], f[v][1] + down[u]);
        cmax(g[u], h[u] + down[v] + a[u]);

        cmax(h[u], f[v][1]);

        cmax(down[u], down[v] + a[u]);
    }
}

int did[N], cid[N];
void work(int u, int fa)
{
    int mx[4] = {-1, -1, -1, -1};
    for (int v, i = head[u]; i; i = e[i].nxt)
    {
        v = e[i].v;
        if (v == fa) continue;
        work(v, u);
        for (int i = 0; i < 4; i++)
        {
            if (mx[i] == -1) {mx[i] = v; break;}
            if (down[v] > down[mx[i]])
            {
                for (int j = 3; j > i; j--)
                    mx[j] = mx[j - 1];
                mx[i] = v;
                break;
            }
        }
    }
    for (int i = 0; i < 4; i++)
    {
        f[u][4] += down[mx[i]];
        if (i != 3) f[u][3] += down[mx[i]];
        if (i == 0) did[u] = mx[i];
        if (i == 1) cid[u] = mx[i];
    }
}
void dp(int u, int fa, ll pre)
{
    cmax(ans, max(f[u][4], f[u][3] + pre));
    for (int v, i = head[u]; i; i = e[i].nxt)
    {
        ll dis;
        v = e[i].v;
        if (v == fa) continue;
        if (v == did[u])
            dis = cid[u] == -1 ? 0 : down[cid[u]];
        else
            dis = did[u] == -1 ? 0 : down[did[u]];
        dp(v, u, max(pre, dis) + a[u]);
    }
}


int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", a+i);
    for (int u, v, i = 1; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        add(u, v); add(v, u);
    }
    dfs(1, 0);
    ans = f[1][2];
    work(1, 0);
    dp(1, 0, 0);
    printf("%lld\n", ans);
    return 0;
}