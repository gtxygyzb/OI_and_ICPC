#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m;
ll power(ll x, ll k)
{
	ll ret = 1;
	for (; k; k >>= 1, x = x * x)
		if (k & 1) ret = ret * x;
	return ret;
}
int main()
{
	scanf("%lld%lld", &n, &m);
	return 0;
}
