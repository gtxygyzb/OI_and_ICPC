#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 50, L = 18;

int head[N], etop;
struct Edge
{
    int v, nxt;
}e[N];
void add(int u, int v)
{
    e[++etop] = Edge{v, head[u]};
    head[u] = etop;
}

int n, m, q, fa[N], cnt, val[N];
int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}

int dep[N], anc[N][20], st[N][20];
void init()
{
    for (int i = 1; i <= n + n; i++)
        fa[i] = i, head[i] = 0;
    etop = 0;
    cnt = n;
}
void dfs(int u, int f)
{
    anc[u][0] = f;
    dep[u] = dep[f] + 1;
    for (int i = head[u]; i; i = e[i].nxt)
        dfs(e[i].v, u);
}
int bin[L + 5], lo[N];
int lca(int x,int y)
{
    if (dep[x] > dep[y]) swap(x, y);
    int d = dep[y] - dep[x];
    for (int i = 0; i < L; i++)
        if (bin[i] & d) y = anc[y][i];
    for (int i = L - 1; ~i; i--)
        if (anc[x][i] != anc[y][i])
        {
            x = anc[x][i];
            y = anc[y][i];
        }
    return x == y ? x : anc[x][0];
}

int query(int l,int r)
{
    int len = lo[r - l + 1];
	return max(st[l][len], st[r - bin[len] + 1][len]);
}
int main()
{
    bin[0] = 1; lo[0] = -1;
    for (int i = 1; i <= L; i++)
        bin[i] = bin[i - 1] << 1;
    for (int i = 1; i <= N - 50; i++)
        lo[i] = lo[i >> 1] + 1;
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &n, &m, &q);
        init();
        for (int u, v, i = 1; i <= m; i++)
        {
            scanf("%d%d", &u, &v);
            u = find(u); v = find(v);
            if (u != v)
            {
                val[++cnt] = i;
                fa[u] = cnt; fa[v] = cnt;
                add(cnt, u); add(cnt, v);
            }
        }
        dfs(cnt, 0);
        for (int j = 1; j <= L; j++)
            for (int i = 1; i <= cnt; i++)
                anc[i][j] = anc[anc[i][j - 1]][j - 1];
        for (int i = 1; i < n; i++)
        {
            st[i][0] = val[lca(i, i + 1)];
            //cout<<i<<" "<<i + 1<<" "<<lca(i, i + 1)<<endl;
        }
        
        for (int j = 1; bin[j] < n; j++)
            for (int i = 1; i + bin[j] - 1 < n; i++)
                st[i][j] = max(st[i][j - 1], st[i + bin[j - 1]][j - 1]);
        for (int l, r; q--;)
        {
            scanf("%d%d", &l, &r); --r;
            printf("%d ", query(l, r));
        }
        puts("");
    }
    return 0;
}
/*
1
5 5 5
1 2
1 3
2 4
3 4
3 5

1 4
3 4
2 2
2 5
3 5
*/