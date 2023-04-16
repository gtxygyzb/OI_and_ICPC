#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 50;
const ll inf = 1e18;
struct Data
{
    int x, val, id, p;
    bool operator <(const Data &t) const {return x == t.x ? p < t.p : x < t.x;}
}a[N];
pair <ll, ll> d[N];
int n, top, ans[N], id[N];
ll m, t[N];
ll pre[N], suf[N];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%lld", &n, &m);
        top = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld%lld", &d[i].first, &d[i].second);
            //scanf("%lld%lld", &x[i], &p[i]);
            ll x = d[i].first, p = d[i].second;
            a[++top] = Data{x - p, 1, 0, 0};
            a[++top] = Data{x, -2, i, p};
            a[++top] = Data{x + p, 1, 0, 0};
        }
        sort(d + 1, d + n + 1);
        sort(a + 1, a + top + 1);
        ll cur = 0, cnt = 0;
        int tot = 0;
        for (int i = 1; i <= top; i++)
        {
            if (i == 1) {cnt += a[i].val; continue;}
            if (a[i].x != a[i - 1].x)
            {
                cur += (a[i].x - a[i - 1].x) * cnt;
            }
            cnt += a[i].val;
            if (a[i].val == -2) {t[++tot] = cur - m; id[tot] = a[i].id;}
        }
        pre[0] = -inf; suf[n + 1] = -inf;
        for (int i = 1; i <= n; i++)
        {
            //cout<<t[i]<<" ";
            if (t[i] <= 0) pre[i] = pre[i - 1];
            else pre[i] = max(pre[i - 1], t[i] - d[i].first);
        }
        //puts("");
        for (int i = n; i; i--)
            if (t[i] <= 0) suf[i] = suf[i + 1];
            else suf[i] = max(suf[i + 1], t[i] + d[i].first);
        for (int i = 1; i <= n; i++)
        {
            //cout<<" fds: "<<pre[i]<<" "<<suf[i]<<endl;
            //cout<<id[i]<<" ";
            ans[id[i]] = (d[i].second - d[i].first >= pre[i] && d[i].second + d[i].first >= suf[i]);
        }
        //puts("");
        for (int i = 1; i <= n; i++)
            printf("%d", ans[i]);
        putchar('\n');
    }
    return 0;
}
/*
1
3 59
89 55
42 22
2 96
*/