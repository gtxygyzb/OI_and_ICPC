#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50, e9 = 1e9;
int n, t[N], a[N];
int check(int lim, int k)
{
    for (int i = 1; i <= n; i++)
    {
        t[i] = a[i];
        if (2 * t[i] < lim)
        {
            if (!k) return 0;
            --k;
            t[i] = e9;
        }
    }
    for (int i = 1; i < n; i++)
        if (min(t[i], t[i + 1]) >= lim) return 1;
    if (k >= 2) return 1;
    if (k == 0) return 0;
    for (int i = 1; i <= n; i++)
    {
        if (i != 1) {if (min(t[i - 1], e9) >= lim) return 1;}
        if (i != n) {if (min(t[i + 1], e9) >= lim) return 1;}
    }
    return 0;
}
int main()
{
    int k, ans, T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++)
            scanf("%d", a+i);
        int l = 1, r = 1e9;
        while (l <= r)
        {
            int mid = l + r >> 1;
            if (check(mid, k)) ans = mid, l = mid + 1;
            else r = mid - 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}