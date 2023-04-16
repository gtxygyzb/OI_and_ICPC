// E
#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using Complex = complex<long double>;
constexpr long double PI = acosl(-1.0), EPS = 0.5;

namespace FTT {
  vector<int> rev;

  void init(int lim) {
    if ((int) rev.size() != lim) {
      int l = __builtin_ctz(lim) - 1;
      rev.resize(lim);
      for (int i = 1; i < lim; ++i)
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << l);
    }
  }

  void dft(vector<Complex>& f) {
    int lim = f.size();
    init(lim);
    for (int i = 1; i < lim; ++i)
      if (i < rev[i]) swap(f[i], f[rev[i]]);
    for (int k = 1; k < lim; k <<= 1) {
      Complex wn = exp(Complex(0.0, PI / k));
      for (int i = 0; i < lim; i += k << 1) {
        Complex w = 1.0;
        for (int j = 0; j < k; ++j, w *= wn) {
          auto f0 = f[i+j], f1 = w * f[i+j+k];
          f[i+j] = f0 + f1, f[i+j+k] = f0 - f1;
        }
      }
    }
  }
  void idft(vector<Complex>& f) {
    int lim = f.size();
    dft(f);
    for (auto &v: f) v /= lim;
    reverse(f.begin() + 1, f.end());
  }
}

struct Poly {
  vector<Complex> a;

  Poly() = default;
  Poly(int n): a(n) { }
  Poly(const vector<Complex>& _a): a(_a) { }
  Poly(const initializer_list<Complex>& _a): a(_a) { }
  int size() const {
    return a.size();
  }
  void resize(int n) {
    a.resize(n);
  }

  Complex operator [](int idx) const {
    return (0 <= idx && idx < size())? a[idx]: 0;
  }
  Complex& operator [](int idx) {
    return a[idx];
  }
  friend Poly operator * (Poly f, Poly g) {
    int lim = 1, n = f.size(), m = g.size();
    while (lim < n + m - 1) lim <<= 1;
    f.resize(lim), FTT::dft(f.a);
    g.resize(lim), FTT::dft(g.a);
    for (int i = 0; i < lim; ++i)
      f[i] *= g[i];
    FTT::idft(f.a), f.resize(n + m - 1);
    return f;
  }
  Poly& operator *= (const Poly& rhs) {
    return *this = *this * rhs;
  }
};

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<int> p(n + 1);
  for (int i = 1; i <= n; ++i)
    cin >> p[i];

  vector<int> vis(n + 1);
  unordered_map<int, vector<LL>> ans;
  for (int i = 1; i <= n; ++i) if (!vis[i]) {
    vector<int> a;
    for (int j = i; !vis[j]; j = p[j]) {
      a.push_back(j);
      vis[j] = true;
    }
    int cnt = a.size();
    Poly f(cnt), g(cnt);
    for (int j = 0; j < cnt; ++j) {
      f[j] = a[j];
      g[j] = a[cnt - j - 1];
    }
    f *= g;
    if (ans.count(cnt) == 0)
      ans[cnt].resize(cnt);
    auto& vec = ans[cnt];
    int m = f.size();
    for (int j = 0; j < cnt; ++j) {
      auto t = f[j].real();
      if (j + cnt < m) t += f[j + cnt].real();
      vec[cnt - j - 1] += (LL) (t + EPS);
    }
  }

  for (int k; q > 0; --q) {
    cin >> k;
    LL cur = 0;
    for (auto &v: ans) {
      auto& vec = v.second;
      int cnt = vec.size();
      cur += vec[k % cnt];
    }
    cout << cur << '\n';
  }
  return 0;
}

