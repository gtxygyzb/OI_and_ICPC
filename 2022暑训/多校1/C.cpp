#include <bits/stdc++.h>
using namespace std;
const int N = 1050;
int f[2][N][N], n, m;
int v[N], w[N];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            scanf("%d%d", v+i, w+i);
        memset(f, 0, sizeof(f));
        f[0][0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            memcpy(f[i & 1], f[!(i & 1)], sizeof(f[i & 1]));

            for (int j = 0; j <= m - v[i]; j++)
                for (int k = 0; k < 1024; k++)
                    if (f[!(i & 1)][j][k])
                    {
                        //cout<< i - 1 <<" "<<j<<" "<<k<<endl;
                        //cout<< i  <<" "<<j + v[i]<<" "<<k<<endl;
                        f[i & 1][j + v[i]][k ^ w[i]] = 1;
                    }
        }
        int ans = -1;
        for (int k = 1023; ~k; k--)
            if (f[n & 1][m][k]) {ans = k; break;}
        printf("%d\n", ans);
    }
    return 0;
}