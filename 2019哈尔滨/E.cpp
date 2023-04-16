#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
const int N = 2e6 + 50;
int n, top, d[N], lc[N];
ll cnt[N];
vector <int> vec[N];
unordered_map <int, ll> mp;

int head[N], etop, id[N];
struct Edge
{
	int v, nxt;
}e[N + N];
void add(int u, int v)
{
	e[++etop] = Edge{v, head[u]};
	head[u] = etop;
	++d[v];
}

void init()
{
	etop = top = 0;
	mp.clear();
	for (int i = 0; i <= n; ++i)
		cnt[i] = d[i] = head[i] = 0;
}
void dag()
{
	queue <int> q;
	for (int i = 1; i <= n; ++i)
		if (!d[i]) q.push(i);
	cnt[n] = 1;
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		for (int v, i = head[u]; i; i = e[i].nxt)
		{
			v = e[i].v;
			cnt[v] += cnt[u];
			--d[v];
			if (!d[v]) q.push(v);
		}
	}
}
namespace IO {
  const int MAXSIZE = 1 << 18 | 1;
  char buf[MAXSIZE], *p1, *p2;

  inline int Gc() {
    return p1 == p2 &&
      (p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin), p1 == p2)? EOF: *p1++;
  }
  template<typename T> inline void read(T& x) {
    x = 0; int f = 0, ch = Gc();
    while (!isdigit(ch)) f |= ch == '-', ch = Gc();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = Gc();
    if (f) x = -x;
  }

  inline int read(char* s) {
    int lgt = 0, ch = Gc();
    while (isspace(ch)) ch = Gc();
    while (!isspace(ch)) s[++lgt] = ch, ch = Gc();
    return s[lgt + 1] = '\0', lgt;
  }
}
using IO::read;
int main()
{
	int T;
	read(T);
	while (T--)
	{
		read(n);
		init();
		for (int op, x, y, i = 1; i <= n; ++i)
		{
			read(op);
			if (op == 1)
			{
				
				id[++top] = i; vec[top].clear();
				read(lc[top]);
				for (int j = 0; j < lc[top]; j++)
				{
					read(x);
					vec[top].push_back(x);
				}
			}
			else
			{
				read(x); read(y);
				add(i, x); add(i, y);
			}
		}
		dag();
		ll len = 0, mx = 0;
		for (int i = 1; i <= top; ++i)
		{ 
			for (auto &v : vec[i])
			{
				mp[v] += cnt[id[i]];
				if (mp[v] > mx) mx = mp[v];
			}
			len += lc[i] * cnt[id[i]];
		} 
		if (mx <= (len >> 1))
			printf("%lld\n", len);
		else
			printf("%lld\n", len + len - mx - mx);

	}
	return 0;
}
