#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
const int MAXN = 1e6 + 10;

struct query {
	int id, a, b, c;
} que[MAXN];

struct node1 {
	int l, r, x;
	node1(int l, int r, int x): l(l), r(r), x(x) {
	}
};

struct node {
	int l, r, cnt;
	node *lef;
	node *rig;
	node(int lb = 0, int rb = 0) {
		l = lb;
		r = rb;
		cnt = 0;
		lef = rig = NULL;
	}
};

int ans[MAXN], to[MAXN], num[MAXN];
int n, m, q;

int add(int l, int r, node *rt) {
	if (rt->cnt == rt->r - rt->l + 1)
		return 0;
	if (l == rt->l && r == rt->r) {
		int tp = rt->cnt;
		rt->cnt = r - l + 1;
		return rt->cnt - tp;
	}
	int mid = (rt->l + rt->r) >> 1;
	if (r <= mid) {
		if (!rt->lef) {
			rt->lef = new node(rt->l, mid);
		}
		int ans = add(l, r, rt->lef);
		rt->cnt += ans;
		return ans;
	}
	if (l > mid) {
		if (!rt->rig) {
			rt->rig = new node(mid + 1, rt->r);
		}
		int ans = add(l, r, rt->rig);
		rt->cnt += ans;
		return ans;
	}
	if (!rt->lef) {
		rt->lef = new node(rt->l, mid);
	}
	if (!rt->rig) {
		rt->rig = new node(mid + 1, rt->r);
	}
	int ans = add(mid + 1, r, rt->rig) + add(l, mid, rt->lef);
	rt->cnt += ans;
	return ans;
}

int solve(int ed, int id) {
	for (int i = 0; i <= m; i++) {
		to[i] = i;
		num[i] = 0;
	}
	num[0] = n;
	vector<node1> v;
	for (int i = ed; i >= 1; i--) {
		if (que[i].id == 1)
			v.push_back(node1(que[i].a, que[i].b, to[que[i].c]));
		else if (que[i].id == 2)
			to[que[i].a] = to[que[i].b];
		else if (que[i].id == 3)
			swap(to[que[i].a], to[que[i].b]);
	}
	node *rt = new node(1, n);
	int all = 0;
	for (node1 p : v) {
		int tpn = add(p.l, p.r, rt);
		if (p.x != 0) {
			num[p.x] += tpn;
			all += tpn;
		}
	}
	num[0] -= all;
	if (id == 4) {
		return num[que[ed + 1].a];
	}
	if (all == 0)
		return 0;
	int mx = -1, mxid = -1;
	for (int i = 1; i <= m; i++) {
		if (num[i] > mx) {
			mx = num[i];
			mxid = i;
		}
	}
	return mxid;
}

int main() {
	int tp = 0;
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= q; i++) {
		scanf("%d", &que[i].id);
		if (que[i].id == 1)
			scanf("%d%d%d", &que[i].a, &que[i].b, &que[i].c);
		else if (que[i].id == 4)
			scanf("%d", &que[i].a);
		else if (que[i].id != 5)
			scanf("%d%d", &que[i].a, &que[i].b);
	}
	if (m == 1) {
		node *rt = new node(1, n);
		int now = 0;
		for (int i = 1; i <= q; i++) {
			if (que[i].id == 1) {
				now += add(que[i].a, que[i].b, rt);
			} else if (que[i].id == 2) {
				rt = new node(1, n);
				now = 0;
			} else if (que[i].id == 4) {
				if (que[i].a == 1)
					ans[++tp] = now;
				else
					ans[++tp] = n - now;
			} else if (que[i].id == 5) {
				if (now == 0)
					ans[++tp] = 0;
				else
					ans[++tp] = 1;
			}
		}
	} else {//if (m <= 2000 && q <= 2000) {
		for (int i = 1; i <= q; i++) {
			if (que[i].id == 4 || que[i].id == 5) {
				ans[++tp] = solve(i - 1, que[i].id);
			}
		}
	}
	for (int i = 1; i <= tp; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}
/*
10 2 15
5
1 2 4 1
1 4 7 2
4 1
5
1 3 4 1
5
1 7 9 1
3 1 2
4 2
2 1 2
4 2
2 2 0
4 2
5

*/