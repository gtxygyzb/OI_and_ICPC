#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;
const double eps = 1e-8;
int n, m, a[N], b[N], ans;
void work()
{
    ans = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", a+i);
    for (int i = 1; i <= m; i++)
        scanf("%d", b+i);
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    b[0] = 0; b[m + 1] = 2e9;
    for (int i = 0; i <= m; i++)
    {
        int l = b[i], r = b[i + 1];
        
        int x = lower_bound(a + 1, a + n + 1, l + 1) - a;
        int y = upper_bound(a + 1, a + n + 1, r - 1) - a;
        ans = max(ans, y - x);
    }
    if (ans == 0) puts("Impossible");
    else printf("%d\n", ans);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        work();
    return 0;
}
/*
1
10 10
13 10 11 14 2 2 8 11 3 19 
20 6 9 6 8 18 14 3 18 18
*/