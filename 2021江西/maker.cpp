#include <bits/stdc++.h>
using namespace std;
int main()
{
    srand(time(0));
    int T = 10;
    printf("%d\n", T);
    while (T--)
    {
        int n = 5000, m = 5000;
        printf("%d %d\n", n, m);
        for (int i = 1; i <= n; i++)
            printf("%d ", 1ll * rand() * rand() % 1000000 + 1);
        puts("");
        for (int i = 1; i <= m; i++)
        {
            int l = rand() % n + 1, r = rand() % n + 1;
            if (l > r ) swap(l, r);
            printf("%d %d\n", l, r);
        }
    }
    return 0;
}