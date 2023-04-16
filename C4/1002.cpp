#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 50;

int etop, head[N], n, ans, a[N];
int c[N], h[N];
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

void modify(int pos, int val)
{
    h[pos] += val;
    if (val == 1 && h[pos] == 1) ++ans;
    if (val == -1 && h[pos] == 0) --ans;
}
void dfs(int u, int fa)
{
    modify(c[u], 1);
    a[u] = ans;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v == fa) continue;
        dfs(v, u);
    }
    modify(c[u], -1);
}
void init()
{
    memset(head, 0, sizeof(head));
}
int output(int P)
{
    int ret = 0;
    for (int i = n; i >= 1; i--)
        ret = (1LL * ret * 19560929 % P + a[i]) % P;
    return ret;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        init();
        scanf("%d", &n);
        for (int fa, i = 2; i <= n; i++)
        {
            scanf("%d", &fa);
            add(fa, i);
            add(i, fa);
        }
        for (int i = 1; i <= n; i++)
            scanf("%d", &c[i]);
        for (int i = 1; i <= n; i++)
        {
            dfs(i, 0);
            printf("%d %d\n", output(1e9+7), output(1e9+9));
        }
    }
}