#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
ll a[N], f[N][3], down[N], g[N], h[N];

void cmax(ll &x, ll y) {x = max(x, y);}
void dfs(int u, int fa)
{
	f[u][1] = down[u] = a[u];
	for (int v, i = head[u]; i; i = e[i].nxt)
	{
		v = e[i].v;
		if (v == fa) continue;
		dfs(v, u);
		
		cmax(f[u][2], f[v][2]);
		cmax(f[u][2], f[u][1] + f[v][1]);
		cmax(f[u][2], down[u] + g[v]);
		cmax(f[u][2], g[u] + down[v]);
		
		cmax(f[u][1], f[v][1]);
		cmax(f[u][1], down[u] + down[v]);
		
		cmax(g[u], a[u] + g[v]);
		cmax(g[u], down[u] + f[v][1]);
		cmax(g[u], down[v] + a[u] + h[u]);
		
		cmax(h[u], f[v][1]);
		
		cmax(down[u], down[v] + a[u]);
	}
	//cout<<u<<":" <<f[u][2] <<" "<<f[u][1]<<" "<<g[u]<<" "<<down[u]<<endl;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lld", a+i);
	for (int u, v, i = 1; i < n; i++)	
	{
		scanf("%d%d", &u, &v);
		add(u, v); add(v, u);
	}
	dfs(1, 0);
	printf("%lld\n", f[1][2]);
	return 0;
}
