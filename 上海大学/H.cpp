#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;
int n, m, k, a[N], b[N];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 0; i < n; i++)
			scanf("%d", a+i);
		int st = -1;
		for (int i = 0; i < n; i++)
			if (a[i] != a[(i - 1 + n) % n]) st = i;
		if (st == -1) //所有数都相同
		{
			printf("%d\n", (n + k - 1) / k);
			continue;
		}
		//cout<<"st:"<<st<<endl;
		int len = 0, pos, mx = 0;
		for (int cs = 1, i = st; cs <= n; i = (i + 1) % n, cs++)
		{
			if (a[i] != a[(i - 1 + n) % n])
			{
				if (len > mx)
				{
					mx = len;
					pos = i;
				}
				len = 1;
			}
			else ++len;
			//cout<<"i:"<<i<<" "<<len<<" "<<mx<<endl;
		}
		if (len > mx)
		{
			mx = len;
			pos = st;
		}
		if (mx < k)
		{
			puts("-1");
			continue;
		}
		int ans = (mx + k - 1) / k;
		//cout<<"ans:"<<ans<<" "<<len<<" "<<pos<<endl;
		len = 0;
		for (int cs = 1, i = pos; cs <= n; i = (i + 1) % n, cs++)
		{
			if (a[i] != a[(i - 1 + n) % n])
			{
				ans += (len + k - 1) / k;
				len = 1;
			}
			else ++len;
		}
		printf("%d\n", ans);
	}
	return 0;
}

