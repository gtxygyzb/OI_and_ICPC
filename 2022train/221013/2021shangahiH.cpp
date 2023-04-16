#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
int n, m, q, fa[N];
int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
struct Edge
{
    int u, v, w;
    void input() {scanf("%d%d%d", &u, &v, &w);}
    bool operator <(const Edge &t) const {return w < t.w;}
}e[N];
struct Data
{
    int k, id;
    bool operator <(const Data &t) const {return k == t.k ? id < t.id : k < t.k;}
};
typedef set <Data>::iterator IT;
set <Data> s[N];
int ans[N], a[N], vis[N];
int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a+i);
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++)
        e[i].input();
    sort(e + 1, e + m + 1);
    for (int x, k, i = 1; i <= q; i++)
    {
        scanf("%d%d", &x, &k);
        s[x].insert(Data{k, i});
    }
    int cnt = 0;
    for (int u, v, w, i = 1; i <= m && cnt < n - 1; i++)
    {
        u = find(e[i].u); v = find(e[i].v);
        if (u == v) continue;
        w = e[i].w;
        IT it;
        for (it = s[u].begin(); it != s[u].end(); ++it)
        {
            if (it->k + a[u] < w) ans[it->id] = it->k + a[u];
            else break;
        }
        s[u].erase(s[u].begin(), it);
        for (it = s[v].begin(); it != s[v].end(); ++it)
        {
            if (it->k + a[v] < w) ans[it->id] = it->k + a[v];
            else break;
        }
        s[v].erase(s[v].begin(), it);
        if (s[u].size() < s[v].size()) swap(u, v);
        s[u].insert(s[v].begin(), s[v].end());
        a[u] += a[v];
        fa[v] = u; ++cnt;
    }
    for (int i = 1; i <= n; i++)
    {
        int u = find(i);
        if (vis[u]) continue;
        vis[u] = 1;
        for (IT it = s[u].begin(); it != s[u].end(); ++it)
            ans[it->id] = it->k + a[u];
    }
    for (int i = 1; i <= q; i++)
        printf("%d\n", ans[i]);
    return 0;
}
/*
2 1 6
5 4
1 2 10
1 4
1 5
1 6
2 4
2 5
2 6
*/