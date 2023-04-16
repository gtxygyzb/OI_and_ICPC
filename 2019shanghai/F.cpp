// F
#include <bits/stdc++.h>
using namespace std;

using LL = long long;
constexpr int MAXN = 1e5 + 5, P = 1e9 + 7;

int fpow(int b, int m) {
  int ret = 1;
  while (m > 0) {
    if (m & 1) ret = (LL) ret * b % P;
    b = (LL) b * b % P, m >>= 1;
  }
  return ret;
}
int norm(int x) {
  if (x < 0)
    return x + P;
  if (x >= P)
    return x - P;
  return x;
}

struct Mint {
  int x;
  Mint(int _x = 0): x(norm(_x)) { }
  Mint inv() const {
    assert(x != 0);
    return fpow(x, P - 2);
  }
  Mint operator - () const {
    return norm(-x);
  }
  Mint& operator += (const Mint& rhs) {
    x = norm(x + rhs.x);
    return *this;
  }
  Mint& operator -= (const Mint& rhs) {
    x = norm(x - rhs.x);
    return *this;
  }
  Mint& operator *= (const Mint& rhs) {
    x = (LL) x * rhs.x % P;
    return *this;
  }
  Mint& operator /= (const Mint& rhs) {
    return *this *= rhs.inv();
  }
  friend Mint operator + (const Mint& lsh, const Mint& rhs) {
    Mint ret = lsh;
    return ret += rhs;
  }
  friend Mint operator - (const Mint& lsh, const Mint& rhs) {
    Mint ret = lsh;
    return ret -= rhs;
  }
  friend Mint operator * (const Mint& lsh, const Mint& rhs) {
    Mint ret = lsh;
    return ret *= rhs;
  }
  friend Mint operator / (const Mint& lsh, const Mint& rhs) {
    Mint ret = lsh;
    return ret /= rhs;
  }
  friend istream& operator >> (istream& is, Mint& a) {
    return is >> a.x;
  }
  friend ostream& operator << (ostream& os, const Mint& a) {
    return os << a.x;
  }
  bool operator < (const Mint& rhs) const {
    return x < rhs.x;
  }
  bool operator != (const Mint& rhs) const {
    return x != rhs.x;
  }
  bool operator == (const Mint& rhs) const {
    return x == rhs.x;
  }
};

int n, q;
int a[MAXN];
int rnk[MAXN], dfn[MAXN], clk;

#define lc (nd << 1)
#define rc (nd << 1 | 1)
namespace SGT {
  Mint x3[MAXN << 2], x2[MAXN << 2], x1[MAXN << 2];
  Mint upd[MAXN << 2], mul[MAXN << 2], pls[MAXN << 2];

  inline void maintain(int nd) {
    x1[nd] = x1[lc] + x1[rc];
    x2[nd] = x2[lc] + x2[rc];
    x3[nd] = x3[lc] + x3[rc];
  }
  inline void pushUpd(int nd, int l, int r, Mint w) {
    Mint len = r - l + 1, w1 = w, w2 = w * w1, w3 = w * w2;
    x1[nd] = len * w1;
    x2[nd] = len * w2;
    x3[nd] = len * w3;
    mul[nd] = 1, pls[nd] = 0;
  }
  inline void pushMul(int nd, Mint w) {
    Mint w1 = w, w2 = w * w1, w3 = w * w2;
    x1[nd] *= w1;
    x2[nd] *= w2;
    x3[nd] *= w3;
    mul[nd] *= w, pls[nd] *= w;
  }
  inline void pushPls(int nd, int l, int r, Mint w) {
    Mint lx1 = x1[nd], lx2 = x2[nd], lx3 = x3[nd];
    Mint len = r - l + 1, w1 = w, w2 = w * w1, w3 = w * w2;
    x1[nd] = lx1 + w1 * len;
    x2[nd] = lx2 + 2 * w1 * lx1 + w2 * len;
    x3[nd] = lx3 + 3 * w1 * lx2 + 3 * w2 * lx1 + w3 * len;
    pls[nd] += w;
  }
  inline void pushdown(int nd, int l, int r) {
    int mid = (l + r) / 2;
    if (upd[nd] != -1) {
      pushUpd(lc, l, mid, upd[nd]);
      pushUpd(rc, mid + 1, r, upd[nd]);
      upd[nd] = -1;
    }
    if (mul[nd] != 1) {
      pushMul(lc, mul[nd]);
      pushMul(rc, mul[nd]);
      mul[nd] = 1;
    }
    if (pls[nd] != 0) {
      pushPls(lc, l, mid, pls[nd]);
      pushPls(rc, mid + 1, r, pls[nd]);
      pls[nd] = 0;
    }
  }

  void build(int nd, int l, int r) {
    upd[nd] = -1;
    mul[nd] = 1;
    pls[nd] = 0;
    if (l == r) {
      int w = a[rnk[l]];
      x1[nd] = fpow(w, 1);
      x2[nd] = fpow(w, 2);
      x3[nd] = fpow(w, 3);
      return;
    }
    int mid = (l + r) / 2;
    build(lc, l, mid), build(rc, mid + 1, r);
    maintain(nd);
  }

