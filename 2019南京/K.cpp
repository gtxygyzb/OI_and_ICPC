#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-12;
struct Point
{
    Point () {}
    Point (double _x, double _y) {x = _x; y = _y;}
    double x, y;
    void input() {scanf("%lf%lf", &x, &y);}
    double operator ^(const Point &t) const {return x * t.y - t.x * y;}
    double operator *(const Point &t) const {return x * t.x + y * t.y;}
    Point operator +(const Point &t) const
    {
        return Point(x + t.x, y + t.y);
    }
    Point operator -(const Point &t) const
    {
        return Point(x - t.x, y - t.y);
    }
    void output() {printf("%.10lf %.10lf\n", x, y);}
}a[4], p;
double as;
bool coline(Point p1, Point p2, Point p)
{
    if (fabs((p1 - p) ^ (p2 - p)) < eps)
        if ((p1 - p) * (p2 - p) < eps)
            return 1;
    return 0;
}
double area(Point p1, Point p2, Point p)
{
    return fabs(((p1 - p) ^ (p2 - p)) / 2.0);
}
double len(Point p1, Point p2)
{
    return sqrt((p1 - p2) * (p1 - p2));
}
int flag;
bool work(int i, int j, int k, Point p)
{
    if (!coline(a[i], a[j], p) || flag) return 0;
    int s1 = area(a[i], a[k], p);
    int s2 = area(a[j], a[k], p);
    if (s1 < s2) swap(i, j); //a[i],a[k]上找点ans，使得area(a[i],p,ans)为面积的一半
    Point l = a[i], r = a[k], ans;
    for (int cs = 1; cs <= 30; cs++)
    {
        ans = l + r;
        ans.x /= 2.0; ans.y /= 2.0;
        if (fabs(area(a[i], ans, p) - as) < eps) break;
        if (area(a[i], ans, p) < as) l = ans;
        else r = ans;
    }
    ans.output();
    return 1;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        for (int i = 1; i <= 3; i++)
            a[i].input();
        as = area(a[1], a[2], a[3]) / 2.0;
        p.input();
        flag = 0;
        flag |= work(1, 2, 3, p);
        flag |= work(1, 3, 2, p);
        flag |= work(2, 3, 1, p);
        if (flag == 0) puts("-1");
    }
    return 0;
}