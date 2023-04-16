#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;

int head[N], etop;
struct Edge
{
    int v, nxt;
}e[N << 1];
void add(int u, int v)
{
    e[++etop].v = v;
    e[etop].nxt = head[u];
    head[u] = etop;
}

int dfn[N], low[N], top, iscut[N];

int cnt, bl[N], vis[N];

void tarjan(int u, int fa)
{
    dfn[u] = low[u] = ++top;
    int son = 0;
    for (int v, i = head[u]; i; i = e[i].nxt)
    {
        v = e[i].v;
        if (!dfn[v])
        {
            ++son;
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (fa == 0 && son >= 2 || fa && low[v] >= dfn[u])
                iscut[u] = 1;
        }
        else if (v != fa) low[u] = min(low[u], dfn[v]);
    }
}
int n, m, Q, u[N], v[N], ds[N];
map <int, bool> mp[N];
void dfs(int u, int fa)
{
    if (!iscut[u]) bl[u] = cnt;
    for (int v, i = head[u]; i; i = e[i].nxt)
    {
        v = e[i].v;
        if (!iscut[v] && vis[v] == 0)
        {
            vis[v] = 1;
            if (fa == 0) ++cnt;
            dfs(v, u);
        }
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &u[i], &v[i]);
        add(u[i], v[i]);
        add(v[i], u[i]);
    }
    tarjan(1, 0);
    int cutn = 0, lt = 1;
    for (int i = 1; i <= n && lt; i++)
    {
        if (iscut[i])
        {
            dfs(i, 0);
            ++cutn;
            bl[i] = ++cnt;
        }
        if (!dfn[i]) lt = 0;
    }

    for (int i = 1; i <= n; i++)
        cout<<bl[i]<<" ";
    puts("");
    for (int i = 1; i <= m; i++)
    {
        int x = bl[u[i]], y = bl[v[i]];
        if (x != y && (!mp[x][y] || !mp[y][x]))
        {
            cout<<x<<" link: "<<y<<endl;
            ++ds[x];
            ++ds[y];
            mp[x][y] = 1;
            mp[y][x] = 1;
        }
    }
    int qs = -1, zd = -1;
    for (int i = 1; i <= cnt && lt; i++)
    {
        if (ds[i] > 2) lt = 0;
        if (ds[i] == 1)
        {
            if (qs == -1) qs = i;
            else if (zd == -1) zd = i;
            else lt = 0;
        }
    }

    scanf("%d", &Q);
    for (int x, y, i = 1; i <= Q; i++)
    {
        scanf("%d%d", &x, &y);
        if (lt == 0) {puts("NO"); continue;}
        if (cutn == 0) {puts("YES"); continue;}
        if (bl[x] > bl[y]) swap(x, y);
        puts(bl[x] == qs && bl[y] == zd ? "YES" : "NO");
    }
    return 0;
}
/*
9 11
1 2
1 3
2 3
2 4
4 5
4 6
5 6
5 7
7 8
7 9
8 9
6
1 9
1 8
3 9
3 8
2 9
2 8
*/