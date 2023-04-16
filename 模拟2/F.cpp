#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 50, M = 1e6 + 1e5;
ll ans;
int a[N], n;
int cnt[M][21][2];
int etop, head[N];
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
 
void add(int u, int fa, int val)
{
    for (int i = 0; i <= 20; i++)
        cnt[a[u]][i][(u>>i)&1] += val;
    for (int v, i = head[u]; i; i = e[i].nxt)
    {
        v = e[i].v;
        if (v == fa) continue;
        add(v, u, val);
    }
}
 
void update(int u, int fa, int num)
{
    int val = a[u] ^ num;
    for (int i = 0; i <= 20; i++)
        ans += 1LL * (1<<i) * cnt[val][i][!((u>>i)&1)];
    for (int v, i = head[u]; i; i = e[i].nxt)
    {
        v = e[i].v;
        if (v == fa) continue;
        update(v, u, num);
    }
}
 
void dfs2(int u, int fa, int keep)
{
    for (int v, i = head[u]; i; i = e[i].nxt) //统计轻儿子子树答案
    {
        v = e[i].v;
        if (v == fa || v == son[u]) continue;
        dfs2(v, u, 0);
    }
    if (son[u]) //统计重儿子子树答案，并保留
        dfs2(son[u], u, 1);
    for (int v, i = head[u]; i; i = e[i].nxt) //再次访问轻儿子，保留答案
    {
        v = e[i].v;
        if (v == fa || v == son[u]) continue;
        update(v, u, a[u]);
        add(v, u, 1);
    }
    for (int i = 0; i <= 20; i++) //保留该点(u)答案
        ++cnt[a[u]][i][(u>>i)&1];
    if (!keep) //删除答案
        add(u, fa, -1);
}
 
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a+i);
    for (int u, v, i = 1; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        add(u, v); add(v, u);
    }
    dfs1(1, 0);
    dfs2(1, 0, 0);
    cout<<ans<<endl;
    return 0;
}
