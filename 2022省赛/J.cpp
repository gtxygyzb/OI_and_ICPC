#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;
int a[N];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a+i);
	for (int i = 2; i <= n; i++)
		if (a[i] != a[i - 1])
		{
			printf("%d\n", n - 1);
			return 0;
		}
	printf("%d\n", n);
	return 0;
}

