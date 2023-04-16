#include <bits/stdc++.h>
using namespace std;
char c;
int a, b;
int main()
{
	while (c = getchar())
	{
		if (c == 'D') a++;
		if (c == 'T') b++;
		if (a == 3) return 0 * puts("DRX");
		if (b == 3) return 0 * puts("T1");
	}
	return 0;
}
