#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 5050;
const ull seed = 13331;

int n, q, que[N][N], a[N];

ull lru[N][N];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &q);
		int len = 0;
		for (int x, i = 1; i <= n; ++i)
		{
			memcpy(que[i], que[i - 1], (n + 1) * sizeof(int));
			scanf("%d", &x);
			int pos = 0;
			for (int j = 1; j <= len; ++j)
				if (que[i][j] == x)
					pos = j;
			for (int j = (pos ? pos : ++len); j; --j)
				que[i][j] = que[i][j - 1];
			que[i][1] = x;
			for (int j = 1; j <= n; j++)
			{
				//cout<<que[i][j]<<" ";
				lru[i][j] = lru[i][j - 1] * seed + que[i][j];
			}
			//puts("");
		}
		for (int m; q--;)
		{
			scanf("%d", &m);
			ull cur = 0;
			for (int i = 1; i <= m; i++)
			{
				scanf("%d", &a[i]);
				cur = cur * seed + a[i];
			}
			//cout<<cur<<endl;
			int suc = 0;
			for (int i = 0; i <= n; i++)
			{
				//cout<<"i: "<<lru[i][m]<<endl;
				if (lru[i][m] == cur)
				{
					int flag = 1;
					for (int j = 1; j <= m && flag; j++)
						if (que[i][j] != a[j])
							flag = 0;
					if (flag) {suc = 1; break;}
				}
			}
			puts(suc ? "Yes" : "No");
		}
	}
	return 0;
}

