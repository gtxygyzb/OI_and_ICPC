#include <bits/stdc++.h>
using namespace std;
typedef set <int>::iterator IT;
const int N = 2e6 + 50;
int head[N], etop, d[N];
struct Edge
{
    int v, nxt;
}e[N * 2];
void add(int u, int v)
{
    e[++etop].v = v;
    e[etop].nxt = head[u];
    head[u] = etop;
    ++d[u];
}

set <int> se[N], s;
void dfs(int u)
{
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (d[v] == -1) continue;
        se[d[v]].erase(v);
        if (se[d[v]].size() == 1) s.erase(d[v]);
        --d[v];
        se[d[v]].insert(v);
        if (se[d[v]].size() >= 2) s.insert(d[v]);
    }
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int u, v, i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        add(u, v); add(v, u);
    }
    for (int i = 1; i <= n + n; i++)
        se[d[i]].insert(i);
    for (int i = 0; i <= n + n; i++)
        if (se[i].size() >= 2) s.insert(i);
    while (!s.empty())
    {
        int i = *s.begin();
        while (se[i].size() >= 2)
        {
            IT it = se[i].begin();
            int a = *it; ++it;
            int b = *it;
            se[i].erase(a);
            se[i].erase(b);
            d[a] = d[b] = -1;
            dfs(a); dfs(b);
            printf("%d %d\n", a, b);
        }
        if (s.find(i) != s.end())
            s.erase(i);
    }
    return 0;
}