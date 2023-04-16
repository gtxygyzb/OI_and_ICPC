#include <bits/stdc++.h>
#define lc (u << 1)
#define rc (u << 1 | 1) 
using namespace std;
typedef long long ll;
const int N = 2e6 + 50, R = 2e5;

namespace Cnt
{
	int t[N];
	void add(int x, int val)
	{
		for (; x <= R; x += x & -x)
			t[x] += val;
	}
	ll query(int x)
	{
		ll ret = 0;
		for (; x; x -= x & -x)
			ret += t[x];
		return ret;
	}
	ll query(int l, int r)
	{
		if (l > r) return 0;
		l = max(l, 1); r = min(r, R);
		return query(r) - query(l - 1);
	}
}
namespace Seg
{
	ll t[N], lazy[N];
	void pu(int u) {t[u] = t[lc] + t[rc];}
	void tag(int u, int l, int r, ll val)
	{
		t[u] += Cnt::query(l, r) * val;
		lazy[u] += val;
	}
	void pd(int u, int l, int r)
	{
		if (lazy[u])
		{
			int mid = l + r >> 1;
			tag(lc, l, mid, lazy[u]);
			tag(rc, mid + 1, r, lazy[u]);
			lazy[u] = 0;
		}
	}
	void change(int u, int l, int r, int pos, ll val)
	{
		if (l == r)
		{
			t[u] = val;
			return ;
		}
		pd(u, l, r);
		int mid = l + r >> 1;
		if (pos <= mid) change(lc, l, mid, pos, val);
		else change(rc, mid + 1, r, pos, val);
		pu(u);
	}
	void change(int x, ll val) {change(1, 1, R, x, val);}
	void add(int u, int st, int ed, int l, int r, ll val)
	{
		if (st <= l && r <= ed)
		{
			tag(u, l, r, val);
			return ;
		}
		pd(u, l, r);
		int mid = l + r >> 1;
		if (st <= mid) add(lc, st, ed, l, mid, val);
		if (ed > mid) add(rc, st, ed, mid + 1, r, val);
		pu(u);
	}
	void add(int l, int r, ll val)
	{
		l = max(l, 1);
		if (l > r) return ;
		add(1, l, r, 1, R, val);
	}
	ll query(int u, int st, int ed, int l, int r)
	{
		if (st <= l && r <= ed) return t[u];
		pd(u, l, r);
		int mid = l + r >> 1; ll ret = 0;
		if (st <= mid) ret += query(lc, st, ed, l, mid);
		if (ed > mid) ret += query(rc, st, ed, mid + 1, r);
		return ret;
	}
	ll query(int l, int r)
	{
		l = max(l, 1); r = min(r, R);
		if (l > r) return 0;
		return query(1, l, r, 1, R);
	}
}

int n, d, vis[N];
ll ans, ac;
int main()
{
	scanf("%d%d", &n, &d);
	for (int x, i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		ll c1 = Cnt::query(x + 1, x + d), c2 = Cnt::query(x - d, x - 1);
		ac = c1 * (c1 - 1) / 2 + c2 * (c2 - 1) / 2;
		ac -= Cnt::query(1, x) * Cnt::query(x - d + 1, x - 1);
		ac += Seg::query(x - d + 1, x - 1);
		if (!vis[x])
		{
			ans += ac;
			Seg::add(x - d, R, 1);
			Cnt::add(x, 1);
			Seg::change(x, Cnt::query(1, x + d));
		}
		else
		{
			ans -= ac;
			Seg::change(x, 0);
			Cnt::add(x, -1);
			Seg::add(x - d, R, -1);
		}
		vis[x] ^= 1;
		printf("%lld\n", ans);
	}
	return 0;
}
/*
5 5
8 5 3 2 1
*/
