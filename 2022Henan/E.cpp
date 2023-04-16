#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 50;
char s[N], ans[20];
int n, cnt[26], l = N - 50, r, pos[26], nxt[N];
int main()
{
	scanf("%d%s", &n, s);
	for (int i = 0; i < n; i++)
	{
		++cnt[s[i] - 'a'];
		if (cnt[s[i] - 'a'] >= 5)
		{
			l = i + 1;
			for (int j = 0; j < 5; j++)
				ans[j] = s[i];
			break;
		}
	}
	memset(cnt, 0, sizeof(cnt));
	for (int i = n - 1; ~i; i--)
	{
		++cnt[s[i] - 'a'];
		if (cnt[s[i] - 'a'] >= 5)
		{
			r = i - 1;
			for (int j = 16; j >= 12; j--)
				ans[j] = s[i];
			break;
		}
	}
	int flag = 0;
	for (int i = 0; i < 26; i++) pos[i] = n;
	nxt[n] = n;
	for (int i = n - 1; ~i; i--)
	{
		nxt[i] = pos[s[i] - 'a'];
		pos[s[i] - 'a'] = i;
	}
	for (int i = l; i <= r; i++)
	{
		int u = i;
		for (int j = 1; j <= 6; j++)
			u = nxt[u];
		if (u <= r)
		{
			for (int j = 5; j <= 11; j++)
				ans[j] = s[i];
			flag = 1;
			break;
		}
	}
	printf("%s\n", flag ? ans : "none");
	return 0;
}
/*
64
aayraeqeqaaartusiowuozzjlfjalfjlazzzfdsafazzbbbfdsjalfjslfjljobb
*/
