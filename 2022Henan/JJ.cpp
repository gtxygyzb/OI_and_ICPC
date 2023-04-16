#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
vector <int> e[N];
int n, a[N], siz[N]; 

int mid[N], cid[N], f[N], ans[N];

void dfs(int u)
{
	f[u] = a[u]; //包括根节点的子树最小值 
	siz[u] = 1;
	int mi[3] = {-1, -1, -1}; //不包括根节点的最大与次大编号 
	for (auto v : e[u])
	{
		dfs(v);
		siz[u] += siz[v];
		f[u] = min(f[u], f[v]);
		for (int i = 1; i <= 2; i++)
			if (mi[i] == -1) {mi[i] = v; break;}
			else
			{
				if (f[v] < f[mi[i]])
				{
					if (i == 1) mi[2] = mi[1];
					mi[i] = v;
					break ;
				}
			}
	}
	mid[u] = mi[1];
	cid[u] = mi[2];
}
void dp(int u, int pre)
{
	if (a[u] == 0) //没有任何数小于他，需要siz特判 
	{
		int cur = 0;
		for (auto v : e[u])
		{
			cur = max(cur, siz[v]);
		}
		cur = max(cur, n - siz[u]);
		ans[0] = cur;
	}
	int cnt = pre < a[u], id = pre < a[u] ? N : -1;
	for (auto v : e[u])
	{
		if (f[v] < a[u]) {++cnt; id = v;}
		int cur = a[u];
		if (v == mid[u])
		{
			if (cid[u] != -1) cur = min(cur, f[cid[u]]);
		}
		else cur = min(cur, f[mid[u]]);
		dp(v, min(pre, cur));
	}
	if (a[u] == 0) return ;
	//cout<<u<<":"<<cnt<<" "<<id<<endl;
	if (cnt >= 2) ans[a[u]] = 0;
	else
	{
		if (id == N) ans[a[u]] = n - siz[u];
		else ans[a[u]] = siz[id];
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	for (int fa, i = 2; i <= n; i++)
	{
		scanf("%d", &fa);
		e[fa].push_back(i);
	}
	dfs(1);
	dp(1, N);
	for (int i = 0; i < n; i++)
		printf("%d ", ans[i]);
	printf("%d\n", n);
	return 0;
}

