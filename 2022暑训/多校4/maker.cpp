#include <bits/stdc++.h>
using namespace std;
int main()
{
    srand(time(0));
    int T = 12;
    printf("%d\n", T);
    while (T--)
    {
        int n = 1e4, m = 1e5;
        printf("%d %d\n", n, m);
        for (int i = 1; i <= m; i++)
        {
            printf("%d %d %lld %lld\n", rand() % n + 1, rand() % n + 1, 1LL * rand() * rand(), 1LL * rand() * rand());
        }
    }
}