  void mdyUpd(int nd, int l, int r, int opl, int opr, int w) {
    if (opl <= l && r <= opr) {
      pushUpd(nd, l, r, w);
      return;
    }
    int mid = (l + r) / 2;
    pushdown(nd, l, r);
    if (opl <= mid)
      mdyUpd(lc, l, mid, opl, opr, w);
    if (opr > mid)
      mdyUpd(rc, mid + 1, r, opl, opr, w);
    maintain(nd);
  }
  void mdyMul(int nd, int l, int r, int opl, int opr, int w) {
    if (opl <= l && r <= opr) {
      pushMul(nd, w);
      return;
    }
    int mid = (l + r) / 2;
    pushdown(nd, l, r);
    if (opl <= mid)
      mdyMul(lc, l, mid, opl, opr, w);
    if (opr > mid)
      mdyMul(rc, mid + 1, r, opl, opr, w);
    maintain(nd);
  }
  void mdyPls(int nd, int l, int r, int opl, int opr, int w) {
    if (opl <= l && r <= opr) {
      pushPls(nd, l, r, w);
      return;
    }
    int mid = (l + r) / 2;
    pushdown(nd, l, r);
    if (opl <= mid)
      mdyPls(lc, l, mid, opl, opr, w);
    if (opr > mid)
      mdyPls(rc, mid + 1, r, opl, opr, w);
    maintain(nd);
  }

  Mint qry(int nd, int l, int r, int opl, int opr) {
    if (opl <= l && r <= opr)
      return x3[nd];
    int mid = (l + r) / 2;
    pushdown(nd, l, r);
    if (opr <= mid)
      return qry(lc, l, mid, opl, opr);
    if (opl > mid)
      return qry(rc, mid + 1, r, opl, opr);
    return qry(lc, l, mid, opl, opr) + qry(rc, mid + 1, r, opl, opr);
  }
}
#undef lc
#undef rc

namespace HLD {
  struct Edge {
    int nxt, v;
  } edges[MAXN << 1];
  int head[MAXN], eidx;

  inline void init() {
    memset(head, -1, sizeof head), eidx = 1;
  }
  inline void addEdge(int u, int v) {
    edges[++eidx] = {head[u], v}, head[u] = eidx;
  };

  int size[MAXN], pre[MAXN], depth[MAXN], son[MAXN], topfa[MAXN];

  void dfs1(int u, int fa) {
    depth[u] = depth[fa] + 1;
    pre[u] = fa, size[u] = 1, son[u] = -1;
    for (int i = head[u]; ~i; i = edges[i].nxt) {
      int v = edges[i].v;
      if (v == fa) continue;
      dfs1(v, u);
      size[u] += size[v];
      if (son[u] == -1 || size[v] > size[son[u]])
        son[u] = v;
    }
  }
  void dfs2(int u, int top) {
    topfa[u] = top, rnk[dfn[u] = ++clk] = u;
    if (~son[u])
      dfs2(son[u], top);
    for (int i = head[u]; ~i; i = edges[i].nxt) {
      int v = edges[i].v;
      if (v == pre[u] || v == son[u]) continue;
      dfs2(v, v);
    }
  }

  inline void build() {
    clk = 0;
    dfs1(1, 0), dfs2(1, 1);
  }

  void mdyUpd(int u, int v, int w) {
    while (topfa[u] != topfa[v]) {
      if (depth[topfa[u]] < depth[topfa[v]])
        swap(u, v);
      SGT::mdyUpd(1, 1, n, dfn[topfa[u]], dfn[u], w);
      u = pre[topfa[u]];
    }
    if (depth[u] > depth[v])
      swap(u, v);
    SGT::mdyUpd(1, 1, n, dfn[u], dfn[v], w);
  }
  void mdyMul(int u, int v, int w) {
    while (topfa[u] != topfa[v]) {
      if (depth[topfa[u]] < depth[topfa[v]])
        swap(u, v);
      SGT::mdyMul(1, 1, n, dfn[topfa[u]], dfn[u], w);
      u = pre[topfa[u]];
    }
    if (depth[u] > depth[v])
      swap(u, v);
    SGT::mdyMul(1, 1, n, dfn[u], dfn[v], w);
  }
  void mdyPls(int u, int v, int w) {
    while (topfa[u] != topfa[v]) {
      if (depth[topfa[u]] < depth[topfa[v]])
        swap(u, v);
      SGT::mdyPls(1, 1, n, dfn[topfa[u]], dfn[u], w);
      u = pre[topfa[u]];
    }
    if (depth[u] > depth[v])
      swap(u, v);
    SGT::mdyPls(1, 1, n, dfn[u], dfn[v], w);
  }

  Mint qry(int u, int v) {
    Mint ret = 0;
    while (topfa[u] != topfa[v]) {
      if (depth[topfa[u]] < depth[topfa[v]])
        swap(u, v);
      ret += SGT::qry(1, 1, n, dfn[topfa[u]], dfn[u]);
      u = pre[topfa[u]];
    }
    if (depth[u] > depth[v])
      swap(u, v);
    ret += SGT::qry(1, 1, n, dfn[u], dfn[v]);
    return ret;
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  int ti;
  cin >> ti;
  for (int cs = 1; cs <= ti; ++cs) {
    HLD::init();
    cin >> n;
    for (int u, v, i = 1; i < n; ++i) {
      cin >> u >> v;
      HLD::addEdge(u, v), HLD::addEdge(v, u);
    }
    for (int i = 1; i <= n; ++i)
      cin >> a[i];
    HLD::build();
    SGT::build(1, 1, n);
    cin >> q;
    cout << "Case #" << cs << ":\n";
    for (int opt, u, v, w; q > 0; --q) {
      cin >> opt >> u >> v;
      if (opt == 1)
        cin >> w, HLD::mdyUpd(u, v, w);
      if (opt == 2)
        cin >> w, HLD::mdyPls(u, v, w);
      if (opt == 3)
        cin >> w, HLD::mdyMul(u, v, w);
      if (opt == 4)
        cout << HLD::qry(u, v) << '\n';
    }
  }
  return 0;
}
