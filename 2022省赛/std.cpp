#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;
int n, a[N], cnt[N];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", a+i);
		++cnt[a[i]];
	}
	sort(a + 1, a + n + 1);
	int ans = n - cnt[a[1]];
	int x = a[n] % a[1];
	for (int i = n - 1; i > ans; i--)
	{
		int flag = 1;
		for (int j = 1; j <= i && flag; j++)
			for (int k = i + 1; k <= n && flag; k++)
			{
				if (a[k] % a[j] != x) flag = 0;
			}
		if (flag) {ans = i; break;}
	}
	printf("%d\n", ans);
	return 0;
}
