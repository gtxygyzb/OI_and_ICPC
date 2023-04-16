#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 50, L = 25;
int n, k, zs;
ll a[N], b[L], bin[L], sum, d[L];

int check(ll ans)
{
	priority_queue <ll> q;
	for (int i = 0; i < k; i++)
		d[i] = b[i];
	for (int i = 1; i <= n; i++)
		q.push(a[i] * ans);
	//cout<<q.size()<<endl;
	int tk = k - 1, cc = 0;
	//cout<<tk<<" \n;";
	while (!q.empty() && tk >= 0)
	{
		ll u = q.top(); q.pop();
		//printf("u: %lld\n", u);
		++cc;
		ll mx = min(d[tk], u / bin[tk]);
		if (u < bin[tk]) mx = 1;
		u -= mx * bin[tk];
		d[tk] -= mx;
		if (u > 0) q.push(u);
		while (tk >= 0 && d[tk] == 0) --tk;
	}
	//cout<<"cc:"<<cc<<endl;
	zs += cc;
	return q.empty();
}

int main()
{
	bin[0] = 1;
	for (int i = 1; i <= 20; i++)
		bin[i] = bin[i - 1] * 2;
		
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &k);
		ll ans = 0, sa = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%lld", &a[i]);
			sa += a[i];
		}
		ll l = 0, r = 0;
		for (int i = 0; i < k; i++)
		{
			scanf("%lld", &b[i]);
			r += b[i] * bin[i];
		}
		sum = r;
		r /= sa;
		//cout<<l<<" "<<r<<endl; 
		while (l <= r)
		{
			ll mid = l + r >> 1;
			if (check(mid)) ans = mid, l = mid + 1;
			else r = mid - 1;
		}
		printf("%lld\n", ans);
		//cout<<zs<<endl;
	}
	return 0;
}
/*
1
3 5
3 1 1
1 1 1 1 1
*/
