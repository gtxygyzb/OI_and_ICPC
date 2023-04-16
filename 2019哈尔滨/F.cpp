#include <bits/stdc++.h>
using namespace std;
string s;
int n, a[10][10], p[10];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin>>T;
	while (T--)
	{
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= 6; i++)
		{
			cin>>s;
			n = s.size();
			for (int j = 0; j < n; j++)
			{
				if (s[j] == 'h') a[i][1] = 1;
				if (s[j] == 'a') a[i][2] = 1;
				if (s[j] == 'r') a[i][3] = 1;
				if (s[j] == 'b') a[i][4] = 1;
				if (s[j] == 'i') a[i][5] = 1;
				if (s[j] == 'n') a[i][6] = 1;
			}
			p[i] = i;
		}
		int ans = 0;
		do
		{
			int flag = 1;
			for (int i = 1; i <= 6 && flag; i++)
				if (a[p[i]][i] == 0) flag = 0;
			if (flag) {ans = 1; break;}
		}while(next_permutation(p + 1, p + 6 + 1));
		printf(ans ? "Yes\n" : "No\n");
	}
	return 0;
}
/*
3
welcome
toparticipate
inthe
ccpccontest
inharbin
inoctober
harvest
belong
ninja
reset
amazing
intriguing
a
b
c
d
e
f
*/
