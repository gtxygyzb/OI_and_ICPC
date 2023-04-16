#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef vector <int> Vec;
typedef pair <int, int> pa;
const int N = 1e6 + 50, L = 20, P = 1e8 + 7;

int bin[L];

void prework()
{
	bin[0] = 1;
	for (int i = 1; i <= 18; i++)
		bin[i] = bin[i - 1] << 1;
}
int m, n;
pa query(int l, int r)
{
	int cur = 0, i = m - 1;
	/*for (int x = l, cs = 0; cs < m; cs++, x >>= 1)
		cout<<(x & 1);
	puts("");
	for (int x = r, cs = 0; cs < m; cs++, x >>= 1)
		cout<<(x & 1);
	puts("");*/
	for (; ~i; i--)
		if ((l >> i) != (r >> i)) break;
		else
		{
			if (l & bin[i])
				cur += bin[i];
		}
	return pa(cur, cur + bin[i + 1] - 1);
}
int l[N], r[N], st[N], ed[N];
int main()
{
	prework();
	/*for (int i = 0; i <= 6; i++)
	{
		pa ans = query(i, i + 1);
		cout<<ans.fi<<" "<<ans.se<<endl;
	}*/
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &m, &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d", &l[i], &r[i]);
			st[i] = l[i]; ed[i] = r[i];
		}
		for (int i = 2; i <= n; i++)
		{
			pa cur = query(r[i - 1], l[i]);
			//cout<<"query:"<<r[i - 1]<<" "<<l[i]<<" "<<cur.fi<<" "<<cur.se<<endl;
			st[i] = max(st[i], cur.fi);
			ed[i] = min(ed[i], cur.se);
			
			st[i - 1] = max(st[i - 1], cur.fi);
			ed[i - 1] = min(ed[i - 1], cur.se);
		}
		int flag = 1, ans = 1;
		for (int i = 1; i <= n; i++)
		{
			//cout<<st[i]<<" "<<ed[i]<<" "<<1ll * (st[i] + ed[i]) * (ed[i] - st[i] + 1) / 2<<endl;
			if (st[i] > ed[i]) flag = 0;
			ll sum = 1ll * (st[i] + ed[i]) * (ed[i] - st[i] + 1) / 2 % P;
			ans = 1ll * ans * sum % P;
		}
		if (!flag) puts("0");
		else printf("%d\n", ans);
	}
	return 0;
}
/*
1
10 4
0 2
3 511
512 1000
1001 1023
*/
