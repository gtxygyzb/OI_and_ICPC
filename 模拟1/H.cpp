#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e4 + 50, M = 5e5 + 50, inf = 1e9;
int n, m, fa[N], id[M];
ll ans;

int find(int x)
{
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}
struct Graph
{
    int head[N], etop;
    struct Edge
    {
        int u, v, w, nxt;
        bool operator <(const Edge &t) const
        {
            return w < t.w;
        }
        void input()
        {
            scanf("%d%d%d", &u, &v, &w);
        }
    }e[M];
    void add(int u, int v, int w)
    {
        e[++etop].v = v;
        e[etop].w = w;
        e[etop].nxt = head[u];
        head[u] = etop;
    }
    void adds(int u, int v, int w)
    {
        //cout<<"ad: "<<u<<" "<<v<<" "<<w<<endl;
        add(u, v, w);
        add(v, u, w);
    }
    bool check(int st, int opt = 0)
    {
        for (int i = 1; i <= n; i++) fa[i] = i;
        int cnt = 0;
        for (int i = st; i <= m; i++)
        {
            //cout<<"fda  "<<i<<" "<<find(e[i].u)<<" "<<find(e[i].v)<<endl;
            if (find(e[i].u) != find(e[i].v))
            {
                fa[find(e[i].u)] = find(e[i].v);
                id[i] = opt;
                ++cnt;
            }
            if (cnt == n - 1) break;
        }
        return cnt == n - 1;
    }

    void dfs(int u, int fa, int mi)
    {
        if (mi != inf) ans += mi;
        for (int i = head[u]; i; i = e[i].nxt)
            if (e[i].v != fa)
                dfs(e[i].v, u, min(mi, e[i].w));
    }
}G1, G2;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
        G1.e[i].input();
    sort(G1.e + 1, G1.e + m + 1);
    int l = 1, r = m;
    while (l < r - 1)
    {
        int mid = l + r >> 1;
        if (G1.check(mid)) l = mid;
        else r = mid - 1;
    }
    int st = G1.check(r) ? r : l;
    G1.check(st, 1);
    //cout<<"ans:"<<st<<endl;
    for (int i = st; i <= m; i++)
        if (id[i]) G2.adds(G1.e[i].u, G1.e[i].v, G1.e[i].w);
    for (int i = 1; i <= n; i++)
        G2.dfs(i, 0, inf);
    cout<<ans/2<<endl;
    return 0;
}