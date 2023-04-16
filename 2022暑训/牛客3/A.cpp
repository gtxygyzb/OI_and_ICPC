#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50, M = 17;

int bin[N] = {1};
int n, k, key[N], kx[N];

struct Tree
{
    int head[N], etop, val[N], dep[N];
    int f[N][20], num[N], lca;
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

    void dfs(int u, int fa)
    {
        dep[u] = dep[fa] + 1;
        f[u][0] = fa;
        for (int i = 1; i <= M; i++)
            f[u][i] = f[f[u][i - 1]][i - 1];
        if (key[u]) ++num[u];

        for (int v, i = head[u]; i; i = e[i].nxt)
        {
            v = e[i].v;
            dfs(v, u);
            num[u] += num[v];
        }
    }
    int getlca(int x, int y)
    {
        if (dep[x] > dep[y]) swap(x, y);
        int d = dep[y] - dep[x];
        for (int i = 0; i <= M; i++)
            if (bin[i] & d) y = f[y][i];
        for (int i = M; i >= 0; i--)
            if (f[x][i] != f[y][i])
            {
                x = f[x][i];
                y = f[y][i];
            }
        return x == y ? x : f[x][0];
    }
    void input()
    {
        for (int i = 1; i <= n; i++)
            scanf("%d", val+i);
        for (int fa, i = 2; i <= n; i++)
        {
            scanf("%d", &fa);
            add(fa, i);
        }
        dfs(1, 0);
        lca = kx[1];
        for (int i = 2; i <= k; i++)
        {
            //cout<<lca<<", "<<kx[i]<<endl;
            lca = getlca(lca, kx[i]);
        }
        //cout<<"lca: "<<lca<<endl;
    }

    int work(int x, int id)
    {
        int d = dep[x] - dep[lca] - 1;
        for (int i = 0; i <= M; i++)
            if (d & bin[i]) x = f[x][i];
        if (num[x] > 1)
        {
            //cout<<"lca: "<<lca<<endl;
            return val[lca];
        }
        int y = (id == 1 ? kx[2] : kx[1]);
        for (int i = M; ~i; i--)
        {
            //cout<<y<<" "<<num[y]<<" "<<k - 1<<endl;
            if (f[y][i] != 0 && num[f[y][i]] < k - 1) y = f[y][i];
        }
        if (num[y] < k - 1) y = f[y][0];
        //cout<<"y: "<<y<<endl;
        return val[y];
    }

}A, B;

int main()
{
    for (int i = 1; i <= 17; i++)
        bin[i] = bin[i - 1] << 1;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; i++)
    {
        scanf("%d", kx+i);
        key[kx[i]] = 1;
    }
    A.input();
    B.input();

    int ans = 0;
    for (int i = 1; i <= k; i++)
        if (A.work(kx[i], i) > B.work(kx[i], i)) ++ans;
    printf("%d\n", ans);
    return 0;
}