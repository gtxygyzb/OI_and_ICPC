#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int n, m, mp[N][N], bin[20] = {1};

int main()
{
	for (int i = 1; i <= 18; i++)
		bin[i] = bin[i - 1] << 1;
	int T;
	scanf("%d", &T);
	for (int cs = 1; cs <= T; cs++)
	{
		scanf("%d%d", &n, &m);
		memset(mp, 0, sizeof(mp));
		int ans = 0;
		for (int u, v, i = 1; i <= m; i++)
		{
			scanf("%d%d", &u, &v);
			--u; --v;
			mp[u][v] = mp[v][u] = 1;
		}
		vector <int> t0, t1;
		for (int s = 0; s < bin[n]; s++)
		{
			t0.clear(); t1.clear();
			for (int i = 0; i < n; i++)
				if (s & bin[i]) t1.push_back(i);
				else t0.push_back(i);
			int cnt = 0;
			for (auto u : t0)
				for (auto v : t0)
					if (mp[u][v])++cnt;
			for (auto u : t1)
				for (auto v : t1)
					if (mp[u][v]) ++cnt;
			ans = max(ans, m - cnt / 2);
		}
		
		printf("Case #%d: %d\n", cs, ans);
	}
	return 0;
}
/*
2
4 5
1 2
1 3
1 4
2 4
3 4
5 6
1 2
2 3
3 1
1 4
4 5
3 5
*/
