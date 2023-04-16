#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
int n, k;

int head[N], etop, top;
struct Edge
{
    int u, v, nxt;
}e[N<<1], t[N];
void add(int u, int v)
{
    e[++etop].v = v;
    e[etop].nxt = head[u];
    head[u] = etop;
}
void adds(int u, int v) {add(u, v); add(v, u);}

void init()
{
    for (int i = 1; i <= n; i++)
        head[i] = 0;
    etop = top = 0;
}
int siz[N];
void dfs(int u, int fa)
{
    siz[u] = 1;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v == fa) continue;
        t[++top] = {u, v, 0};
        dfs(v, u);
        siz[u] += siz[v];
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &k);
        init();
        for (int u, v, i = 1; i < n; i++)
        {
            scanf("%d%d", &u, &v);
            adds(u, v);
        }
        dfs(1, 0);
        int ans = 0;
        for (int i = 1; i <= top; i++)
        {
            int v = t[i].v;
            if (siz[v] >= k && n - siz[v] >= k)
                ++ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}
/*
5
1 1

2 1
1 2

2 2
1 2
*/