#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, x, y, a[N];
int m, p[N];
int main()
{
	scanf("%d%d%d", &n, &x, &y);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
		scanf("%d", &p[i]);
	
	int op;
	if (x < y) op = 1;
	else op = -1;
	for (int i = x + op, j = x - op, k = 1; k <= m; i += op, j -= op, ++k)
	{
		if (a[i] != p[k]) return 0 * puts("Wrong");
		if (a[j] != p[k]) return 0 * puts("Right");
	}
	puts("Unsure");
	return 0;
}
