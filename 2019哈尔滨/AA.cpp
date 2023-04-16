#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 50, M = 1e6 + 50, inf = 0x3f3f3f3f;

int head[N], etop;
struct Edge
{
	int v, w, nxt;
}e[M];
void add(int u, int v, int w)
{
	e[++etop] = Edge{v, w, head[u]};
	head[u] = etop;
}

int n, m1, m2, dis[N], vis[N], cnt[N];
void init()
{
	for (int i = 0; i <= n + 5; i++)
		head[i] = 0;
	etop = 0;
}

int st[N], ed[N], wk[N], clr, ph[N];
int check(int c)
{
	etop = clr;
	for (int i = 0; i <= n + 1; i++)
	{
		head[i] = ph[i];
		cnt[i] = vis[i] = 0;
		dis[i] = -inf;
	}
		
	for (int i = 1; i <= m2; i++)
		add(ed[i], st[i] - 1, wk[i] - c);
	add(0, n, c);
	add(n, 0, -c);
	queue <int> q;
	q.push(n + 1);
	vis[n + 1] = cnt[n + 1] = 1;
	dis[n + 1] = 0;
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		vis[u] = 0;
		for (int i = head[u]; i; i = e[i].nxt)
		{
			int v = e[i].v, w = e[i].w;
			if (dis[u] + w > dis[v])
			{
				dis[v] = dis[u] + w;
				cnt[v] = cnt[u] + 1;
				if (cnt[v] > n + 2) return 0;
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
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d", &n, &m1, &m2);
		init();
		for (int i = 1; i <= n; i++)
		{
			add(i - 1, i, 0);
			add(i, i - 1, -1);
		}
		for (int i = 0; i <= n; i++) //共n + 2个点 
			add(n + 1, i, 0);
		for (int l, r, k; m1--;)
		{
			scanf("%d%d%d", &l, &r, &k);
			add(l - 1, r, k);
		}
		
		clr = etop; //加边前的现场 
		for (int i = 0; i <= n + 1; i++)
			ph[i] = head[i];
		
		for (int i = 1; i <= m2; i++)
			scanf("%d%d%d", st+i, ed+i, wk+i);
		int l = 0, r = n, ans = -1;
		while (l <= r)
		{
			int mid = l + r >> 1;
			if (check(mid)) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}
