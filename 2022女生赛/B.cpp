#include <bits/stdc++.h>
using namespace std;
typedef set <int>::iterator IT;
const int N = 3e5 + 50;


int n, m, Q, f[N][20];
char s[N];

set <int> se[N];

int main()
{
	scanf("%d%d", &m, &n);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++)
		se[s[i] - 'a'].insert(i);
	for (int i = 1; i <= n; i++)
	{
		int mx = 0;
		for (int j = 0; j < m; j++)
		{
			IT it = se[j].lower_bound(i);
			if (it == se[j].end())
				mx = n + 5;
			else mx = max(mx, (*it) + 1);
		}
		f[i][0] = (mx == n + 5 ? 0 : mx);
		//cout<<f[i][0]<<" ";
	}
	for (int j = 1; j <= 19; j++)
		for (int i = 1; i <= n; i++)
			f[i][j] = f[f[i][j - 1]][j - 1];
	scanf("%d", &Q);
	for (int l, r, i = 1; i <= Q; i++)
	{
		scanf("%d%d", &l, &r);
		int u = l, ans = 0;
		for (int j = 19; ~j; j--)
			if (f[u][j] != 0 && f[u][j] <= r + 1)
			{
				u = f[u][j];
				ans += 1 << j;
			}
		printf("%d\n", ans + 1);
	}
	return 0;
}
/*
2 6
abaabb
3
1 4
2 5
3 6
*/
