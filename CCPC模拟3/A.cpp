#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int n, x, t;
ull ans1, ans2;
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &n, &x, &t);
        ans1 = 1LL * 2 * n * t;
        if (x > ans1 - t - t) ans1 += x - (ans1 - t - t);
        ans1 += 1LL * 2 * n * t;

        ans2 = 1LL * 2 * n * t;
        ans2 += t;
        if (x > ans2 - t) ans2 += x - (ans2 - t);
        ans2 += 1LL * 2 * n * t;
        cout<<min(ans1, ans2)<<endl;
    }
    return 0;
}
/*
3
2 2 2
3 1 10
11 45 14
*/