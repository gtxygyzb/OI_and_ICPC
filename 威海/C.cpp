#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pa;
const int N = 1e6 + 50;
struct Point
{
	ll x, y;
	Point(ll _x=0, ll _y=0) {x = _x; y = _y;}
	void input() {scanf("%lld%lld", &x, &y);}
	void output() {printf("%lld %lld\n", x, y);}
	Point operator -(const Point &t) const
	{
		return Point(x - t.x, y - t.y);
	}
	ll operator ^(const Point &t) const
	{
		return x * t.y - y * t.x;
	}
	bool operator ==(const Point &t) const
	{
		return x == t.x && y == t.y;
	}
}a[N];
int check(Point x, vector <Point> vec) //vec内是否存在与x不共线的，此时vec内的点一定都共线 
{
	//x.output(); vec[0].output(); vec[1].output();
	//cout<<"cross: "<<((x - vec[0]) ^ (x - vec[1]))<<endl;
	return ((x - vec[0]) ^ (x - vec[1])) != 0;
}
Point chose(vector <Point> vec)
{
	for (auto &u : vec)
	{
		int flag = 1;
		map <pa, bool> mp;
		for (auto &v : vec)
		{
			if (u == v) continue;
			ll dx = v.x - u.x, dy = v.y - u.y;
			ll g = __gcd(abs(dx), abs(dy));
			dx /= g; dy /= g;
			if (mp[pa(dx, dy)]) {flag = 0; break;}
			mp[pa(dx, dy)] = 1;
		}
		if (flag) return u;
	}
	return Point(-114514, -114514);
}
int n;
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)	
			a[i].input();
		vector <Point> p;
		p.push_back(a[1]); 
		p.push_back(a[2]);
		int cnt = 2, flag = 0;
		for (int i = 3; i <= n && cnt <= 4; i++)
		{
			if (cnt == 4)
			{
				if (flag) {p.push_back(a[i]); ++cnt;}
				else if (check(a[i], p))
				{
					p.push_back(a[i]); ++cnt;
					flag = 1;
				}
			}
			else
			{
				flag |= check(a[i], p);
				p.push_back(a[i]);
				++cnt;
			}	
		}
		if (cnt <= 4) puts("NO");
		else
		{
			puts("YES");
			Point A = chose(p);
			A.output();
			for (auto &u : p)
				if (!(A == u))
					u.output();
		}
	}
	return 0;
}
/*
1000
5
0 0
1 1
1 -1
-1 1
-1 -1
3
1 1
4 5
1 4
5
1 0
2 0
3 0
4 0
5 0
*/
