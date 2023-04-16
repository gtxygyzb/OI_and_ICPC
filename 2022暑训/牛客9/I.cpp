// K
#include <bits/stdc++.h>
using namespace std;

using LL = long long;

void FWT(vector<int>& f, int type) {
  int n = f.size();
  for (int k = 1; 2 * k <= n; k <<= 1)
    for (int i = 0; i < n; i += k << 1)
      for (int j = 0; j < k; ++j)
        f[i+j+k] += type * f[i+j];
}

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  int N = 1 << k;
  vector<LL> f(N), g(N);
  for (int m, i = 0; i < n; ++i) {
    cin >> m;
    int s = 0;
    for (int x; m > 0; --m)
      cin >> x, s |= (1 << (x - 1));
    f[s] = g[s] = 1;
  }
  vector<int> vis(N);
  for (int i = 1; i <= k; ++i) {
    if (i == 1) {
      FWT(g, 1);
    } else {
      FWT(f, 1);
      for (int j = 0; j < N; ++j)
        f[j] *= g[j];
      FWT(f, -1);
      for (int j = 0; j < N; ++j)
        if (f[j] > 0) f[j] = 1;
    }
    int ans = 0;
    for (int j = 0; j < N; ++j)
      if (!vis[j] && f[j] > 0) ++ans, vis[j] = true;
    cout << ans << " \n"[i == k];
  }
  return 0;
}