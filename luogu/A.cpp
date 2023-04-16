#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 50;

int len, ans[N], in[N], out[N], dfn;

struct Graph
{
    int etop, head[N];
    Graph () {memset(head, -1, sizeof(head));}
    struct Edge
	{
		int v, nxt;
	}e[N];

    void add(int u, int v)
    {
        e[++etop].v = v;
        e[etop].nxt = head[u];
        head[u] = etop;
    }
    void dfs(int u)
    {
        in[u] = ++dfn;
        for (int i = head[u]; ~i; i = e[i].nxt)
            dfs(e[i].v);
        out[u] = dfn;
    }
}G;

namespace BIT
{
	int a[N];
	void add(int pos, int val)
    {
		for (int i = pos; i <= dfn; i += i & -i)
			a[i] += val;
	}
	int query(int pos)
    {
		int ret = 0;
		for (int i = pos; i; i -= i & -i)
			ret += a[i];
		return ret;
	}
	int query(int l, int r)
    {
		return query(r) - query(l - 1);
	}
}

struct Query
{
	int x, y, id;
	void input(int _id)
    {
		id = _id;
		scanf("%d%d", &x, &y);
	}
	bool operator <(const Query &t) const
    {
		return y < t.y;
	}
}ask[N];

namespace AC
{
	int ch[N][26], top, fa[N], fail[N], num, pos[N];

	void trie(char *s)
	{
		int u = 0;
		for (int v, i = 0; i < len; i++)
		{
			if (s[i] == 'P')
				pos[++num] = u;
			else if (s[i] == 'B')
				u = fa[u];
			else
			{
				v = s[i] - 'a';
				if (!ch[u][v])
					ch[u][v] = ++top;
				fa[ch[u][v]] = u;
				u = ch[u][v];
			}
		}
	}

	void build()
	{
		queue <int> q;
		for (int i = 0; i < 26; i++)
			if (ch[0][i])
			{
				q.push(ch[0][i]);
				G.add(0, ch[0][i]);
			}
		while (!q.empty())
		{
			int u = q.front();
			q.pop();
			for (int v, i = 0; i < 26; i++)
			{
				v = ch[u][i];
				if (v)
				{
					fail[v] = ch[fail[u]][i];
					q.push(v);
					G.add(fail[v], v);
				}
				else ch[u][i] = ch[fail[u]][i];
			}
		}
		G.dfs(0);
	}

	void work(char *s)
    {
		int u = 0, cnt = 0, k = 1;
		for (int i = 0; i < len; i++)
        {
			if (s[i] == 'B')
            {
				BIT::add(in[u], -1);
				u = fa[u];
			}
            else if (s[i] == 'P')
            {
				++cnt;
				while (ask[k].y == cnt)
                {
					int x = pos[ask[k].x];
					ans[ask[k].id] = BIT::query(in[x], out[x]);
					++k;
				}
			}
            else 
            {
				u = ch[u][s[i] - 'a'];
				BIT::add(in[u], 1);
			}
		}
	}
}

char s[N];

int main()
{
	scanf("%s", s);
	len = strlen(s);
	AC::trie(s);
	AC::build();
	int m;
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
		ask[i].input(i);
	sort(ask + 1, ask + m + 1);
	AC::work(s);
	for (int i = 1; i <= m; i++)
		printf("%d\n", ans[i]);
	return 0;
}
/*
aPaPBbP
3
1 2
1 3
2 3
*/