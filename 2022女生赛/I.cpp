#include <bits/stdc++.h>
using namespace std;
const int N = 505, dx[] = {-1, -1, 0, 1, 1, 1, 0, -1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int a[N][N], n, m, q;
char s[N];


int x, y, v, d = 0;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s);
		for (int j = 0; j < m; j++)
		{
			a[i][j + 1] = s[j] == '#';
			if (s[j] == '*')
				x = i, y = j + 1;
		}
	}
	
	scanf("%d", &q); getchar();
	while (q--)
	{
		char op = getchar();
		if (op == 'U') ++v;
		if (op == 'D') v = max(v - 1, 0);
		if (op == 'R') d = (d + 1) % 8;
		if (op == 'L') d = (d - 1 + 8) % 8;
		int flag = 0;
		for (int i = 1; i <= v; i++)
		{
			int nx = x + dx[d], ny = y + dy[d];
			if (nx < 1 || nx > n || ny < 1 || ny > m || a[nx][ny])
				{flag = 1; break;}
			if (d == 1 && a[x - 1][y] && a[x][y + 1])
				{flag = 1; break;}
			if (d == 3 && a[x + 1][y] && a[x][y + 1])
				{flag = 1; break;}
			if (d == 5 && a[x + 1][y] && a[x][y - 1])
				{flag = 1; break;}
			if (d == 7 && a[x - 1][y] && a[x][y - 1])
				{flag = 1; break;}
			x = nx; y = ny;
		}
		if (flag) {printf("Crash! "); v = 0;}
		printf("%d %d\n", x, y);
	}
	return 0;
}
/*
5 4
....
##..
..#.
.*..
....
12
URULLULLLLUD
*/
