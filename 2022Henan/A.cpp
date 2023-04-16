#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	if (n == 1) puts("1");
	else if (n == 2) puts("10");
	else
	{
		if (n > 10) puts("-1");
		else
		{
			printf("10");
			for (int i = 2; i <= n - 1; i++)
				printf("%d", i);
		}
	}
	return 0;
}
