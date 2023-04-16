#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 4e6 + 50;
ll sum[N];
int n, bi;
void init(ll x)
{
	bi = 1;
	while (bi < x) bi <<= 1;
	for (ll i = 1; i <= bi; i++)
	{
		sum[i] = (__gcd((i * x) ^ x, x) == 1);
		sum[i] += sum[i - 1];
	}
}
ll calc(ll x)
{
	ll di = x / bi, res = x % bi;
	//cout<<bi<<" "<<di<<" "<<res<<endl;
	return sum[bi] * di + sum[res];
}
ll x;
int main()
{
	scanf("%lld%d", &x, &n);
	if (x & 1) init(x);
	for (ll l, r; n--; )
	{
		scanf("%lld%lld", &l, &r);
		if (x & 1)
			printf("%lld\n", calc(r) - calc(l - 1));
		else puts("0");
	}
	return 0;
}
/*
482979 10
1590 14861
30270 30540
21667 24389
19166 19274
1674 3921
20476 23907
19633 27462
19911 23261
1255 28957
24214 29740
*/
