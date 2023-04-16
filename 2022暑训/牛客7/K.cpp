#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 2e6 + 50;

int n, m, a[N], b[N], c[N][2], s[N];
ll ans[N], cnt;
struct Query
{
    int id, l, r;

    void init(int _id)
    {
        scanf("%d%d", &l, &r);
        id = _id; ++r;
    }

    bool operator <(Query const &t) const
    {
        return b[l] == b[t.l] ? (b[l] & 1 ? r < t.r : r > t.r) : b[l] < b[t.l];
    }
}q[N];

int l = 1, r = 0, siz;
void add(int p, int x)
{
    cnt += c[x][p&1]; ++c[x][p&1];
}
void del(int p, int x)
{
    //cout<<p<<" "<<x<<endl;
    --c[x][p&1]; cnt -= c[x][p&1];
}
int main()
{
    scanf("%d%d", &n, &m);
    siz = sqrt(n + 1);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a+i);
        a[i] = a[i - 1] ^ (a[i] - 1);
    }
    for (int i = 1; i <= n + 1; i++)
        b[i] = (i-1) / siz + 1;

    for (int i = n + 1; i >= 2; i--)
        a[i] = a[i - 1];
    a[1] = 0;
    /*for (int i = 1; i <= n + 1; i++)
        cout<<a[i]<<" ";
    puts("");*/
    for (int i = 1; i <= m; i++)
        q[i].init(i);
    sort(q + 1, q + m + 1);
    for (int i = 1; i <= m; i++)
    {
        int len = q[i].r - q[i].l;
        while (l < q[i].l) {del(l, a[l]); l++;}
        while (r < q[i].r) {++r, add(r, a[r]);}
        while (l > q[i].l) {--l, add(l, a[l]);}
        while (r > q[i].r) {del(r, a[r]); r--;}
        ans[q[i].id] = 1ll * len * (len + 1) / 2 - cnt;
    }
    for (int i = 1; i <= m; i++)
        printf("%lld\n", ans[i]);
}
/*
3 1
1 2 3
1 3
*/