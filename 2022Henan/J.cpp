#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

vector <int> e[N];
int a[N], in[N], out[N], tim, siz[N], dfm[N];
void dfs(int u)
{
	in[u] = ++tim; dfm[tim] = u;
	siz[u] = 1;
	for (int v, i = 0; i < e[u].size(); i++)
	{
		v = e[u][i];
		dfs(v);
		siz[u] += siz[v];
	}
	out[u] = tim;
}

int top;
struct Tree
{
	int l, r, val;
}t[N * 18];
void modify(int &u, int pre, int l, int r, int pos)
{
	t[u = ++top] = t[pre]; ++t[u].val;
	if (l == r) return ;
	int mid = l + r >> 1;
	if (pos <= mid) modify(t[u].l, t[pre].l, l, mid, pos);
	else modify(t[u].r, t[pre].r, mid + 1, r, pos);
}
int query(int u, int pre, int st, int ed, int l, int r)
{
	if (st > ed) return 0;
	if (st <= l && r <= ed) return t[u].val - t[pre].val;
	int mid = l + r >> 1, ret = 0;
	if (st <= mid) ret += query(t[u].l, t[pre].l, st, ed, l, mid);
	if (ed > mid) ret += query(t[u].r, t[pre].r, st, ed, mid + 1, r);
	return ret;
}

int pos[N], n, rt[N];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		pos[a[i]] = i;
	}
	for (int fa, i = 2; i <= n; i++)
	{
		scanf("%d", &fa);
		e[fa].push_back(i);
	}
	dfs(1);
	for (int i = 1; i <= n; i++)
		modify(rt[i], rt[i - 1], 0, n - 1, a[dfm[i]]);
	for (int x = 0; x < n; x++)
	{
		int u = pos[x], ans = 0;
		for (int v, i = 0; i < e[u].size(); i++)
		{
			v = e[u][i];
			int cnt = query(rt[out[v]], rt[in[v] - 1], 0, x - 1, 0, n - 1);
			if (cnt == x)
			{
				ans = siz[v];
				break;
			}
		}
		int cnt = query(rt[out[u]], rt[in[u] - 1], 0, x - 1, 0, n - 1);
		if (cnt == 0) ans = max(ans, n - siz[u]);
		
		printf("%d ", ans);
	}
	printf("%d\n", n);
	return 0;
}
/*
5
3 2 1 0 4
1 1 2 4
*/
