#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50, P = 1e9 + 7;
int n, m, a[N];
int phi(int x)
{
    if (x == 1) return 1;
    int ret = 0;
    for (int i = 1; i < x; i++)
        if (__gcd(i, x) == 1) ret++;
    return ret;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int x, y, opt, w, i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &opt, &x, &y);
        if (opt == 0)
        {
            scanf("%d", &w);
            for (int i = x; i <= y; i++)
                a[i] *= w;
        }
        else
        {
            int ans = 0;
            for (int i = x; i <= y; i++)
                ans = (ans + phi(a[i]))%P;
            cout<<ans<<endl;
        }
    }
    return 0;
}
