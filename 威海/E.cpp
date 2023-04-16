#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;
int a[N];
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	int pos = -1;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] < k && pos == -1)
			pos = i;
	}
	if (~pos)
		printf("Python 3.%d will be faster than C++\n", pos);
	else
	{
		if (a[n] >= a[n - 1])
			puts("Python will never be faster than C++");
		else
		{
			int ans = n;
			while(1)
			{
				++ans;
				a[ans] = max(0, 2 * a[ans - 1] - a[ans - 2]);
				if (a[ans] < k)
				{
					printf("Python 3.%d will be faster than C++\n", ans);
					break;
				}
			}
		}
	}
	
	return 0;
}
/*
10 1000
11 45 14 19 19 8 10 13 10 11
*/
