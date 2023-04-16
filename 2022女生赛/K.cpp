#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
	int n, ans = 0;
	scanf("%d", &n); getchar();
	for (int i = 1; i <= n; i++)
	{
		getline(cin, s);
		for (int j = 1; j <= 4; j++)
			if (s[j] == '-') ++ans;
	}
	cout<<ans;
	return 0;
}

