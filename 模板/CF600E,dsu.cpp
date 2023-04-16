/*
有一棵 n 个结点的以 1 号结点为根的有根树。
每个结点都有一个颜色，颜色是以编号表示的， i 号结点的颜色编号为 ci

如果一种颜色在以 x 为根的子树内出现次数最多，称其在以 x 为根的子树中占主导地位。显然，同一子树中可能有多种颜色占主导地位。
你的任务是对于每一个 i∈[1,n]，求出以 i 为根的子树中，占主导地位的颜色的编号和。
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 50;
int c[N], n, ac[N], x, cnt[N];
ll ans[N];

int head[N], etop;
struct Edge
{
    int v, nxt;
}e[N<<1];
void add(int u, int v)
{
    e[++etop].v = v;
    e[etop].nxt = head[u];
    head[u] = etop;
}

int siz[N], son[N];
void dfs1(int u, int fa)
{
    siz[u] = 1;
    for (int v, i = head[u]; i; i = e[i].nxt)
    {
        v = e[i].v;
        if (v == fa) continue;
        dfs1(v, u);
        siz[u] += siz[v];
        if (siz[v] > siz[son[u]])
            son[u] = v;
    }
}

void update(int u, int val)
{
    cnt[c[u]] += val;
    if (val == -1) return ;
    if (cnt[c[u]] > ac[x])
    {
        ac[x] = cnt[c[u]];
        ans[x] = c[u];
    }
    else if (cnt[c[u]] == ac[x])
        ans[x] += c[u];
}
void add(int u, int fa, int val)
{
    update(u, val);
    for (int v, i = head[u]; i; i = e[i].nxt)
    {
        v = e[i].v;
        if (v == fa) continue;
        add(v, u, val);
    }
}
void dfs2(int u, int fa, int keep)
{
    for (int v, i = head[u]; i; i = e[i].nxt)
    {
        v = e[i].v;
        if (v == fa || v == son[u]) continue;
        dfs2(v, u, 0);
    }
    if (son[u])
    {
        dfs2(son[u], u, 1);
        ans[u] = ans[son[u]];
        ac[u] = ac[son[u]];
    }
    x = u;
    for (int v, i = head[u]; i; i = e[i].nxt)
    {
        v = e[i].v;
        if (v == fa || v == son[u]) continue;
        add(v, u, 1);
    }
    update(u, 1);
    if (!keep)
        add(u, fa, -1);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", c+i);
    for (int u, v, i = 1; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        add(u, v); add(v, u);
    }
    dfs1(1, 0);
    dfs2(1, 0, 0);
    for (int i = 1; i <= n; i++)
        printf("%lld ", ans[i]);
    return 0;
}
/*
2
1 2
1 2
*/