#include <bits/stdc++.h>
using namespace std;
const int M = 5e5 + 50, dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int flag, qd, zd, m, vis[5][M];
char mp[5][M];
void dfs(int x, int y, int d)
{
	if (flag) return ;
	if (x == 2 && y == zd - 1)
	{
		flag = 1;
		return ;
	}
	
	if (x < 0 || x >= 2 || y < 0 || y >= m || vis[x][y]) return ;
	vis[x][y] = 1;
	
	if (mp[x][y] == 'I') dfs(x + dx[d], y + dy[d], d);
	else
	{
		if (d == 0 || d == 2)
		{
			dfs(x, y + 1, 1);
			dfs(x, y - 1, 3);
		}
		else
		{
			dfs(x + 1, y, 0);
			dfs(x - 1, y, 2);
		}
	}
	
	vis[x][y] = 0;
}

bool solve()
{
	scanf("%d%d%d", &m, &qd, &zd);
	for (int i = 0; i < 2; i++)
		scanf("%s", mp[i]);
	
	flag = 0;
	dfs(0, qd - 1, 0);
	return flag;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		if (solve()) puts("YES");
		else puts("NO");
	}
	return 0;
}

