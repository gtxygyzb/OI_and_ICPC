#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 50;
unordered_map <ll, int> f;
int pri[N], vis[N], tot;
void init(int lim)
{
    for (int i = 2; i <= lim; i++)
    {
        if (vis[i] == 0) pri[++tot] = i;
        for (int j = 1; j <= tot && i * pri[j] <= lim; j++)
        {
            vis[i * pri[j]] = 0;
            if (i % pri[j] == 0) break;
        }
    }
}

int vec[N], top;

ll H(ll a, ll b) {return a * 1e9 + b;}

ll dfs(ll a, ll c)
{
    if (a == 1) return 0;
    if (c == 1) return a - 1;
    if (f[H(a, c)]) return f[H(a, c)];
    ll mi = a - 1;
    for (int i = 1; i <= top; i++)
        if (c % vec[i] == 0)
        {
            ll res = a % vec[i];
            mi = min(mi, min(dfs(a / vec[i], c / vec[i]) + res + 1, dfs(a / vec[i] + 1, c / vec[i]) + vec[i] - res + 1));
        }
    return f[H(a, c)] = mi;
}
ll a, b;
int main()
{
    int T;
    scanf("%d", &T);
    init(1e5);
    while (T--)
    {
        scanf("%lld%lld", &a, &b);
        if (a > b) swap(a, b);
        ll c = b - a;
        top = 0;
        for (int i = 1; pri[i] * pri[i] <= c; i++)
            if (c % pri[i] == 0)
            {
                vec[++top] = pri[i];
                while (c % pri[i] == 0) c/= pri[i];
            }

        if (c > 1) vec[++top] = c;
        if (top == 0) printf("%lld\n", a - 1);
        else printf("%lld\n", dfs(a, b - a));
    }
    return 0;
}
/*
5
4 7
9 8
32 84
11 35
2 1
*/