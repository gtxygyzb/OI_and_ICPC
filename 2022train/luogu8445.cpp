#include <bits/stdc++.h>
using namespace std;
const int N = 4e6 + 50, inf = 0x3f3f3f3f;
int n, a, b, c, ans = -inf;
int main()
{
    scanf("%d", &n);
    for (int mi = inf, mx = -inf, i = 1; i <= n; i++)
    {
        scanf("%d", &a);
        mi = min(mi, b = a - i);
        mx = max(mx, c = a + i);
        ans = max(ans, max(b - mi - 1, mx - c - 1));
    }
    printf("%d\n", ans);
    return 0;
}