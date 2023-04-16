#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 50;

int head[N], etop;
struct Edge
{
    int v, nxt;
}e[N];
void add(int u, int v, int *d)
{
    e[++etop] = {v, head[u]};
    head[u] = etop;
    ++d[v];
}
struct Data
{
    int l, r, id;
    bool operator <(const Data &t) const {return r > t.r;}
}b[N];

int n, m, shun[N], ni[N], a[N], ans[N];

int dag(int d[], int op)
{
    queue <int> q;
    for (int i = 1; i <= n; i++)
        if (d[i] == 0) q.push(i);
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        for (int v, i = head[u]; i; i = e[i].nxt)
        {
            if ((i & 1) != op) continue;
            v = e[i].v;
            if (op)
                b[v].l = max(b[v].l, b[u].l + 1);
            else
                b[v].r = min(b[v].r, b[u].r - 1);
            --d[v];
            if (!d[v]) q.push(v);
        }
    }
    for (int i = 1; i <= n; i++)
        if (d[i]) return 0;
    return 1;
}

vector <Data> vec[N];
void init()
{
    for (int i = 1; i <= n; i++)
    {
        head[i] = shun[i] = ni[i] = 0;
        vec[i].clear();
    }
    etop = 0;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        init();
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", a+i);
            if (a[i]) b[i] = Data{a[i], a[i], i};
            else b[i] = Data{1, n, i};
        }
        for (int u, v, i = 1; i <= m; i++)
        {
            scanf("%d%d", &u, &v);
            add(u, v, shun);
            add(v, u, ni);
        }
        int flag = 1;
        flag &= dag(shun, 1);
        flag &= dag(ni, 0);
        for (int i = 1; i <= n && flag; i++)
            if (b[i].l > b[i].r) flag = 0;
        
        if (!flag) {puts("-1"); continue;}
        for (int i = 1; i <= n; i++)
            vec[b[i].l].push_back(b[i]);
        
        priority_queue <Data> q;
        for (int x = 1; x <= n && flag; x++)
        {
            for (int i = 0; i < vec[x].size(); i++)
                q.push(vec[x][i]);
            if (q.empty()) {flag = 0; break;}
            Data u = q.top(); q.pop();
            if (u.r < x) flag = 0;
            else ans[u.id] = x;
        }
        if (flag)
            for (int i = 1; i <= n; i++)
                printf("%d%c", ans[i], i == n ? '\n' : ' ');
        else puts("-1");
    }
    return 0;
}
/*
1
6 4
0 2 0 4 0 0
2 3
3 4
1 5
5 6
*/