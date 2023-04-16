// L
#include <bits/stdc++.h>
using namespace std;

int lowbit(int x) {
	return x & -x;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr) ;
	int ti;
	cin >> ti;
	while (ti--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		vector<vector<int>> G(n + 1);
		vector<int> pre(n + 1);
		for (int u = 1; u <= n; ++u) {
			int fa = u + lowbit(u);
			if (fa <= n)
				G[fa].push_back(u), pre[u] = fa;
		}
		int ans = 0;
		function<void(int)> dfs = [&](int u)  {
			int c = 0;
			for (auto v: G[u]) {
				dfs(v);
				if (s[v - 1] == '1')
					++c;
			}
			if (s[u - 1] == '1') {
				if (c == 0) ++ans;
			} else {
				if (c == 1) ++ans;
			}
		};
		for (int u = 1; u <= n; ++u)
			if (pre[u] == 0) dfs(u);
		cout << ans << '\n';
	}
	return 0;
}

