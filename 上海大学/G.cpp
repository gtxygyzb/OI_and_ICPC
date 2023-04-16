#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	int b, r, d, s;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d%d", &b, &r, &d, &s);
		int dmg;
		if (r) dmg = b * ((r * s + 60) / 60);
		else dmg = 0;
		//cout<<"dmg:"<<dmg<<endl;
		puts(d > dmg ? "gua!" : "ok");
	}
	return 0;
}

