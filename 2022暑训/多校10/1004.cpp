#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 50;

double a[MAXN], b[MAXN];
vector<int> G[MAXN];

void solve()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lf", a + i);
        G[i].clear();
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    while (1)
    {
        for (int i = 1; i <= n; i++)
        {
            int k = G[i].size() + 1;
            b[i] = a[i];
            for (int v : G[i])
            {
                b[i] += a[v];
            }
            b[i] /= k;
        }
        bool f = 1;
        for (int i = 1; i <= n; i++)
        {
            if ((b[i] - a[i]) > 1e-7) f = 0;
            a[i] = b[i];
        }
        if (f) break;
        //cnt++;
    }
    for (int i = 1; i <= n; i++) printf("%.6lf\n", a[i]);
    //printf("dasasd %d\n", cnt);
}

int main()
{
    int T = 1;
    scanf("%d", &T);
    while (T--)
    {
        solve();
    }
    return 0;
}
/*
3
7 7
100 20 30 40 50 60 70
1 3
2 3

4 5
4 7
6 5
5 7
4 6

2 1
1 2
1 2
4 2
1 2 3 4
1 2
3 4
*/

