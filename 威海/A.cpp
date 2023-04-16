// A
#include <bits/stdc++.h>
using namespace std;

constexpr int N = 5;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int n, m;
	cin >> n;
	set<string> s;
	for (int i = 0; i < n; ++i) {
		string name;
		for (int j = 0; j < N; ++j) {
			cin >> name;
			s.insert(name);
		}
	}
	vector<int> c(N), d(N);
	cin >> m;
	for (int p, i = 0; i < m; ++i) {
		string name;
		cin >> name >> p, --p;
		if (s.find(name) != s.end()) {
			++c[p];
		} else {
			++d[p];
		}
	}
//	for (int i = 0; i < N; ++i)
//		cout << c[i] << " \n"[i + 1 == N];
//	for (int i = 0; i < N; ++i)
//		cout << d[i] << " \n"[i + 1 == N];
	vector<int> p(N);
	iota(p.begin(), p.end(), 0);
	sort(p.begin(), p.end(), [&](int x, int y) {
		return c[x] + d[x] < c[y] + d[y];
	});
	int sc = 0, p0 = p[0];
	for (int i = 1; i < N; ++i)
		sc += c[p[i]];
	if (d[p0] <= sc) {
		cout << c[p0] + d[p0] << '\n';
	} else {
		cout << c[p0] + sc << '\n';
	}
	return 0;
}



