#include <bits/stdc++.h>

using namespace std;
const int N = 4e6 + 50, V = 1e6;

int n, m, a[N], b[N], ans[N];
struct Query
{
    int l, r, id;
    void input(int _id)
    {
        scanf("%d%d", &l, &r);
        id = _id;
    }
}q[N];

int vis[N], pri[N], mi[N], tot;
void init()
{
    for (int i = 2; i <= V; i++)
    {
        if (!vis[i]) {pri[++tot] = i; mi[i] = i;}
        for (int j = 1; j <= tot && i * pri[j] <= V; j++)
        {
            vis[i * pri[j]] = 1;
            mi[i * pri[j]] = pri[j];
            if (i % pri[j] == 0) break;
        }
    }
}

vector <int> vec[N];
void did(int i, int x)
{
    int u = x;
    if (vec[u].size()) return ;
    while (x > 1)
    {
        int di = mi[x];
        while (di == mi[x])
            x /= mi[x];
        vec[u].push_back(di);
    }
}

int mx, cnt[N], num[N];
void add(int x)
{
    for (int i = 0; i < vec[x].size(); i++)
    {
        int v = vec[x][i];
        ++cnt[v]; ++num[cnt[v]];
        if (num[cnt[v]] == 1) ++mx;
    }
}
void del(int x)
{
    for (int i = 0; i < vec[x].size(); i++)
    {
        int v = vec[x][i];
        --num[cnt[v]];
        if (num[cnt[v]] == 0) --mx;
        --cnt[v]; 
    }
}

bool cmp(Query q1, Query q2)
{
    if (b[q1.l] != b[q2.l])
    {
        return b[q1.l] < b[q2.l];
    }
    return q1.r == q2.r ? 0 : ((b[q1.l] & 1) ^ (q1.r < q2.r));
}
int main()
{
    int T;
    scanf("%d", &T);
    init();
    while (T--)
    {
        scanf("%d%d", &n, &m);
        int l = 1, r = 0, sqr = sqrt(n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            b[i] = (i - 1) / sqr + 1;
            did(i, a[i]);
        }
        for (int i = 1; i <= m; i++)
            q[i].input(i);
        sort(q + 1, q + m + 1, cmp);
        for (int i = 1; i <= m; i++)
        {
            while (r < q[i].r) add(a[++r]);
            while (l > q[i].l) add(a[--l]);
            while (r > q[i].r) del(a[r--]);
            while (l < q[i].l) del(a[l++]);
            ans[q[i].id] = mx;
        }
        for (int i = 1; i <= m; i++)
            printf("%d\n", ans[i]);
        while (l <= r) del(a[l++]);
    }
    return 0;
}