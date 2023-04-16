#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50, inf = 0x3f3f3f3f;
char s[N], t[N];
int n, m, ans, a[N];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		scanf("%s%s", s, t);
		ans = inf;
		printf("%d\n", ans == inf ? -1 : ans);
	}
	return 0;
}

