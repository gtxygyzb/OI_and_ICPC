#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> pa;
const int N = 1e5 + 50, inf = 0x3f3f3f3f;

int etop, head[N];
struct Edge
{
    int v, nxt;
}e[N << 2];
void add(int u, int v)
{
    e[++etop] = Edge{v, head[u]};
    head[u] = etop;
}

int n, m, k, f[N][55], du[N], spec[N];
void bfs()
{
    queue <pa> q;
    for (int i = 1; i <= n; i++)
        spec[i] = du[i] == 0;
    for (int j = 0; j <= k; j++)
    {
        f[n][j] = 0;
        q.push(pa(n, j));
    }
    while (!q.empty())
    {
        int u = q.front().first;
        int c = q.front().second;
        //cout<<"front: "<<u<<" "<<c<<" "<<f[u][c]<<endl;
        q.pop();
        if (c)
        {
            for (int v, i = head[u]; i; i = e[i].nxt)
            {
                v = e[i].v;
                if (~f[v][c - 1]) continue;
                f[v][c - 1] = f[u][c] + 1;
                q.push(pa(v, c - 1));
            }
            continue;
        }
        for (int v, i = head[u]; i; i = e[i].nxt)
        {
            if (i & 1) continue; //选择反向边
            v = e[i].v; --du[v];
            if (du[v] == 0) //此时的点是最坏情况
                for (int j = 0; j <= k; j++)
                {
                    if (~f[v][j]) continue;
                    f[v][j] = f[u][0] + 1;
                    q.push(pa(v, j));
                }
        }
        if (spec[u]) //没出边的点，可以自己更新自己
            for (int j = 1; j <= k; j++)
            {
                if (~f[u][j]) continue;
                f[u][j] = f[u][0] + 1;
                q.push(pa(u, j));
            }
    }
}
void init()
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
            f[i][j] = -1;
        head[i] = spec[i] = du[i] = 0;
    }
    etop = 0;
}
int main()
{
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; cs++)
    {
        scanf("%d%d%d", &n, &m, &k);
        init();
        for (int u, v, i = 1; i <= m; i++)
        {
            scanf("%d%d", &u, &v);
            add(u, v); add(v, u);
            ++du[u];
        }
        bfs();
        printf("Case #%d:\n", cs);
        for (int i = 1; i <= n; i++)
        {
            int ans = inf;
            for (int j = 0; j <= k; j++)
                if (~f[i][j])
                    ans = min(ans, f[i][j]);
            printf("%d\n", ans == inf ? -1 : ans);
        }
    }
    return 0;
}
/*
1
3 2 1
2 1
3 2
*/