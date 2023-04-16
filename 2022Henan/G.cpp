#include <bits/stdc++.h>
using namespace std;
const int N = 4e3 + 50;
char s[N][N];
int n, m, ans;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%s", s[i]);
	for (int j = 0; j <= m; j++)
	{
		int flag = 1;
		for (int i = 1; i <= n; i++)
			flag &= s[i][j] - '0';
		ans += flag;
	}
	cout<<ans;
	return 0;
}

