#include <bits/stdc++.h>
using namespace std;
constexpr int N(4e6 + 5);
std::array<int, 26> ch[N];
int len[N], fa[N], cnt;
void init() {
  fa[0] = -1, cnt = 0, ch[0].fill(0);
}
int ins(int last, int x) {
  if (ch[last][x] && len[last] + 1 == len[ch[last][x]])
  	return ch[last][x];
  int p = last, np = ++cnt, q;
  len[np] = len[p] + 1;
  ch[np].fill(0);
  for (; ~p && !ch[p][x]; p = fa[p]) ch[p][x] = np;
  if (p == -1) {
    fa[np] = 0;
  } else if (len[q = ch[p][x]] == len[p] + 1) {
    fa[np] = q;
  } else {
    int nq = p == last ? np : ++cnt;
    len[nq] = len[p] + 1;
    ch[nq].fill(0);
    ch[nq] = ch[q];
    for (; ~p && ch[p][x] == q; p = fa[p]) ch[p][x] = nq;
    fa[np] = nq;
    fa[nq] = fa[q];
    fa[q] = nq;
  }
  return np;
}

std::vector<int> g[N];
int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  init();
  
  int n;
  std::cin >> n;
  std::vector<int> f(n);
  std::iota(f.begin(), f.end(), 0);
  
  auto find = [&](int x) {
    while (x != f[x]) {
      x = f[x] = f[f[x]];
    }
    return x;
  };
  
  for (int i = 0; i < n; i++) {
    std::string s;
    std::cin >> s;
    int o = 0;
    for (char c : s) {
      o = ins(o, c - 'a');
//      std::cerr << o << " ";
      
      g[o].push_back(i);
      //std::cout<<o<<" "<< i<<endl;
    }
//    std::cerr << "\n";
  }
  //cout<<"top: "<<cnt<<endl;
  std::vector<int> p(cnt);
  std::iota(p.begin(), p.end(), 1);
  std::sort(p.begin(), p.end(), [&](int i, int j) {
    return len[i] > len[j];
  });
  
  auto merge = [&](int x, int y) {
    x = find(x), y = find(y);
    return x != y ? f[y] = x, 1 : 0;
  };
  
  long long ans = 0;
  for (int x : p) {
    int rt = -1, c = 0;
//    std::cerr << "! " << x << "\n";
    for (int y : g[x]) {
//      std::cerr << y << "\n";
      if (~rt) c += merge(rt, y);
      else rt = y;
    }
    if (~rt) {
      g[fa[x]].push_back(rt);
    }
    //cout<<x<<" "<<len[x]<<" "<<c<<" "<<fa[x]<<endl;
//    std::cerr << "! " << x << " : " << len[x] << " " << c << " " << rt << "\n";
    ans += 1LL * len[x] * c;
  }
  
  std::cout << ans << "\n";
  return 0;
}
