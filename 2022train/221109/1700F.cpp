#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 50;
int n, a[3][N], b[3][N], cnt;
ll ans;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= 2; i++)
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &a[i][j]);
			cnt += a[i][j];
		}
	for (int i = 1; i <= 2; i++)
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &b[i][j]);
			cnt -= b[i][j];
		}
	if (cnt) return 0 * puts("-1");
	int sum1 = 0, sum2 = 0;
	for (int j = 1; j <= n; j++)
	{
		sum1 += a[1][j] - b[1][j];
		sum2 += a[2][j] - b[2][j];
		//cout<<sum1<<" ,"<<sum2<<" "<<a[1][j] <<" "<< b[1][j]<<" "<<a[2][j] <<" "<< b[2][j]<<endl;
		if (sum1 < 0 && sum2 > 0)
		{
			int mi = min(-sum1, sum2);
			sum1 += mi;
			sum2 -= mi;
			ans += mi;
		}
		if (sum1 > 0 && sum2 < 0)
		{
			int mi = min(sum1, -sum2);
			sum2 += mi;
			sum1 -= mi;
			ans += mi;
		}
		//cout<<j<<" "<<sum1<<" "<<sum2<<endl;
		ans += abs(sum1) + abs(sum2);
	}
	printf("%lld\n", ans);
	return 0;
}
