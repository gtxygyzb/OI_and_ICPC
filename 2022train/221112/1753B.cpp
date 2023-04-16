#include <bits/stdc++.h> 
using namespace std;
const int N = 1e6 + 50;
int cnt[N];
int main()
{
	int n, x;
	scanf("%d%d", &n, &x);
	for (int a, i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		++cnt[a];
	}
	for (int i = 1; i < x; i++)
	{
		int d = cnt[i] / (i + 1);
		cnt[i + 1] += d;
		cnt[i] -= d * (i + 1);
		if (cnt[i] > 0)
			return 0 * puts("No");
	}
	puts("Yes");
	return 0;
}
