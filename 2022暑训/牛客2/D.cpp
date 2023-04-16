#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 50;
const double eps = 1e-8;

int etop, head[N];
struct Edge
{
    int v, nxt;
    double w;
}e[N + N];
void add(int u, int v, double w)
{
    e[++etop].v = v;
    e[etop].w = w;
    e[etop].nxt = head[u];
    head[u] = etop;
}

int n, m, vis[N], cnt[N], done[N];
long double dis[N];

int spfa(int st, double w)
{
    queue <int> q;
    dis[st] = 1; cnt[st] = vis[st] = 1;
    q.push(st);
	while (!q.empty())
	{
		int u = q.front(); q.pop();
        vis[u] = 0;
        done[u] = 1;
        for (int i = head[u]; i; i = e[i].nxt)
        {
            int v = e[i].v;
            if (dis[u] * e[i].w * w > dis[v])
            {
                dis[v] = dis[u] * e[i].w * w;
                cnt[v] = cnt[u] + 1;
                //cout<<v<<" "<<dis[v]<<" "<<cnt[v]<<endl;
                if (cnt[v] > n) return 0;
                if (!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
	}
    return 1;
}
int check(double w)
{
    memset(dis, 0, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    memset(done, 0, sizeof(done));
    for (int i = 1; i <= n; i++)
        if (done[i] == 0)
            if (spfa(i, w)  == 0)
                return 0;
    return 1;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        double a, c; int b, d;
        scanf("%lf%d%lf%d", &a, &b, &c, &d);
        add(b, d, c / a);
    }
    
    double l = 0, r = 1;
    while (r - l > eps)
    {
        double mid = (l + r) / 2;
        //cout<<"ck: "<<mid<<" "<<check(mid)<<endl;
        if (check(mid)) l = mid;
        else r = mid;
    }
    printf("%.8lf\n", l);
    return 0;
}
/*
3 6
1 1 3 2
1 2 3 1
1 3 4 1
1 1 1 3
2 2 4 3
1 3 3 2
*/