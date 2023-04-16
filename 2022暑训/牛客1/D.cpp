#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9, pi = acos(-1);
int T;
double r, d;

struct Point
{
    double x,y;
    Point () {}
    Point (double xx,double yy) {x=xx; y=yy;}
    void input() {scanf("%lf%lf",&x,&y);}
    void output()
    {
        cout<<x<<" "<<y<<endl;
    }
}a;

double dis(Point t)
{
    return sqrt(t.x * t.x + t.y * t.y);
}

double work(Point t)
{
    double l = dis(t);
    //cout<<l<<" "<<r<<" "<<acos(l / r)<<endl;
    return acos(l / r);
}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lf", &r);
        scanf("%lf%lf%lf", &a.x, &a.y, &d);

        double len = dis(a);

        double dx, dy;
        if (len < eps) dx = d, dy = 0; //Q点就是原点
        else dx = a.x / len * d, dy = a.y / len * d;

        Point p = Point(a.x - dx, a.y - dy);
        Point q = Point(a.x + dx, a.y + dy);
        //p.output(); q.output();

        double a1, a2;
        if (fabs(q.x) < eps && fabs(q.y) < eps) swap(p, q); //一个点在原点
        if (fabs(p.x) < eps && fabs(p.y) < eps)
        {
            a1 = acos((2 * d) / r);
            a1 = pi / 2 - a1;
        }
        else
        {
            a1 = work(p), a2 = work(q);
            if (q.x * p.x < 0 || q.y * p.y < 0) a1 = pi - a1 - a2; //分别在左右两边
            else {a1 = fabs(a1 - a2);}
        }
        printf("%.8lf\n", r * a1);

    }
    return 0;
}
/*
4
2
0 0 1

4
0 2 1

2
0 1 1

2 
1 0 1

*/