// A
#include <bits/stdc++.h>
using namespace std;

using pdd = pair<double, double>;

struct I {
	int l, r;
	bool operator < (const I& rhs) const {
		return l < rhs.l || (l == rhs.l && r < rhs.r);
	}
	bool operator == (const I& rhs) const {
		return l == rhs.l && r == rhs.r;
	}
};

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<I> ia, ib;
	vector<int> pa, pb;
	double A = 0, B = 0;
	for (int l, r, i = 0; i < n; ++i) {
		cin >> l >> r;
		if (l == r)
			pa.push_back(l);
		else {
			ia.push_back({l, r});
			A += r - l;
		}
	}
	for (int l, r, i = 0; i < m; ++i) {
		cin >> l >> r;
		if (l == r) {
			pb.push_back(l);
		} else {
			ib.push_back({l, r});
			B += r - l;
		}
	}
	if (ia.size() > 0 && ib.size() > 0) {
		sort(ia.begin(), ia.end());
		sort(ib.begin(), ib.end());
		vector<int> pos;
		for (int i = 0; i < (int) ia.size(); ++i) {
			pos.push_back(ia[i].l);
			pos.push_back(ia[i].r);
		}
		for (int j = 0; j < (int) ib.size(); ++j) {
			pos.push_back(ib[j].l);
			pos.push_back(ib[j].r);
		}
		sort(pos.begin(), pos.end());
		pos.erase(unique(pos.begin(), pos.end()), pos.end());
		vector<I> a, b;
		for (int p = 0, i = 0; i < (int) ia.size(); ++i) {
			int u = ia[i].l, v = ia[i].r;
			while (p < (int) pos.size() && pos[p] <= u)
				++p;
			while (p < (int) pos.size() && pos[p] <= v) {
				a.push_back({u, pos[p]});
				u = pos[p], ++p;
			}
		}
		for (int p = 0, i = 0; i < (int) ib.size(); ++i) {
			int u = ib[i].l, v = ib[i].r;
			while (p < (int) pos.size() && pos[p] <= u)
				++p;
			while (p < (int) pos.size() && pos[p] <= v) {
				b.push_back({u, pos[p]});
				u = pos[p], ++p;
			}
		}
		int s = a.size(), t = b.size();
		if (false) {
			cout << "! " << s << endl;
			for (int i = 0; i < s; ++i)
				cout << a[i].l << ' ' << a[i].r << '\n';
			cout << "! " << t << endl;
			for (int j = 0; j < t; ++j)
				cout << b[j].l << ' ' << b[j].r << '\n';
			cout << endl;
		}
		vector<pdd> pre(t), suf(t);
		for (int i = 0; i < t; ++i) {
			double l = b[i].l, r = b[i].r;
			pre[i] = suf[i] = {r * r - l * l, r - l};
		}
		for (int i = 1; i < t; ++i) {
			pre[i].first += pre[i - 1].first;
			pre[i].second += pre[i - 1].second;
		}
		for (int i = t - 2; i >= 0; --i) {
			suf[i].first += suf[i + 1].first;
			suf[i].second += suf[i + 1].second;
		}
		double ans = 0;
		for (int i = 0; i < s; ++i) {
			double l = a[i].l, r = a[i].r;
			int p0 = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
			int p1 = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
//			cout << "#" << p0 << ' ' << p1 << endl;
//			cout << a[i].l << ' ' << a[i].r << endl;
			if (b[p0] == a[i])
				ans += (r - l) / 3 * (r - l) * (r - l);
			if (p1 < t) {
				ans += (suf[p1].first * (r - l) / 2);
				ans -= (suf[p1].second * (r * r - l * l) / 2);
			}
			if (p0 > 0) {
				ans -= (pre[p0 - 1].first * (r - l) / 2);
				ans += (pre[p0 - 1].second * (r * r - l * l) / 2);
			}
//			cout << ans << endl;
		}
		cout << fixed << setprecision(10) << ans / A / B << '\n'; 
	} else if (ia.size() > 0 || ib.size() > 0) {
		if (ib.size() > 0) {
			swap(pa, pb);
			swap(ia, ib);
		}
		sort(ia.begin(), ia.end());
		sort(pb.begin(), pb.end()); 
		vector<int> pos = pb;
		for (int i = 0; i < (int) ia.size(); ++i) {
			pos.push_back(ia[i].l);
			pos.push_back(ia[i].r);
		}
		sort(pos.begin(), pos.end());
		pos.erase(unique(pos.begin(), pos.end()), pos.end());
		vector<I> a;
		auto& b = pb;
		for (int p = 0, i = 0; i < (int) ia.size(); ++i) {
			int u = ia[i].l, v = ia[i].r;
			while (p < (int) pos.size() && pos[p] <= u)
				++p;
			while (p < (int) pos.size() && pos[p] <= v) {
				a.push_back({u, pos[p]});
				u = pos[p], ++p;
			}
		}
		int s = a.size(), t = b.size();
		if (false) {
			cout << "! " << s << endl;
			for (int i = 0; i < s; ++i)
				cout << a[i].l << ' ' << a[i].r << endl;
			cout << "! " << t << endl;
			for (int i = 0; i < t; ++i)
				cout << b[i] << endl;
		}
		vector<pdd> pre(t), suf(t);
		for (int i = 0; i < t; ++i) {
			int p = b[i];
			pre[i] = suf[i] = {p, 1};
		}
		for (int i = 1; i < t; ++i) {
			pre[i].first += pre[i - 1].first;
			pre[i].second += pre[i - 1].second;
		}
		for (int i = t - 2; i >= 0; --i) {
			suf[i].first += suf[i + 1].first;
			suf[i].second += suf[i + 1].second;
		}
		double ans = 0;
		for (int i = 0; i < s; ++i) {
			double l = a[i].l, r = a[i].r;
			int p0 = lower_bound(b.begin(), b.end(), a[i].l) - b.begin();
			int p1 = upper_bound(b.begin(), b.end(), a[i].r) - b.begin();
//			cout << "#" << p0 << ' ' << p1 << endl;
//			cout << a[i].l << ' ' << a[i].r << endl;
			if (p1 < t) {
				ans += (suf[p1].first * (r - l));
				ans -= (suf[p1].second * (r * r - l * l) / 2);
			}
			if (p0 >= 0) {
				ans += (pre[p0].first * (r - l));
				ans -= (pre[p0].second * (r * r - l * l) / 2);
			}
//			cout << ans << endl;
		}
		cout << fixed << setprecision(10) << ans / A << '\n'; 
	} else {
		sort(pa.begin(), pa.end());
		sort(pb.begin(), pb.end());
		auto &a = pa, &b = pb;
		int s = a.size(), t = b.size();
		vector<pdd> pre(t), suf(t);
		for (int i = 0; i < t; ++i) {
			int p = b[i];
			pre[i] = suf[i] = {p, 1};
		}
		for (int i = 1; i < t; ++i) {
			pre[i].first += pre[i - 1].first;
			pre[i].second += pre[i - 1].second;
		}
		for (int i = t - 2; i >= 0; --i) {
			suf[i].first += suf[i + 1].first;
			suf[i].second += suf[i + 1].second;
		}
		double ans = 0;
		for (int i = 0; i < s; ++i) {
			double p = a[i];
			int p0 = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
			int p1 = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
			if (p1 < t) {
				ans += (suf[p1].first);
				ans -= (suf[p1].second * p);
			}
			if (p0 > 0) {
				ans -= (pre[p0 - 1].first);
				ans += (pre[p0 - 1].second * p);
			}
		}
		cout << fixed << setprecision(10) << ans / n / m << '\n'; 
	}
	return 0;
}
/*
2 1
1 2
3 4
1 4

1 1
1 2
3 4
*/ 


