#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
int n, a[3][N];
int shun[N], ni[N];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= 2; i++)
            for (int j = 1; j <= n; j++)
                scanf("%d", &a[i][j]);
        a[1][1] = -1;
        shun[n] = max(a[1][n] + 2, a[2][n] + 1);
        ni[n] = max(a[2][n] + 2, a[1][n] + 1);
        for (int j = n - 1; j >= 1; j--)
        {
            shun[j] = max(shun[j + 1] + 1, max(a[2][j] + 1, a[1][j] + 2 * (n - j + 1)));
            ni[j] = max(ni[j + 1] + 1, max(a[1][j] + 1, a[2][j] + 2 * (n - j + 1)));
        }
        int cur = -1, ans = 2e9;
        for (int j = 1; j <= n; j++)
        {
            int res;
            if (j & 1) res = max(cur + 2 * (n - j + 1), shun[j]);
            else res = max(cur + 2 * (n - j + 1), ni[j]);

            //cout<<j<<": cur:"<<cur<<" ,"<<res<<" "<<shun[j]<<" "<<ni[j]<<endl;

            ans = min(ans, res);
            if (j & 1) cur = max(cur + 2, max(a[1][j] + 2, a[2][j] + 1));
            else cur = max(cur + 2, max(a[2][j] + 2, a[1][j] + 1));
        }
        printf("%d\n", ans);
    }
    return 0;
}
/*
1
2
0 0
0 0
*/