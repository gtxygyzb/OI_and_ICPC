#include <bits/stdc++.h>
using namespace std;
int main()
{
	srand(time(0));
	int T = 6;
	printf("%d\n", T);
	while (T--)
	{
		int x = rand() % 3;
		for (int i = 0; i < 40; i++)
			printf("%d", rand() % 1);
		puts("");
	}
	return 0;
}

