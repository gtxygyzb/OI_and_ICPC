#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;
double x[N], y[N];
int n;

bool eq(double a, double b) {return fabs(a - b) < 1e-6;}
bool check(int i, int j)
{
    if (eq(x[i], x[j]) || eq(y[i], y[j])) return 1;
    if (eq(fabs(x[i] - x[j]), fabs(y[i] - y[j]))) return 1;
    return 0;
}

int getans(double xx, double yy)
{
    x[0] = xx; y[0] = yy;
    for (int i = 1; i <= n; i++)
        if (check(0, i) == 0) return 0;
    return 1;   
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%lf%lf", &x[i], &y[i]);
        int flag = 1, p;
        for (p = 2; p <= n; p++)
            if (!check(1, p)) {flag = 0; break;}
        if (flag) {puts("YES"); continue;}

        if (x[1] > x[p]) {swap(x[1], x[p]); swap(y[1], y[p]);}
        if (!flag && getans(x[p], y[1])) flag = 1;
        if (!flag && getans(x[1], y[p])) flag = 1;

        int dx = abs(x[p] - x[1]), dy = abs(y[p] - y[1]);

        if (!flag && getans(x[1], y[p] + dx)) flag = 1;
        if (!flag && getans(x[1], y[p] - dx)) flag = 1;

        if (!flag && getans(x[p], y[1] - dx)) flag = 1;
        if (!flag && getans(x[p], y[1] + dx)) flag = 1;

        if (!flag && getans(x[p] + dy, y[1])) flag = 1;
        if (!flag && getans(x[p] - dy, y[1])) flag = 1;

        if (!flag && getans(x[1] + dy, y[p])) flag = 1;
        if (!flag && getans(x[1] - dy, y[p])) flag = 1;
        
        if (!flag && getans((x[1] - y[1] + x[p] + y[p]) / 2, (y[1] - x[1] + x[p] + y[p]) / 2)) flag = 1;
        if (!flag && getans((x[p] - y[p] + x[1] + y[1]) / 2, (y[p] - x[p] + x[1] + y[1]) / 2)) flag = 1;


        puts(flag ? "YES" : "NO");
    }
    return 0;
}
/*
1
4
1 1
3 5
8 0
4 100
*/