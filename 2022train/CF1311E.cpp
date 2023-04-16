#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 50;

int n, d, dep[N], fa[N];
int a[N], vis[N];
void solve()
{
    scanf("%d%d", &n, &d);
    memset(vis, 0, sizeof(vis));
    int mx = 0;
    for (int i = 2; i <= n; i++)
    {
        fa[i] = i >> 1;
        dep[i] = dep[fa[i]] + 1;
        d -= dep[i];
        mx = max(mx, dep[i]);
    }
    int x = n;
    for (int x = n; x; x = fa[x])
        a[dep[x]] = x, vis[x] = 1;
    for (int i = n; i >= 1; i--)
    {
        if (vis[i]) continue;
        int pre = mx;
        while (dep[fa[i]] < pre && d)
        {
            fa[i] = a[dep[fa[i]] + 1];
            dep[i] = dep[fa[i]] + 1;
            if (dep[i] > mx) {a[++mx] = i; vis[i] = 1;}
            --d;
        }
    }
    if (d) puts("NO");
    else
    {
        puts("YES");
        for (int i = 2; i <= n; i++)
            printf("%d%c", fa[i], i == n ? '\n' : ' ');
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}