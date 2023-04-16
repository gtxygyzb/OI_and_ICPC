#include <bits/stdc++.h>
using namespace std;
const int N = 5e6 + 50;

int pri[N], tot, vis[N], mi[N];
void init()
{
	for (int i = 2; i <= N - 50; i++)
	{
		if (!vis[i]) {pri[++tot] = i; mi[i] = i;}
		for (int j = 1; j <= tot && i * pri[j] <= N - 50; j++)
		{
			vis[i * pri[j]] = 1;
			mi[i * pri[j]] = pri[j];
			if (i % pri[j] == 0) break;
		}
	}
}
int n, m, a[N], b[N];

int divid(int x)
{
	if (b[x]) return b[x];
	int u = x;
	while (vis[u])
		u /= mi[u];
	return b[x] = u;
}

int main()
{
	init();
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		priority_queue <int> q;
		int zx = 1e9;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", a+i);
			q.push(a[i]);
			zx = min(zx, a[i]);
		}
		if (n == 1)
		{
			puts("0");
			continue;
		}
		int ans = q.top() - zx;
		while (1)
		{
			int u = q.top(); q.pop();
			if (!vis[u]) break;
			int x = divid(u);
			int y = u / x;
			//cout<<u<<" "<<x<<" "<<y<<endl;
			zx = min(zx, x);
			zx = min(zx, y);
			q.push(x);
			q.push(y);
			ans = min(ans, q.top() - zx);
		}
		printf("%d\n", ans);
	}
	return 0;
}
/*
1
5 10
2 4 2 4 2
*/
