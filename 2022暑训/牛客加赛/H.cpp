#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
int n, m;

int head[N], etop;
struct Edge
{
    int v, nxt;
}e[N];
void add(int u, int v)
{
    e[++etop].v = v;
    e[etop].nxt = head[u];
    head[u] = etop;
}

int siz[N], two[N], fiv[N];
int tim, in[N], out[N];
int tf[N], tt[N];

void modify(int x, int id, int val)
{
    for (int i = x; i <= n; i += i & -i)
    {
        tt[i] += val * two[id];
        tf[i] += val * fiv[id];
    }
}
void change(int l, int r, int id, int val)
{
    modify(l, id, val);
    modify(r + 1, id, -val);
}
int query(int x)
{
    int r1 = 0;
    for (int i = x; i; i -= i & -i)
        r1 += tt[i];
    int r2 = 0;
    for (int i = x; i; i -= i & -i)
        r2 += tf[i];
	return min(r1, r2);
}

void dfs(int u, int fa)
{
    siz[u] = 1;
    in[u] = ++tim;
    for (int v, i = head[u]; i; i = e[i].nxt)
    {
        v = e[i].v;
        if (v == fa) continue;
        dfs(v, u);
        siz[u] += siz[v];
    }
    out[u] = tim;
    change(in[u], in[u], u, siz[u]); //当前点作为根节点，其本身对自己的贡献
    for (int v, i = head[u]; i; i = e[i].nxt)
    {
        v = e[i].v;
        if (v == fa) continue;
        change(in[v], out[v], u, siz[u] - siz[v]); //扣去当前子树，其他点对子树的贡献
    } 
}

int q[N];
int main()
{
    scanf("%d%d", &n, &m);
    for (int u, v, i = 1; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        add(u, v); add(v, u);
    }
    for (int i = 2; i <= n; i++)
    {
        int tmp = i;
        while (tmp % 2 == 0) {tmp /= 2; ++two[i];}
        while (tmp % 5 == 0) {tmp /= 5; ++fiv[i];}
    }
    dfs(1, 0);
    for (int i = 1; i <= m; i++)
        scanf("%d", q+i);
    for (int i = 1; i <= m; i++)
        printf("%d\n", query(in[q[i]]));
    return 0;
}