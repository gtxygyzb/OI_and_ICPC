#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 6050, N = 1e6 + 50;
const int dx[] = {1, 1, -1, -1}, dy[] = {-1, 1, -1, 1};
ll a[M][M], ans;
int n, m, x[N], y[N], nt, vis[M][M], tim;

void work(int u, int v, int i, int j, int w)
{
    for (int k = 0; k < 4; k++)
    {
        int nu = u + i * dx[k], nv = v + j * dy[k];
        if (nu >= 1 && nu <= 6000 && nv >= 1 && nv <= 6000 && a[nu][nv] && vis[nu][nv] != tim)
            a[nu][nv] += w, vis[nu][nv] = tim;
    }
}

ll query(int u, int v, int i, int j)
{
    ll ret = 0;
    for (int k = 0; k < 4; k++)
    {
        int nu = u + i * dx[k], nv = v + j * dy[k];
        if (nu >= 1 && nu <= 6000 && nv >= 1 && nv <= 6000 && a[nu][nv] && vis[nu][nv] != tim)
            ret += a[nu][nv], vis[nu][nv] = tim;
    }
    return ret;
}
void init()
{
    for (int i = 1; i <= nt; i++)
        a[x[i]][y[i]] = 0;
}
int main()
{
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs)
    {
        scanf("%d%d", &n, &m);
        ans = 0; nt = n;
        for (int w, i = 1; i <= n; i++)
        {
            scanf("%d%d%d", x + i, y + i, &w);
            a[x[i]][y[i]] = w;
        }
        printf("Case #%d:\n", cs);
        for (int op, u, v, w, k, i = 1; i <= m; i++)
        {
            scanf("%d%d%d", &op, &u, &v);
            u = (u + ans) % 6000 + 1;
            v = (v + ans) % 6000 + 1;
            //cout<<"treu: "<<u<<" "<<v<<endl;
            if (op == 1)
            {
                scanf("%d", &w);
                a[u][v] = w; ++nt;
                x[nt] = u; y[nt] = v;
            }
            if (op == 2)
                a[u][v] = 0;
            if (op == 3)
            {
                scanf("%d%d", &k, &w);
                for (int i = 0; i <= sqrt(k); i++)
                {
                    int j = sqrt(k - i * i);
                    if (j < i) break;
                    if (i * i + j * j == k)
                    {
                        ++tim;
                        work(u, v, i, j, w), work(u, v, j, i, w);
                    }
                }
            }
            if (op == 4)
            {
                scanf("%d", &k);
                ans = 0;
                for (int i = 0; i <= sqrt(k); i++)
                {
                    int j = sqrt(k - i * i);
                    if (j < i) break;
                    if (i * i + j * j == k)
                    {
                        ++tim;
                        ans += query(u, v, i, j);
                        ans += query(u, v, j, i);
                    }
                }
                printf("%lld\n", ans);
            }
        }
        init();
    }
    return 0;
}
/*
1
3 2
2999 3000 1
3001 3000 1
3000 2999 1
1 2999 3000 1
4 2999 2999 1
*/