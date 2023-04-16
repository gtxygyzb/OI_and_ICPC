#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;

int n, a[N], f[N];
int pre[N][101], ans;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a+i);
    for (int i = 2; i <= n; i++)
    {
        memcpy(pre[i], pre[i - 1], sizeof(pre[i]));
        pre[i][a[i - 1]] = i - 1;
    }
    for (int val = 2; val <= 200; val++)
    {
        memset(f, 0, sizeof(f));
        for (int i = 2; i <= n; i++)
        {
            f[i] = f[i - 1];
            if (val - a[i] <= 0) continue;
            if (val - a[i] > 100) continue;
            int j = pre[i][val - a[i]];
            if (j == 0) continue;
            //cout<<val<<": "<<i<<" "<<j<<" "<<f[j - 1]<<endl;
            f[i] = max(f[i], f[j - 1] + 1);
        }
        ans = max(ans, f[n]);
    }
    printf("%d\n", ans + ans);
    return 0;
}
/*
11
3 1 4 1 5 9 2 6 5 3 5


7
1 1 1 1 1 1 1
*/