// A
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int ti;
	cin >> ti;
	while (ti--) {
		int n;
		cin >> n;
		vector<vector<int>> G(n + 1);
		vector<int> size(n + 1), l(n + 1), r(n + 1);
		for (int u, v, i = 1; i < n; ++i) {
			cin >> u >> v;
			G[u].push_back(v), G[v].push_back(u);
		}
		function<void(int, int)> dfs0 = [&](int u, int fa) {
			size[u] = 1;
			for (auto v: G[u]) if (v != fa) {
				dfs0(v, u);
				size[u] += size[v];
			}
		};
		dfs0(1, 0);
		function<void(int, int)> dfs1 = [&](int u, int fa) {
			for (auto v: G[u]) if (v != fa) {
				l[v] = l[u] + 1;
				r[v] = r[u] + size[u] - size[v];
				dfs1(v, u);
			}
		};
		l[1] = r[1] = 1;
		dfs1(1, 0);
		for (int i = 1; i <= n; ++i)
			cout << l[i] << ' ' << r[i] << '\n'; 
	} 
	return 0;
}

