#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+50;
int T, ans;
char ch[N];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", ch+1);
		int len = strlen(ch+1);
		ch[len+1] = '0';
		ans = 0;
		for (int i=1;i<=len+1;i++)
		{
			if (ch[i]=='0'&&ch[i-1]=='1')
				++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}

