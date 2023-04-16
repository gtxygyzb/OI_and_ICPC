#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e7 + 50;

int n, q, mi[N], vis[N], pri[N], tot, f[N];

int st[100], top, mp[N];

void init()
{
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i]) {pri[++tot] = i; mi[i] = i;}
        for (int j = 1; j <= tot && i * pri[j] <= n; j++)
        {
            vis[i * pri[j]] = 1;
            mi[i * pri[j]] = pri[j];
            if (i % pri[j] == 0) break;
        }
    }
}

void divid(int t)
{
    while (t > 1)
    {
        int div = mi[t];
        while (mi[t] == div)
            t /= div;
        if (mp[div] == 0) st[top++] = div;
        mp[div] = 1;
    }
}

ll ans;

void dfs(int dep, int xs, ll cur)
{
    if (dep == top)
    {
        //cout<<"fdsa: "<<(n / cur)<<" "<<xs-1<<endl;
        ans += (n / cur) * (xs - 1);
        return ;
    }
    dfs(dep + 1, xs, cur);
    dfs(dep + 1, xs ^ 2, cur * st[dep]);
}
int main()
{
    scanf("%d%d", &n, &q);
    init();

    for (ll u, v; q--;)
    {
        scanf("%lld%lld", &u, &v);
        ll gcd = __gcd(u, v);
        if (gcd == 1) {puts("1 1"); continue;}

        ll m = min(u * v / gcd, 1ll * n);

        ll lcm = u * v / gcd;

        if (lcm <= 1e7 && f[lcm]) {printf("2 %lld\n", f[lcm]); continue;}

        top = 0;
        divid(u); divid(v);

        ans = 0;

        dfs(0, 2, 1);
        printf("2 %lld\n", ans + (gcd == 2));
        if (lcm <= 1e7) f[lcm] = ans;

        for (int i = 0; i < top; i++)
            mp[st[i]] = 0;
    }
    return 0;
}
/*
30 2
24 12
30 24
*/