#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f, N = 550, M = 3e5 + 50;
int n, m, u[M], v[M], w[M];
int f[N][N];
void init()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            f[i][j] = inf;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        init();
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d%d", &u[i], &v[i], &w[i]);
            f[u[i]][v[i]] = f[v[i]][u[i]] = 1;
        }
        for (int i = 1; i <= n; i++) f[i][i] = 0;
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
        ll ans = 1e18;
        for (int i = 1; i <= m; i++)
        {
            ans = min(ans, 1ll * w[i] * min(f[u[i]][1] + f[v[i]][n] + 1, f[u[i]][n] + f[v[i]][1] + 1));
            for (int j = 1; j <= n; j++)
            {
                ans = min(ans, 1ll * w[i] * (f[j][1] + f[j][n] + min(f[u[i]][j], f[v[i]][j]) + 2));
                if (i == 3)
                    cout<<"j: "<<f[j][1] + f[j][n] + min(f[u[i]][j], f[v[i]][j]) + 2<<endl;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
/*
1
5 5
1 2 7
2 3 7
4 3 1
3 5 7
2 4 7
*/