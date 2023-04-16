#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 50;

int n, m, fa[N], r[N];

void init()
{
    for (int i = 1; i <= 2 * n; i++)
        fa[i] = i;
    memset(r, 0, sizeof(r));
}

int find(int x)
{
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}
void hb(int x, int y)
{
    int fx = find(x), fy = find(y);
    fa[fx] = fy; //fy是目前根节点
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        init();
        priority_queue <int> q;
        for (int x, y, i = 1; i <= m; i++)
        {
            scanf("%d%d", &x, &y);
            y += n;
            hb(x, y);
            ++r[x];
            ++r[y];
        }
        for (int i = n + 1; i <= n + n; i++)
            q.push(-i);
        printf("%d\n", n + n - m);
        for (int i = 1; i <= n; i++)
        {
            while (r[i] < 2)
            {
                int u = -q.top(); q.pop();
                if (find(i) == find(u) && !q.empty())
                {
                    int v = -q.top(); q.pop();
                    q.push(-u); u = v;
                }
                hb(i, u);
                printf("%d %d\n", i, u - n);
                ++r[u]; ++r[i];
                if (r[u] < 2) q.push(-u);
            }
        }
    }
    return 0;
}