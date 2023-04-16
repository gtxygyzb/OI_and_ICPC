#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
int n, k, a[N], ys[N];
double ans[N], sum, tots, s[N];
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a+i);
        ys[i] = a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        sum += a[i];
        s[i] = s[i - 1] + a[i];
    }
    tots = (n - 1) * sum;
    ans[0] = 2.0 * sum / n;
    for (int i = 1; i <= k; i++)
    {
        int l = 1, r = 2;
        double cnt = 0, ps = 0, lim = ans[i - 1];
        while (r < n && a[l] + a[r + 1] < lim)
            ++r;
        cnt += r - l;
        ps = 1.0 * a[l] * (r - l) + s[r] - s[l];
        ++l;
        while (l < r)
        {
            while (l != r && a[l] + a[r] >= lim)
                --r;
            if (r == l) break;
            cnt += r - l;
            ps += 1.0 * a[l] * (r - l) + s[r] - s[l];
            ++l;
        }
        ans[i] = cnt * lim * 2 / n / (n-1) + (tots - ps) * 2 / n / (n-1);
    }
    printf("%.10lf\n", ans[k]);
    return 0;
}