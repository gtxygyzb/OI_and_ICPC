#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 50;
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

ll f[N][2];
int d[N];
ll s[N];
void dfs(int u, int k)
{
    ll ret = k * s[u];
    f[u][0] = f[u][1] = ret;
    f[u][1] += s[u];
    if (d[u] == 0) return ;
    int q = k / d[u], r = k % d[u];
    
    vector <ll> vec;
    for (int v, i = head[u]; i; i = e[i].nxt)
    {
        dfs(v = e[i].v, q);
        f[u][0] += f[v][0];
        f[u][1] += f[v][0];
        vec.push_back(f[v][1] - f[v][0]);
    }
    sort(vec.begin(), vec.end(), greater<int>());
    for (int i = 0; i < r; i++)
    {
        f[u][0] += vec[i];
        f[u][1] += vec[i];
    }
    f[u][1] += vec[r];
}
int n, k;
void init()
{
    for (int i = 1; i <= n; i++)
    {
        head[i] = d[i] = 0;
        f[i][0] = f[i][1] = 0;
    }
    etop = 0;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &k);
        init();
        for (int fa, i = 2; i <= n; i++)
        {
            scanf("%d", &fa);
            add(fa, i); ++d[fa];
        }
        for (int i = 1; i <= n; i++)
            scanf("%lld", &s[i]);
        dfs(1, k);
        printf("%lld\n", f[1][0]);
    }
    return 0;
}
/*
1
2 2
1 1
2 1 1
*/