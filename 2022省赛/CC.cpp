// C 
#include <bits/stdc++.h>
using namespace std;

struct Edge {
	int u, v, w;
	bool operator < (const Edge& rhs) const {
		return w < rhs.w;
	}
};

int LCS(const string& s, const string& t) {
	int n = s.size(), m = t.size();
	vector<vector<int>> f(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			f[i][j] = max(f[i - 1][j], f[i][j - 1]);
			if (s[i - 1] == t[j - 1])
				f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
		}
	}
//	cout << s << ' ' << t << ' ' << f[n][m] << endl;
	return f[n][m];
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	vector<int> l(n + 1);
	vector<string> s(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> l[i] >> s[i];
	vector<Edge> edges;
	int t = n + 1;
	for (int i = 1; i <= n; ++i) {
		edges.push_back({i, t, l[i]});
		for (int j = 1; j < i; ++j) {
			int m = LCS(s[i], s[j]), w = l[i] - m + l[j] - m + k;
			edges.push_back({i, j, w});
		}
	}
	vector<int> fa(n + 2);
	for (int i = 1; i <= n + 1; ++i)
		fa[i] = i;
	function<int(int)> fnd = [&](int u) {
		return (fa[u] == u)? u: fa[u] = fnd(fa[u]);
	};
	int ans = 0, cnt = 0;
	sort(edges.begin(), edges.end());
	for (auto e: edges) {
		int fu = fnd(e.u), fv = fnd(e.v);
		if (fu != fv) {
			ans += e.w;
			fa[fv] = fa[e.v] = fu;
			if (++cnt == n + 1 - 1)
				break;
		}
	}
	cout << ans << '\n';
	return 0;
}







