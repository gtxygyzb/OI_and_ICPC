#include <bits/stdc++.h>
using namespace std;
const int N = 1E3 + 50;
int n, m, s, e, bin[30] = {1};
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
 
int a[N][N];
int se[N][N], mx[N][N];
int tim;
int vis[N][N], vv;
 
void init()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            se[i][j] = mx[i][j] = 0;
}
 
int qx[N * N], qy[N * N], h, t;
int bfs(int x, int y, int num)
{
    h = t = 1;
    qx[1] = x; qy[1] = y;
    int ss = 0, ee = 0;
    vis[x][y] = vv;
    while (h <= t)
    {
        int ux = qx[h], uy = qy[h]; ++h;
 
        if (se[ux][uy] == 1) ss = 1;
        else if (se[ux][uy] == 2) ee = 1;
 
        for (int k = 0; k < 4; k++)
        {
            int vx = ux + dx[k], vy = uy + dy[k];
            if (vx < 1 || vx > n || vy < 1 || vy > m) continue;
            if (mx[vx][vy] != tim - 1 || (a[vx][vy] & num) == 0) continue;
            if (vis[vx][vy] == vv) continue;
            vis[vx][vy] = vv;
 
            ++t;
            qx[t] = vx; qy[t] = vy;
        }
    }
    return ss && ee;
}
int main()
{
    for (int i = 1; i < 30; i++) bin[i] = bin[i - 1] << 1;
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &n, &m, &s);
        init();
        for (int x, y, i = 1; i <= s; i++)
        {
            scanf("%d%d", &x, &y);
            se[x][y] = 1;
        }
        scanf("%d", &e);
        for (int x, y, i = 1; i <= e; i++)
        {
            scanf("%d%d", &x, &y);
            se[x][y] = 2;
        }
 
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                scanf("%d", &a[i][j]);
 
        int ans = 0; tim = 0;
        for (int k = 29; ~k; k--)
        {
            ++tim; ++vv;
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++)
                    if ((a[i][j] & bin[k]) && vis[i][j] != vv && mx[i][j] == tim - 1)
                    {
                        int flag = bfs(i, j, bin[k]);
                        if (flag)
                        {
                            ans |= bin[k];
                            for (int l = 1; l <= t; l++)
                                mx[qx[l]][qy[l]] = tim;
                        }
                    }
            if ((ans & bin[k]) == 0) --tim;
        }
        printf("%d\n", ans);
    }
    return 0;
}