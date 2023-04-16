// F
#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 2e5 + 5, LOG = 20;

int pre[MAXN][LOG], f[MAXN][LOG];

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n + 1), d(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		cin >> d[i];
	vector<vector<int>> G(n + 1);
	vector<int> rts; 
	for (int i = 1; i <= n; ++i) {
		auto ite = lower_bound(a.begin() + 1, a.end(), a[i] + k + 1);
		if (ite != a.end()) {
			int j = ite - a.begin();
			G[j].push_back(i);
		} else {
			rts.push_back(i);
		}
	}
	vector<int> val(n + 1);
	function<void(int, int)> dfs = [&](int u, int fa) {
		val[u] = val[fa] + d[u];
		pre[u][0] = fa;
		f[u][0] = val[fa];
		for (int j = 1; j < LOG; ++j) {
			pre[u][j] = pre[pre[u][j - 1]][j - 1];
			f[u][j] = min(f[u][j - 1], f[pre[u][j - 1]][j - 1]);
		}
//		cout << u << ' ' << fa << ' ' << val[u] << endl;
		for (auto v: G[u]) {
			dfs(v, u);
		}
	};
	for (auto rt: rts) {
		dfs(rt, 0);
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int cur = INT_MAX;
		int u = i;
		for (int j = LOG - 1; j >= 0; --j) {
			if ((m & (1 << j)) == 0) continue; 
			cur = min(cur, f[u][j]);
			u = pre[u][j];
			if (u == 0)
				break;
		}
		ans = max(ans, val[i] - cur);
	}
	cout << ans << '\n';
	return 0;
}










