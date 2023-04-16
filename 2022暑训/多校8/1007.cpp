#include<iostream>
#include<cstdio>
#include<set>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<bitset>
#include<stack>
#include<queue>
#include<cmath>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e6 + 10;
const int mod = 1e9 + 7;

int n;
ll a[MAXN], fa[MAXN], pos[MAXN];

int find(int x)
{
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

bool unite(int x, int y)
{
    x = find(x); y = find(y);
    if (x == y) return 0;
    fa[x] = y;
    return 1;
}

struct edge
{
    int u, v; ll c;
    edge(int u=0,int v=0,ll c=0):u(u),v(v),c(c){}
    bool operator < (const edge& y) const
    {
        return c < y.c;
    }
};



void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", a + i);
        pos[a[i]] = i;
        fa[i] = i;
    }
    vector<edge> v;
    int up = sqrt(n);
    up = min(up, 125);
    for (int i = 1; i <= up; i++)
    {
        for (int j = 1; j + i <= n; j++)
        {
            if (abs(a[j] - a[j + i]) * i < n)
            {
                v.push_back(edge(j, j + i, abs(a[j] - a[j + i]) * i));
            }
            if (abs(pos[j] - pos[j + i]) * i < n)
            {
                v.push_back(edge(pos[j], pos[j + i], abs(pos[j] - pos[j + i]) * i));
            }
        }
    }
    sort(v.begin(), v.end());
    ll ans = 0, cnt = 0;
    for (edge& e : v)
    {
        if (cnt == n - 1) break;
        if (unite(e.u, e.v))
        {
            ans += e.c;
            cnt++;
        }
    }
    printf("%lld\n", ans);
}


int main()
{
    int T = 1;
    scanf("%d", &T);
    while (T--)
    {
        solve();
    }
    return 0;
}
