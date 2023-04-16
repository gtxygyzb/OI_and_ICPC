#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 50;

struct Ans
{
    int id;
    ll l, r;
    Ans (int _id, ll _l, ll _r)
    {
        id = _id; l = _l; r = _r;
    }
    void output(int cnt, int u)
    {
        printf("%d %lld %lld", id, l, r);
        printf(u == cnt ? "\n": " ");
    }
};
vector <Ans> ans[N];

struct Data
{
    ll val, l;
    int id, rev;
    Data () {}
    Data(int _id, ll _val, int _rev, ll _l) {id = _id; val = _val; rev = _rev; l = _l;}
    void input(int _id)
    {
        scanf("%lld", &val);
        id = _id;
        rev = 0;
        l = 0;
    }
    bool operator <(const Data &t) const
    {
        return val == t.val ? id > t.id : val < t.val;
    } 
}a[N];

int n, m, siz[N];
priority_queue <Data> s, p;
bool check(ll lim)
{
    while (!s.empty()) s.pop();
    while (!p.empty()) p.pop();
    memset(siz, 0 ,sizeof(int) * (n+5));
    for (int i = 1; i <= n; i++)
    {
        if (a[i].val > (lim*2)) return 0;
        s.push(a[i]);
    }
    for (int i = 1; i <= m; i++)
        p.push(Data(i, lim, 0, lim));
    while (!s.empty())
    {
        if (p.empty()) return 0;
        Data u = s.top(); s.pop();
        Data pt = p.top(); p.pop();
        if (u.val >= pt.val)
        {
            u.val -= pt.val;
            ++siz[u.id];
                ans[u.id].push_back(Ans(pt.id, lim - pt.val, lim));
            if (u.val)
            {
                u.rev ^= 1;
                s.push(u);
            }
        }
        else
        {
            ++siz[u.id];
                if (u.rev == 0)
                    ans[u.id].push_back(Ans(pt.id, lim - pt.val, lim - (pt.val - u.val)));
                else
                {
                    ans[u.id].push_back(Ans(pt.id, pt.l - u.val, pt.l));
                    pt.l -= u.val;
                }
            pt.val -= u.val;
            if (pt.val) p.push(pt);
        }
        if (siz[u.id] > 2) return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        if (siz[i] > 1)
        {
            if (ans[i][0].l > ans[i][1].l)
                swap(ans[i][0], ans[i][1]);
            if (ans[i][0].r > ans[i][1].l)
                return 0;
        }
    }
    return 1;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        a[i].input(i);
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