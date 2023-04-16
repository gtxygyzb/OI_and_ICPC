// J
#include <bits/stdc++.h>
using namespace std;

using LL = long long;
constexpr int INF = 1e9 + 7;

struct A {
	int x, y;
	bool operator < (const A& rhs) const {
		return x < rhs.x;
	}
};

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int ti;
	cin >> ti;
	while (ti--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n), b(n), pos;
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		vector<A> lim;
		for (int x, y, i = 0; i < k; ++i) {
			cin >> x >> y;
			if (y == 0)
				pos.push_back(x);
			else
				lim.push_back({x, y});
		}
		pos.push_back(-1);
		pos.push_back(INF);
		sort(a.begin(), a.end());
		sort(pos.begin(), pos.end());
		sort(lim.begin(), lim.end());
		int m = pos.size(), t = lim.size();
		for (int ll = 0, i = 0; i + 1 < m; ++i) {
			auto itel = upper_bound(a.begin(), a.end(), pos[i]);
			if (itel == a.end())
				break;
			auto iter = --lower_bound(a.begin(), a.end(), pos[i + 1]);
			int al = itel - a.begin(), ar = iter - a.begin();
//			cout << "# " << al << ' ' << ar << endl;
			int x = pos[i];
			while (ll < t && lim[ll].x < x)
				++ll;
			if (ll < t && lim[ll].x == x + 1) {
				vector<int> lens;
				int lr = ll;
				lens.push_back(lim[ll].y);
				while (lr + 1 < t && lim[lr + 1].x == lim[lr].x + 1) {
					lens.push_back(lim[lr + 1].y);
					++lr;
				}
				ll = lr + 1;
				int p = al, d = 1;
//				cout << "! " << p << ": ";
//				for (auto len: lens) cout << len << ' ';
//				cout << endl;
				for (auto len: lens) {
					for (int l = p; l <= p + len - 1 && l <= ar; ++l)
						b[l] = x + d;
					++d;
					p += len;
				}
				for (int l = p; l <= ar; ++l)
					b[l] = x + d;
			} else {
				for (int l = al; l <= ar; ++l)
					b[l] = x + 1;
			}
		}
//		for (int i = 0; i < n; ++i) cout << b[i] << ' ';
//		cout << endl;
		
		LL s = 0;
		for (int i = 0; i < n; ++i)
			s += a[i] - b[i];
		cout << ((s & 1)? "Pico": "FuuFuu") << '\n';
	}
	return 0;
}
/*
1
5 2
7 2 3 10 9
4 0
5 0

1
3 2
2 3 3
1 2
0 1

*/
