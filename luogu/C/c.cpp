#include <bits/stdc++.h>
using namespace std;

const int N = 850;
int n, a[N][N], t[N], x[N];


int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n - i + 1; j++)
            scanf("%d", &a[i][j]);
    for (int i = n; i > 1; i--) // 第i行先排序，再按照i-1行复原
    {
        int len = n - i + 1;
        memcpy(x, a[i], sizeof(int) * (len + 5));
        sort(x + 1, x + len + 1);
        memset(t, 0 ,sizeof(t));
        for (int j = 1; j <= n - (i - 1) + 1)
            ++t[a[i - 1][j]];
        for (int j = )
    }
    return 0;
}
