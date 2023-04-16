#include <bits/stdc++.h>
using namespace std;
double n, m, p;
double f(int i)
{
    return (n * i + m) / (1 - pow(1.0 - p, i));
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lf%lf%lf", &n, &m, &p);
        p *= 1e-4;
        int l = 1, r = 0x3f3f3f3f;
        while (l < r)
        {
            int m1 = l + (r - l) / 3;
            int m2 = r - (r - l) / 3;
            if (f(m1) < f(m2)) r = m2 - 1;
            else l = m1 + 1;
        }
        printf("%.6lf\n", f(l));
    }
    return 0;
}