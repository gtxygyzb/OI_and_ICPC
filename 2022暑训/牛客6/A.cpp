// A
#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
constexpr int N = 1e6;

int main() {
  //ios::sync_with_stdio(false), cin.tie(nullptr);
  int n;
  cin >> n;
  vector<pii> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first;
    a[i].second = i + 1;
  }
  vector<int> b(N);
  sort(a.begin(), a.end());
  int p = 0;
  for (int i = 0; i < n; ++i) {
    while (p < N && b[p] != 0)
      ++p;
    for (int j = p; j < N; j += a[i].first)
      if (b[j] == 0) b[j] = a[i].second;
  }
  vector<bool> vis(n + 1);
  int m = 0, c = 0;
  for (int i = 0; i < N; ++i) {
    int v = b[i];
    if (!vis[v]) {
      vis[v] = true;
      if (++c == n) { m = i + 1; break; }
    }
  }
  cout << m << '\n';
  for (int i = 0; i < m; ++i)
    cout << b[i] << " ";
  return 0;
}