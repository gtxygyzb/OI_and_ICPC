// B
#include <bits/stdc++.h>
using namespace std;

using LL = long long;
constexpr int P = 998244353;

int fpow(int b, int m) {
  int ret = 1;
  while (m > 0) {
    if (m & 1) ret = (LL) ret * b % P;
    b = (LL) b * b % P, m >>= 1;
  }
  return ret;
}

struct BIT {
  vector<int> c;

  BIT() { }
  BIT(int n) { c.resize(n); }

  static int lowbit(int x) { return x & -x; }

  void mdy(int p, int d) {
    for (int i = p; i < (int) c.size(); i += lowbit(i))
      c[i] = (c[i] + d) % P;
  }
  void mdy(int l, int r, int d) {
    mdy(l, d), mdy(r + 1, -d);
  }
  int qry(int p) {
    int ret = 0;
    for (int i = p; i > 0; i -= lowbit(i))
      ret = (ret + c[i]) % P;
    return ret;
  }
};

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n), iva(n);
  for (int i = 1; i <= n - 1; ++i)
    cin >> a[i], iva[i] = fpow(a[i], P - 2);

  vector<BIT> f(n + 1, BIT(n + 1));
  f[0].mdy(1, 1, 1);
  for (int j = 0; j < n; ++j) {
    for (int i = 1; i <= n - 1; ++i) {
      int t = (LL) f[j].qry(i) * iva[i] % P;
      f[j + 1].mdy(i + 1, i + a[i], t);
    }
  }
  int ans = 0;
  for (int j = 1; j <= n; ++j)
    ans = (ans + (LL) f[j].qry(n) * f[j].qry(n) % P) % P;

  cout << ans << '\n';
  return 0;
}
