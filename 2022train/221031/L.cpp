#include <bits/stdc++.h>
using namespace std;
const int N = 20;
double a[N][N];
int p[N], n, m;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        if (i <= 2 * m)
            p[i] = (i + 1) / 2;
        else p[i] = 1;
        a[i][p[i]] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 1; j--)
            printf("%.12lf ", a[i][j]);
        puts("");
    }
    return 0;
}