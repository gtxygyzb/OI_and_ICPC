// L
#include <bits/stdc++.h>
using namespace std;

int n, m;
double pa, pb, pt;
vector<int> a, b, ha, ca, hb, cb;

void dfs(double p, int cur) {
	int ala = 0, alb = 0;
	for (int i = 0; i < n; ++i)
		if (ha[i] > 0) ++ala;
	for (int j = 0; j < m; ++j)
		if (hb[j] > 0) ++alb;
	if (ala == 0 || alb == 0) {
		if (ala == 0 && alb == 0)
			pt += p;
		else if (alb == 0)
			pa += p;
		else
			pb += p;
		return;
	}
	if (cur) {
		// Alice
		int posa = -1;
		for (int i = 0; i < n; ++i) if (ha[i] > 0)
			if (posa == -1 || ca[posa] > ca[i])
				posa = i;
		if (posa != -1) {
			for (int j = 0; j < m; ++j) if (hb[j] > 0) {
				++ca[posa];
//				++cb[j];
				hb[j] -= a[posa], ha[posa] -= b[j];
				dfs(p / alb, cur ^ 1);
				--ca[posa];
//				--cb[j];
				hb[j] += a[posa], ha[posa] += b[j];
			}
		}
	} else {
		// Bob
		int posb = -1;
		for (int j = 0; j < m; ++j) if (hb[j] > 0)
			if (posb == -1 || cb[posb] > cb[j])
				posb = j;
		if (posb != -1) {
			for (int i = 0; i < n; ++i) if (ha[i] > 0) {
				++cb[posb];
//				++ca[i];
				ha[i] -= b[posb], hb[posb] -= a[i];
				dfs(p / ala, cur ^ 1);
				--cb[posb];
//				--ca[i];
				ha[i] += b[posb], hb[posb] += a[i];
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> m;
	a.resize(n), b.resize(m);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int j = 0; j < m; ++j)
		cin >> b[j];
	ha = a, hb = b;
	ca = vector<int>(n, 0), cb = vector<int>(m, 0);
	if (n == m) {
		dfs(0.5, 1), dfs(0.5, 0);
	} else {
		dfs(1.0, n > m);
	}
	cout << fixed << setprecision(10) << pa << '\n' << pb << '\n' << pt << '\n'; 
	return 0;
}

