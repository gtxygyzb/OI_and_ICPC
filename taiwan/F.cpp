#include <bits/stdc++.h>
using namespace std;
int n;
struct Data
{
	string s;
	double a;
	void input()
	{
		cin>>s;
		double q, w, e, r, t;
		scanf("%lf%lf%lf%lf%lf", &q, &w, &e, &r, &t);
		a = 0.56 * r + 0.24 * e + 0.14 * w + 0.06 * q + 0.3 * t;
	}
}d[10];
bool cmp(Data x, Data y)
{
	return x.a > y.a;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < 6; i++)
		d[i].input();
	sort(d, d + 6, cmp);
	int ans = n / 6;
	n %= 6;
	for (int i = 0; i < 6; i++)
		if (d[i].s == "Taiwan")
		{
			if (i + 1 <= n) ++ans;
			break;
		}
	cout<<ans;
	return 0;
}
/*
17
Japan 500 95 40 30 5
Vietnam 400 50 150 40 20
Indonesia 700 25 80 35 20
Taiwan 200 30 100 35 1
Korea 600 100 100 70 0
Philippines 50 10 40 15 15
*/
