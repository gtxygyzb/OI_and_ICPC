#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x;
int main()
{
	int n;
	scanf("%lld%d", &x, &n);
	for (ll l, r; n--;)
	{
		scanf("%lld%lld", &l ,&r);
		ll ans = 0;
		for (ll k = l; k <= r; k++)
		{
			if (__gcd((k * x) ^ x, x) == 1) ++ans;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

