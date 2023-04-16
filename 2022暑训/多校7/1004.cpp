#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T, e, l, r, b;
    int ans1, ans2;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d%d", &e, &l, &r, &b);
        if (l == 0 && r == 0)
        {
            ans1 = e + min(b, 1);
            ans2 = min(e + b, e + e + 1);
        }
        else
        {
            ans1 = e + max(l, r);
            ans2 = l + r + e + min(b, e + 1);
        }
        printf("%d %d\n", ans1, ans2);
    }
    return 0;
}