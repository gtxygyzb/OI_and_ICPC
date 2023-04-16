#include <bits/stdc++.h>
#define IT set<Node>::iterator
using namespace std;
typedef long long ll;
const ll P = 1e9 + 7;
const int N = 1e5 + 50;

struct Node
{
    int l, r;
    mutable ll v;
    Node (int L, int R = -1, ll V=0):l(L), r(R), v(V) {}
    bool operator <(const Node &t) const
    {
        return l < t.l;
    }
};
set <Node> s;
IT split(int pos) //将pos位置分为[l, pos - 1 ]和 [pos, r]
{
    IT it = s.lower_bound(Node(pos));
    if (it != s.end() && it->l == pos) return it;
    --it;
    int L = it->l, R= it->r;
    ll V = it->v;
    s.erase(it);
    s.insert(Node(L, pos - 1, V));
    return s.insert(Node(pos, R, V)).first;
}
void assign(int l, int r, ll val=0) //区间推平
{
    IT itr = split(r + 1), itl = split(l);
    s.erase(itl, itr); //删除这个区间内所有元素
    s.insert(Node(l, r, val));
}
void add(int l, int r, ll val) //区间加法
{
    IT itr = split(r + 1), itl = split(l);
    for (; itl != itr; ++itl) itl->v += val;
}
ll rk(int l, int r, int k) //区间第k小
{
    vector < pair<ll, int> > vec; // 数值与出现次数
    IT itr = split(r + 1), itl = split(l);
    for (; itl != itr; ++itl)
        vec.push_back(pair<ll, int>(itl->v, itl->r - itl->l + 1));
    sort(vec.begin(), vec.end());
    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        k -= it->second;
        if (k <= 0) return it->first;
    }
}
ll power(ll x, ll k, ll mod)
{
	ll ret = 1;
	for (; k; k >>= 1, x = x * x % mod)
		if (k & 1) ret = ret * x % mod;
	return ret;
}
ll sum(int l, int r, ll ex, ll mod)
{
	IT itr = split(r + 1), itl = split(l);
	ll ret = 0;
	for (; itl != itr; ++itl)
	{
		ll siz = itl->r - itl->l + 1;
		ret = (ret + siz * power(itl->v % mod, ex, mod)) % mod;
	}
	return ret;
}

int n, m;
ll seed, vmax, a[N];
ll rnd()
{
    ll ret = seed;
    seed = (seed * 7 + 13) % P;
    return ret;
}

int main()
{
    scanf("%d%d%lld%lld", &n, &m, &seed, &vmax);
    for (int i = 1; i <= n; i++)
    {
        a[i] = rnd() % vmax + 1;
        s.insert(Node(i, i, a[i]));
    }
    for (int op, l, r; m--;)
    {
        ll x, y;
        op = rnd() % 4 + 1;
        l = rnd() % n + 1;
        r = rnd() % n + 1;
        if (l > r) swap(l, r);
        if (op == 3) x = (rnd() % (r - l + 1)) + 1;
        else x = rnd() % vmax + 1;
        if (op == 4) y = rnd() % vmax + 1;
        
        if (op == 1) add(l, r, x);
        if (op == 2) assign(l, r, x);
        if (op == 3) printf("%lld\n", rk(l, r, x));
        if (op == 4) printf("%lld\n", sum(l, r, x, y));
    }
    return 0;
}
