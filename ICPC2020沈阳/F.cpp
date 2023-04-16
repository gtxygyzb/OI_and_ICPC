#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
const int N = 1e6 + 50;
const ull seed = 1e9 + 7;

int n, a[N], xu[N], ans;
ull b[N];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a+i);
        xu[i] = a[i];
    }
    sort(xu + 1, xu + n + 1);
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(xu + 1, xu + n + 1, a[i]) - xu;
    for (int i = 1; i <= n; i++)
        xu[i] = a[i];
    sort(xu + 1, xu + n + 1);


    b[0] = 1;
    for (int i = 1; i <= n; i++)
        b[i] = b[i - 1] * seed;

    ull ah = 0, ch = 0;
    for (int i = 1; i <= n; i++)
    {
        ah = ah + b[xu[i]];
        ch = ch + b[a[i]];
        if (ah == ch) ++ans;
    }
    printf("%d\n", ans);
    return 0;
}
/*
10
10 10 20 10 10 20 10 10 20 10
*/