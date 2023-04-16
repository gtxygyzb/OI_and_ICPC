#include <bits/stdc++.h>
using namespace std;
const int N = 18, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

int n, m, K, xs, ys, xt, yt;
int wall[N][N], dfn, num[N][N];
int ans;
int xq[N], yq[N], xz[N], yz[N], tot;

void clear()
{
    memset(wall, 0, sizeof(wall));
    memset(num, 0, sizeof(num));
    tot = 0;
}

void dfs(int x, int y)
{
    if (num[x][y]) return ;
    num[x][y] = 1;
    for (int u, v, k = 0; k < 4; k++)
    {
        u = x + dx[k]; v = y + dy[k];
        if (u < 1 || u > n || v < 1 || v > m) continue;
        if (k == 0 && ((wall[x - 1][y] & wall[x][y]) == 0))
            dfs(u, v);

        if (k == 1 && ((wall[x][y - 1] & wall[x][y]) == 0))
            dfs(u, v);
        
        if (k == 2 && ((wall[x - 1][y - 1] & wall[x][y - 1]) == 0))
            dfs(u, v);
        if (k == 3 && ((wall[x - 1][y - 1] & wall[x - 1][y]) == 0))
            dfs(u, v);
    }
}

void buildwall(int t)
{
    for (int k = 0; k < K; k++)
        if ((1<<k) & t)
        {
            ++tot;
            if (xq[k] == xz[k])
                for (int j = yq[k]; j <= yz[k]; j++)
                    wall[xz[k]][j] |= (1<<k);
            else
                for (int i = xq[k]; i <= xz[k]; i++)
                    wall[i][yz[k]] |= (1<<k);
        }
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ans = 0x3f3f3f3f;
        scanf("%d%d%d", &n, &m, &K);
        scanf("%d%d%d%d", &xs, &ys, &xt, &yt);
        for (int k = 0; k < K; k++) 
            scanf("%d%d%d%d", &xq[k], &yq[k], &xz[k], &yz[k]);

        for (int k = 0; k < (1<<K); k++)
        {
            clear();
            buildwall(k);
            dfs(xs + 1, ys + 1);
            if (num[xs + 1][ys + 1] == num[xt + 1][yt + 1])
                ans = min(ans, K - tot);
        }
        printf("%d\n", ans);
    }
    return 0;
}
/*
1
3 2 2 
0 0 2 1
0 1 3 1
1 0 1 2
*/