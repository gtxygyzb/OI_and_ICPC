#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	if (n & 1)
	{
		printf("%d\n", (n + 1) / 2);
		for (int i = 0; i <= n / 2; i++)
			printf("%d ", i);
	}
	else
	{
		if (n == 2 || n == 4) puts("-1");
		else
		{
			printf("%d\n", n / 2);
			for (int i = 0; i <= n / 2 - 2; i++)
				printf("%d ", i);
			printf("%d", n / 2);
		}
	}
	return 0;
}

