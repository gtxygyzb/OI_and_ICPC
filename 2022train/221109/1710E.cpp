#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 50, inf = 0x3f3f3f3f;

void cmin(int &x, int y) {if (y < x) x = y;}
int f[2][N][3], n, m;

char s[N], t[N];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		scanf("%s%s", s + 1, t + 1);
		int pos = 0;
		for (int i = 1; i <= n; i++)
			if (pos < m && t[pos + 1] == s[i]) ++pos;
		if (pos < m)
		{
			puts("-1");
			continue;
		}
		int pl = m;
		for (int i = 1; i <= m; i++)
			if (s[i] != t[i])
			{
				pl = i - 1;
				break;
			}
		for (int j = 0; j <= m; j++)
			for (int k = 0; k <= 2; k++)
				f[0][j][k] = inf;
		f[0][0][0] = f[0][0][1] = f[0][0][2] = 0;
		for (int i = 1; i <= n; i++)
		{
			int u = i & 1, pre = (i & 1) ^ 1;
			for (int j = 0; j <= m; j++)
			{
				f[u][j][0] = f[u][j][1] = f[u][j][2] = inf;
				cmin(f[u][j][0], f[pre][j][0] + 2);
				cmin(f[u][j][2], f[pre][j][2] + 1);
				if (s[i] == t[j])
				{
					cmin(f[u][j][1], f[pre][j - 1][1]);
					cmin(f[u][j][0], f[pre][j - 1][0] + 1);
					cmin(f[u][j][2], f[pre][j - 1][2] + 1);
				}
				cmin(f[u][j][1], f[u][j][0]);
				cmin(f[u][j][2], f[u][j][1]);
			}
		}
		
		int ans = f[n & 1][m][2];
		printf("%d\n", min(ans + 1, n - pl));
	}
	return 0;
}
