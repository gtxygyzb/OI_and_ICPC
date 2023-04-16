#include <bits/stdc++.h>
using namespace std;

/*struct Complex
{
    double x, y;
    Complex () {}
    Complex (double _x, double _y) {x = _x; y = _y;}
    void input() {scanf("%lf%lf", &x, &y);}
    Complex operator +(const Complex &t) const
    {
        return Complex(x + t.x, y + t.y);
    }
    Complex operator -(const Complex &t) const
    {
        return Complex(x - t.x, y - t.y);
    }
    Complex operator *(const Complex &t) const
    {
        return Complex(x * t.x - y * t.y, x * t.y + y * t.x);
    }
    Complex operator /(const Complex &t) const
    {
        double f = t.x * t.x + t.y * t.y;
        Complex tmp(t.x, -t.y);
        Complex ret = (*this) * tmp;
        return Complex(ret.x / f, ret.y / f);
    }
}z1, z2, z3, w1, w2, w3;*/
const double eps = 1e-10;
complex <double> z1, z2, z3, w1, w2, w3, z, a, b, d, w;
void read(complex <double> &t)
{
    double p, q;
    scanf("%lf%lf", &p, &q);
    t.real(p); t.imag(q);
}
double len(complex <double> x)
{
    return sqrt(x.imag() * x.imag() + x.real() * x.real());
}
void work()
{
    a = (w1 - w2) / (z1 - z2);
    b = w1 - a * z1;
    if (len(a * z3 + b - w3) < eps)
    {
        w = a * z + b;
        printf("%.10lf %.10lf\n", w.real(), w.imag());
        return ;
    }
    complex <double> fm = z1*(-w3) + z3*(-w2) + z2*(-w1) + z3*w1 + z2*w3 + z1*w2;
    a = (w1*z1*(-w3) - w2*w3*z3 - w1*w2*z2 + w1*w3*z3 + w2*w1*z1 + w3*w2*z2 ) / fm;
    d = (z1*w3*z3 + z2*w1*z1 + z3*w2*z2 - z3*w1*z1 - z1*w2*z2 - z2*w3*z3) / fm;
    b = w1*z1 + d*w1 - a*z1;
    w = (a * z + b) / (z + d);
    printf("%.10lf %.10lf\n", w.real(), w.imag());
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        read(z1); read(w1);
        read(z2); read(w2);
        read(z3); read(w3);
        read(z);
        work();
    }
    return 0;
}
/*
2
-1 0 0 -1
0 1 -1 0
1 0 0 1
0 -1
-1 0 -1 0
0 1 0 -1
1 0 1 0
0 -1
*/