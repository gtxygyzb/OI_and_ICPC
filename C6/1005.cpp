#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
int n, m;
int a[N], b[N], c[N];
bool check(int l, int r)
{
	memcpy(c, a, sizeof(int)*(m+5));
	for (int i = l; i <= r; i++)
		c[i] = a[i];
	int st = l, ed = r;
	while (l != r)
	{
		while (c[l] == 0 && l < r) ++l;
		while (c[r] == 0 && l < r) --r;
		if (l == r)
		{
			if (c[l] <= l - st) return 1;
			if (l == 1) return 0;
			if (r == ed) return 0;
			else
			{
				int tmp = 0, pos = l, cs = 0;
				while (r < ed && c[l])
				{
					++r;
					while (a[r] == 0 && r < ed) ++r;
					if (a[r] == 0) break;
					int del = min(c[l], a[r] -1);
					if (a[r] - 1 <= c[l])
						tmp += a[r];
					else tmp += c[l] + 1;
					c[l] -= del;
					++cs;
				}
				//cout<<tmp<<" "<<l<<" "<<r<<" "<<c[l]<<" "<<cs<<endl;
				while (tmp)
				{
					if (l == 1)
					{
						if (tmp > cs)
							return 0;
						break;
					}
					--l;
					int del = min(tmp, a[l]);
					//cout<<"del:"<<l<<" "<<del<<" "<<tmp<<endl;
					tmp -= del;
					c[l] += del;
				}
				/*for (int i = l; i <= pos; i++)
					cout<<c[i]<<" ";
				puts("");
				cout<<l<<" "<<pos<<endl;*/
				for (int i = l; i <= pos; i++)
					a[i] = c[i];
				return check(l, pos);
			}
		}
		if (c[l] < c[r])
		{
			c[r] -= c[l];
			c[l] = 0;
		}
		else
		{
			c[l] -= c[r];
			c[r] = 0;
		}
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= m; i++)
			scanf("%d", b+i);
		sort(b + 1, b + m + 1);
		for (int i = 1; i <= m; i++)
			a[i] = b[i] - b[i - 1] - 1;
		a[m + 1] = n - b[m];
		puts(check(1, m + 1) == 1 ? "Yes" : "No");
	}
	return 0;
}