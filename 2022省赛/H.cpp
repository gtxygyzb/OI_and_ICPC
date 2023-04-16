#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 50;
int n, a[N], qc[N], cnt[N], d[N], g[N], m;
int ans;

int workmi()
{
	
	int f = 1;
	int x = a[n] % a[1];
	for (int i = 1; i < n; i++)
		if (a[n] % a[i] != x) f = 0;
	if (f) return n - 1;
	
	f = 1;
	for (int i = 2; i <= n - cnt[qc[m]] && f; i++)
		if (a[n] % a[i] != a[n] % a[i - 1]) f = 0;
	if (f) return n - cnt[qc[m]];
	
	
	
	for (int i = n - 2; i >= cnt[a[1]]; i--)
	{
		if (a[i] != a[i + 1])
		{
			int gg = g[i + 1];
			int lim = sqrt(gg); //前面所有数是g[i]的因数 
			int tot = 0, flag = 1;
			for (int j = 1; j <= lim; j++)
				if (gg % j == 0)
				{
					int u = j;
					if (cnt[u] && u <= a[i])
					{
						if (a[n] % u != x) {flag = 0; break;}
						tot += cnt[u];
					}
					if (j * j == gg) continue;
					u = gg / j;
					if (cnt[u] && u <= a[i])
					{
						if (a[n] % u != x) {flag = 0; break;}
						tot += cnt[u];
					}
				}
			if (flag && tot == i) return i;
		}
	}
	return 0;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", a+i);
		++cnt[a[i]];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		qc[i] = a[i];
		if (i < n) d[i] = a[i + 1] - a[i];
	}
	m = unique(qc + 1, qc + n + 1) - qc - 1;
	if (m == 1) {printf("%d\n", n - 1); return 0;} //所有数相同 
	/*if (m == 2)
	{printf("%d\n", max(cnt[qc[1]], cnt[qc[2]])); return 0;
	} //只有两种数值，选最多的 */
	
	g[n - 1] = d[n - 1];
	for (int i = n - 2; i >= 1; i--)
	{
		if (d[i] == 0) g[i] = g[i + 1];
		else g[i] = __gcd(d[i], g[i + 1]);
	}
	
	ans = n - cnt[qc[1]]; //n-最小值个数
	//cout<<"n-min:"<<ans<<endl;
	printf("%d\n", max(n - cnt[qc[1]], workmi()));
	return 0;
}
/*
8
4 4 4 8 8 8 9 9
*/
