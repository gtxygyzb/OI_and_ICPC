#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int M = 2e5, N = 5e5 + 50;
vector <int> p[N];
int n, m, fa[N], siz[N], a[N];
ll ans;
map <int, int> mp[N];

int find(int x)
{
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= M; i++)
        for (int j = i + i; j <= M; j += i)
        {
            int y = j ^ i;
            if (__gcd(j, y) == i)
                p[j].push_back(y);
        }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        ++mp[i][a[i]];
    }
    for (int i = 1; i <= n + m; i++)
        fa[i] = i, siz[i] = 1;
    for (int opt, x, y; m--;)
    {
        scanf("%d%d%d", &opt, &x, &y);
        if (opt == 1)
        {
            ++mp[x][y];
            a[x] = y;
        }
        if (opt == 2)
        {
            int u = find(x), v = find(y);
            if (u == v) {printf("%lld\n", ans); continue;}
            if (siz[u] > siz[v]) swap(u, v);

            for (map <int, int>::iterator it = mp[u].begin(); it != mp[u].end(); it++)
            {
                int val = (*it).fi;
                int len = p[val].size();
                for (int i = 0; i < len; i++)
                    if (mp[v].count(p[val][i])) ans += 1LL * (*it).se * mp[v][p[val][i]];
            }
            for (map <int, int>::iterator it = mp[u].begin(); it != mp[u].end(); it++)
                mp[v][(*it).fi] += (*it).se;
            fa[u] = v;
            siz[v] += siz[u];
        }
        if (opt == 3)
        {
            int u = find(x);

            int len = p[a[x]].size();
            for (int i = 0; i < len; i++)
                if (mp[u].count(p[a[x]][i]))
                    ans -= mp[u][ p[a[x]][i] ];
            
            --mp[u][a[x]];
            a[x] = y;

            len = p[a[x]].size();
            for (int i = 0; i < len; i++)
                if (mp[u].count(p[a[x]][i]))
                    ans += mp[u][ p[a[x]][i] ];

            ++mp[u][a[x]];
        }
        printf("%lld\n", ans);
    }
    return 0;
}