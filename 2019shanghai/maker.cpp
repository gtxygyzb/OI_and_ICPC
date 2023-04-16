#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll shu(ll x)
{
	return 1ll * rand() * rand() * rand() % (x + 1);
}
int main()
{
	srand(time(0));
	int T = 1;
	printf("%d\n", T);
	while (T--)
	{
		int n = 10000, m = 10000;
		ll f = 2000000000;
		printf("%d %d\n", n, m);
		for (int i = 1; i <= n; i++)
			printf("%lld ", shu(f));
		puts("");
		for (int op; m--;)
		{
			op = rand() % 3;
			if (op == 0) printf("Add %lld\n", shu(f));
			//if (op == 1) puts("Shift");
			if (op == 1) printf("Query %lld\n", shu(f));
			if (op == 2)
			{
				ll l = shu(f), r = shu(f);
				if (l > r) swap(l, r);
				printf("Sum %lld %lld\n", l, r);
			}
		}
	}
	return 0;
}

