// C
#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 2 * 100 + 5, MAXM = MAXN * 3 + MAXN * MAXN;
constexpr int INF = 0x3f3f3f3f;

int S, T;

namespace MCMF {
	struct Edge {
		int nxt, to, cap, flow, cost;
	} edges[MAXM << 1];
	int head[MAXN], eidx;
	
	inline void init() {
		memset(head, -1, sizeof head), eidx = 1;
	}
	inline void addEdge(int u, int v, int c, int w) {
		cout << u << ' ' << v << ' ' << c << ' ' << w << endl;
		edges[++eidx] = {head[u], v, c, 0, w}, head[u] = eidx;
		edges[++eidx] = {head[v], u, 0, 0, -w}, head[v] = eidx;
	}
	
	bool inq[MAXN];
	int d[MAXN], a[MAXN], pre[MAXN];
	
	bool SPFA() {
		static int Q[MAXN << 2], h, t;
		memset(d, 0x3f, sizeof d);
		Q[h = t = 1] = S;
		pre[S] = d[S] = 0, a[S] = INF, inq[S] = true;
		while (h <= t) {
			int u = Q[h++];
			inq[u] = false;
			for (int i = head[u]; ~i; i = edges[i].nxt) {
				const Edge& e = edges[i];
				if (d[e.to] > d[u] + e.cost && e.cap > e.flow) {
					a[e.to] = min(a[u], e.cap - e.flow);
					d[e.to] = d[u] + e.cost, pre[e.to] = i;
					if (!inq[e.to]) Q[++t] = e.to, inq[e.to] = true;
				}
			}
		}
		return d[T] < INF;
	}
	
	void MCMF(int& flow, int& cost) {
		flow = cost = 0;
		while (SPFA()) {
			flow += a[T], cost += a[T] * d[T];
			for (int u = T; u != S; u = edges[pre[u] ^ 1].to) {
				edges[pre[u]].flow += a[T];
				edges[pre[u] ^ 1].flow -= a[T];
			}
		}
	}
}

int f[MAXN][MAXN];
int LCS(const string& s, const string& t) {
	int n = s.size(), m = t.size();
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
	MCMF::init();
	int n, k;
	cin >> n >> k;
	vector<int> l(n + 1);
	vector<string> s(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> l[i] >> s[i];
	S = 2 * n + 1, T = 2 * n + 2;
	for (int i = 1; i <= n; ++i) {
		MCMF::addEdge(S, i, INF, l[i]);
		MCMF::addEdge(i, n + 1, 1, 0);
		MCMF::addEdge(n + i, T, 1, 0);
		for (int j = 1; j < i; ++j) {
			int m = LCS(s[i], s[j]), w = l[i] - m + l[j] - m + k;
			MCMF::addEdge(i, n + j, 1, w - l[i]);
			MCMF::addEdge(j, n + i, 1, w - l[j]);
		}
	}
	int flow, cost;
	MCMF::MCMF(flow, cost);
	cout << flow << endl;
	cout << cost << '\n';
	return 0;
}











