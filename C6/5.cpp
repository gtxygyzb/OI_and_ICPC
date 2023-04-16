#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 50;
int T, n, m, ans[N * N], top;

int a[N][N], vec[N], t[N*N], tans;
void work(int u)
{
    for (int i = 1; i <= 3; i++)
        if (a[u][vec[i]])
        {
            a[u][vec[i]] = a[vec[i]][u] = 0;
            int tmp = vec[i];
            ans[++top] = vec[i];
            vec[i] = ans[top - n + 3];
            work(ans[top]);
        }
    t[++tans] = u;
}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                a[i][j] = a[j][i] = 1;
        for (int i = 1; i <= n - 3; i++)
        {
            if (i > 1) a[i-1][i] = a[i][i-1] = 0;
            ans[i] = i;
        }
        top = n - 3;
        vec[1] = n-2;
        vec[2] = n-1;
        vec[3] = n;
        work(n-3);
        for (int i = 1; i <= tans; i++)
            cout<<t[i];
        /*for (int l, i = 1; i <= m; i++)
        {
            scanf("%d", &l);
        }*/
    }
    return 0;
}