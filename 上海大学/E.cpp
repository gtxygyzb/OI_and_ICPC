#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;
char s[N], f[N];
int pos[38], n, m, nxt[N][38];
int num(char c)
{
	if (c >= '0' && c <= '9') return c - '0';
	return c - 'a' + 10;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s%s", s, f);
		n = strlen(s);
		m = strlen(f);
		int ans = 1e9, ap;
		for (int i = 0; i < 36; i++)
		{
			nxt[n][i] = n;
			pos[i] = n;
		}
		for (int i = n - 1; ~i; i--)
		{
			for (int j = 0; j < 36; j++)
				nxt[i][j] = pos[j];
			pos[num(s[i])] = i;
		}
		
		for (int i = 0; i < n; i++)
		{
			int u = i;
			int j = s[u] == f[0];
			for (; j < m && u < n; j++)
				u = nxt[u][num(f[j])];
			if (u >= n) continue;
			if (u - i + 1 < ans)
			{
				ans = u - i + 1;
				ap = i;
			}
		}
		//cout<<ap<<" "<<ans<<endl;
		for (int i = ap; i <= ap + ans - 1; i++)
			printf("%c", s[i]);
		puts("");
	}
	return 0;
}
/*
4
114514 15
shanghaicpc ac
aaabbbaaabbbccc abc
howdeliciousandfreshitis oishii
*/
