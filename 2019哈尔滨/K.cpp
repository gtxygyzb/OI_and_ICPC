#include <bits/stdc++.h>
using namespace std;
typedef double ld;
const int N = 1e6 + 50;
int n;
double k, a[N];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%lf", &n, &k);
		double sum = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%lf", &a[i]);
			sum += a[i];
		}
		for (int i = 1; i <= n; i++)
			printf("%.8lf ", a[i] + k * a[i] / sum);
		puts("");
	}
	return 0;
}
/*
3
1 1
2
2 2
1 3
3 2
1 1 1
*/
