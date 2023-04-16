#include <bits/stdc++.h>
using namespace std;
int main()
{
	srand(time(0));
	int n = rand()%3 + 2;
	printf("%d\n", n);
	for (int i = 1; i <= n; i++)
		printf("%d ", rand() % 3 + 1);
	return 0;
}

