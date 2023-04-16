#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;

int head[N], etop;
struct Edge
{
	int v, w, nxt;
}e[N];
void add(int u, int v, int w)
{
	e[++etop] = Edge{v, w, head[u]};
	head[u] = etop;
}

int dis[N], cnt[N], vis[N];
int spfa(int S, int n)
{
	memset(dis, 0x3f, sizeof(dis));
	dis[S] = 0;
	queue <int> q;
	q.push(S);
	cnt[S] = vis[S] = 1;
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		vis[u] = 0;
		for (int i = head[u]; i; i = e[i].nxt)
		{
			int v = e[i].v, w = e[i].w;
			if (dis[u] + w < dis[v])
			{
				dis[v] = dis[u] + w;
				cnt[v] = cnt[u] + 1;
				if (cnt[v] > n + 1) return 0;
				if (!vis[v])
				{
					q.push(v);
					vis[v] = 1;
				}
			}
		}
	}
	return 1;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int u, v, w; m--;)
	{
		scanf("%d%d%d", &v, &u, &w);
		add(u, v, w);
	}
	for (int i = 1; i <= n; i++)
		add(0, i, 0);
	if (spfa(0, n))
	{
		for (int i = 1; i <= n; i++)
			printf("%d ", dis[i]);
	}
	else puts("NO");
	return 0;
}
