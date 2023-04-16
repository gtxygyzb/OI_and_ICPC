#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 50;
const double pi = acos(-1), eps = 1e-10;

int dcmp(double x)
{
	if (fabs(x) < eps)
		return 0;
	return x < 0 ? -1 : 1;
}

struct point
{
	double x, y;
	point(double x = 0, double y = 0) :x(x), y(y) {}
    void input() {scanf("%lf%lf", &x, &y);}
};
point operator + (point a, point b)
{
	return point(a.x + b.x, a.y + b.y);
}
point operator - (point a, point b)
{
	return point(a.x - b.x, a.y - b.y);
}
bool operator == (const point& a, const point& b)
{
	return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;
}
double dot(point a, point b)
{
	return a.x * b.x + a.y * b.y;
}
double length(point a)
{
	return sqrt(dot(a, a));
}


struct circle
{
	point c;
	double r;
    circle () {}
	circle(point c, double r) :c(c), r(r) {}
	point Point(double a) // 由角度求圆上点
	{
		return point(c.x + cos(a) * r, c.y + sin(a) * r);
	}
    void input() {c.input(); scanf("%lf", &r);}
}a[N];

int getccjiao(circle C1, circle C2, vector<point>& ans)
{
    double d = length(C1.c - C2.c);
    if (dcmp(d) == 0)
	{
		if (dcmp(C1.r - C2.r) == 0)	// 重合
			return -1;
		return 0;	// 包含
	}
    if (dcmp(C1.r + C2.r - d) < 0) // 相离
		return 0;
	if (dcmp(fabs(C1.r - C2.r) - d) > 0) // 包含
		return 0;
	double a = atan2((C2.c - C1.c).y, (C2.c - C1.c).x);
	double da = acos((C1.r * C1.r + d * d - C2.r * C2.r) / (2 * C1.r * d));
	point p1 = C1.Point(a - da), p2 = C1.Point(a + da);
	ans.push_back(p1);
	if (p1 == p2) // 相切
		return 1;
	ans.push_back(p2); // 相交
	return 2;
}

int n;
int main()
{
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; i++)
            a[i].input();
        double ans = 2 * pi * a[n].r;
        for (int i = n - 1; i >= 1; i--)
        {
            vector <int> vec;
            for (int j = i + 1; j <= n; j++)
                int flag = getccjiao;
        }
    }
    return 0;
}