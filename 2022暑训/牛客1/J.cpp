#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;

int etop, head[N];
struct Edge
{
    int v, nxt;
}e[N];
void add(int u, int v)
{
    e[++etop].v = v;
    e[etop].nxt = head[u];
    head[u] = etop;
}

int n, ru[N], chu[N], pre[N];

int vis[N], dfn, del[N], f[N], ans;
struct Data
{
    int u, w;
    Data () {}
    Data (int _u) {u = _u; w = chu[u];}
    bool operator <(const Data &t) const {return w > t.w;}
};
void work()
{
    priority_queue <Data> q;
    for (int i = 1; i <= n; i++)
        if (ru[i] == 1) q.push(Data(i));
    while (!q.empty())
    {
        int u = q.top().u; q.pop();
        if (ru[u] == 1)
        {
            int p = 0;
            for (int i = head[u]; i; i = e[i].nxt)
                if (e[i].v == u) p = 1;
            cout<<p<<", "<<u<<endl;
            if (p) continue;
        }

        ++dfn;
        for (int i = head[pre[u]]; i; i = e[i].nxt)
        {
            if (del[e[i].v]) continue;
            //cout<<"qianqu: "<<e[i].v<<endl;
            vis[e[i].v] = dfn;
        }

        for (int i = head[u]; i; i = e[i].nxt)
        {
            int v = e[i].v;
            if (del[v]) continue;
            if (vis[v] == dfn) //前后都有，那就入度-1
            {
                --ru[v];
                if (ru[v] == 1)
                {
                    q.push(Data(v));
                    pre[v] = pre[u];
                }
            }
            else add(pre[u], v);
        }
        f[pre[u]] += f[u];
        del[u] = 1;
    }
}
void init()
{
    etop = ans = 0;
    for (int i = 1; i <= n; i++)
    {
        f[i] = 1;
        pre[i] = 0;
        del[i] = head[i] = ru[i] = chu[i] = 0;
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; cs++)
    {
        scanf("%d", &n);
        init();
        for (int m, i = 1; i <= n; i++)
        {
            scanf("%d", ru+i);
            for (int u, j = 1; j <= ru[i]; j++)
            {
                scanf("%d", &u);
                ++chu[u];
                add(u, i);
                pre[i] = u; //如果ru[i] == 1，前驱固定
            }
        }
        work();
        for (int i = 1; i <= n; i++)
        {
            ans = max(ans, f[i]);
            cout<<del[i]<<" "<<f[i]<<endl;
        }
        printf("Case #%d: %d\n", cs, ans);
    }
    return 0;
}
/*
1

5
1 3
1 1
1 2
1 5
4 1 2 3 4
*/