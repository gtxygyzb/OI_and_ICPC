#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 50, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int a[N][N], n, m, vis[N][N], sr, sc, tr, tc, tim;
int x[N * N], A, B, C, P;
struct Data
{
	int x, y, val;
	bool operator <(const Data &t) const {return val < t.val;}
};

void init()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			vis[i][j] = 0;
}
int main()
{
	int T;
	scanf("%d", &T);
	for (int cs = 1; cs <= T; cs++)
	{
		ll ans = 0;
		scanf("%d%d%d%d%d%d", &n, &m, &sr, &sc, & tr, &tc);
		scanf("%d%d%d%d%d%d", &x[1], &x[2], &A, &B, &C, &P);
		++tim;
		for (int i = 3; i <= n * m; i++)
			x[i] = (A * x[i - 1] + B * x[i - 2] + C) % P;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				a[i][j] = x[(i - 1) * m + j];
		
		priority_queue <Data> q;
		vis[sr][sc] = tim;
		for (int k = 0; k < 4; k++)
		{
			int nx = sr + dx[k], ny = sc + dy[k];
			if (nx < 1 || nx > n || ny < 1 || ny > m || vis[nx][ny] == tim) continue;
			q.push(Data{nx, ny, a[sr][sc] * a[nx][ny]});
		}
		puts("-------------");
		int cnt=1;
		while (!q.empty())
		{
			Data u = q.top(); q.pop();
			if (u.val == 0) break;
			if (vis[u.x][u.y] == tim) continue;
			ans += u.val;
			vis[u.x][u.y] = tim;
			cnt++;
			if(cnt>=n*m) break; 
			for (int k = 0; k < 4; k++)
			{
				int nx = u.x + dx[k], ny = u.y + dy[k];
				if (nx < 1 || nx > n || ny < 1 || ny > m || vis[nx][ny] == tim) continue;
				q.push(Data{nx, ny, a[u.x][u.y] * a[nx][ny]});
			}
		}
		printf("Case #%d: %lld\n", cs, ans);
	}
	return 0;
}
/*
1
1000 1000 1 2 1 3
1 2 2 34 1 100
*/
