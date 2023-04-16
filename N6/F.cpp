#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 50;

int n, m;

struct Steak
{
    int id, t;
    void input(int _id)
    {
        id = _id;
        scanf("%d", &t);
    }
    bool operator <(const Steak &tmp) const
    {
        return t > tmp.t;
    }
}s[N];
struct Data
{
    int id;
    ll l, r;
    Data (int _id, ll _l, ll _r)
    {
        id = _id; l = _l; r = _r;
    }
    void output(int cnt, int u)
    {
        printf("%d %lld %lld", id, l, r);
        printf(u == cnt ? "\n": " ");
    }
};

vector <Data> ans[N];

int c[N], siz[N];

ll a[N];
bool check(ll lim)
{
    if (lim == 0) return 0;
    int top = 1;
    a[top] = 0;
    for (int i = 1; i <= n; i++)
    {
        c[i] = s[i].t;
        siz[s[i].id] = 0;
        ans[s[i].id].clear();
    }
    for (int i = 1; i <= n; i++)
        while (c[i] >= lim)
        {
            ++siz[s[i].id];
            c[i] -= lim;
            ans[s[i].id].push_back(Data(top, 0, lim) );
            ++top;
            if (siz[s[i].id] > 2) return 0;
        }
    for (int i = 1; i <= n; i++)
    {
        while (c[i])
        {
            ++siz[s[i].id];
            ll del = min(1LL * c[i], lim - a[top]);
            c[i] -= del;
            ans[s[i].id].push_back( Data(top, a[top], a[top] + del) );
            a[top] += del;
            if (a[top] == lim)
                a[++top] = 0;
        }
        if (siz[s[i].id] > 2)
            return 0;
    }
    if (a[top] == 0) --top;
    return top <= m;
}
int main()
{
    ll sum = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        s[i].input(i);
        sum += s[i].t;
    }
    sort(s + 1, s + n + 1);
    ll l = 0, r = 1e18;
    while (l < r)
    {
        ll mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    check(l);
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", siz[i]);
        if (siz[i] > 1)
            if (ans[i][0].l > ans[i][1].l)
                swap(ans[i][0], ans[i][1]);
        for (int j = 0; j < siz[i]; j++)
            ans[i][j].output(siz[i], j+1);
    }
    return 0;
}