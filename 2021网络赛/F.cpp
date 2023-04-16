#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5+50;
char s[N], ans[N];

bool cmp(int a[], int b[])
{
	int f;
	for (int i = 0; i < 26; i++)
		if (a[i]) f = i;
	for (int i = 0; i < f; i++)
		if (b[i]) return 0;
	return 1;
}

void work(int st, int ed, int m)
{
	if (ed - st == m)
	{
		for (int i = st; i < ed; i++)
			ans[i] = s[i];
	}
	else if (m == 1)
	{
		for (int i = st; i < ed; i++)
			ans[i] = s[i];
		sort(ans + st, ans + ed);
	}
	else
	{
		int pos = st + 1, a[26] = {0}, b[26] = {0};
		++a[s[st] - 'a']; 
		for (int i = pos; i <= ed - m; i++)
			++b[s[i] - 'a'];
		while (cmp(a, b) == 0 && ed - pos >= m)
		{
			--b[s[pos] - 'a'];
			++a[s[pos] - 'a'];
			++pos;
		}
		for (int i = st; i < pos; i++)
			ans[i] = s[i];
		sort(ans + st, ans + pos);
		work(pos, ed, m-1);
	} 
}

int main()
{
	int T, n, m;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%s", &n, &m, s);
		for (int i = 0; i <= n; i++)
			ans[i] = 0;
		work(0, n, m);
		printf("%s\n", ans);
	}
	return 0;
}
/*
4
4 1
dbca
4 2
dbca
4 3
dbca
5 3
dbcae
*/
