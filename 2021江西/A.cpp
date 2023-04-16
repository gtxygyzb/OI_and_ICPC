#include <bits/stdc++.h>
using namespace std;
const int N = 1050, P = 998244353;
int f[2][N][N], a[N][N]; //x, y 选了几个1
int main()
{
    int n, m, p, q;
    scanf("%d%d%d%d", &n, &m, &p, &q);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    
    for (int i = 1; i <= n; i++)
    {
        int u = i & 1, v = (i & 1) ^ 1;
        memset(f[u], 0, sizeof(f[u]));
        for (int j = 1; j <= m; j++)
        {
            if (i == 1 && j == 1)
            {
                f[u][1][a[1][1] == 1] = 1;
                //cout<<"st:"<<u<<" "<<1<<" "<<(a[1][1] == 1)<<endl;
                continue;
            }
            for (int k = 0; k <= n + m - 1; k++)
            {
                if (a[i][j])
                {
                    if (k > 0) f[u][j][k] = (f[v][j][k - 1] + f[u][j - 1][k - 1]) % P;
                }
                else f[u][j][k] = (f[v][j][k] + f[u][j - 1][k]) % P;
                //cout<<i<<" "<<j<<" "<<k<<" "<<f[u][j][k]<<endl;
            }
        }
    }
    int ans = 0;
    for (int k = q; k <= n + m - 1 - p; k++)
    {
        ans = (ans + f[n & 1][m][k]) % P;
        //cout<<k<<" "<<f[n & 1][m][k]<<endl;
    }
    printf("%d\n", ans);
    return 0;
}
/*
3 3 0 3
0 0 1
0 0 1
1 0 0
*/