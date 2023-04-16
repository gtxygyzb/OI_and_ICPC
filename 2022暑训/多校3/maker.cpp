#include <bits/stdc++.h>
using namespace std;
int main()
{
    srand(time(0));
    int T = 10;
    printf("%d\n", T);
    while (T--)
    {
        int n = 100000, k = rand() % rand() + 1;
        printf("%d %d\n", n, k);
        for (int i = 1; i <= n; i++)
        {
            int l = rand() % 1000 + 1, r = rand() % 1000 + 1;
            printf("%d %d\n", l, r);
        }
            
    }
    return 0;
}