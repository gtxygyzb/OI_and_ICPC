#include <bits/stdc++.h>
using namespace std;
int main()
{
    srand(time(0));
    int T = 100;
    printf("%d\n", T);
    while (T--)
    {
        int n = 500, m1 = 1000, m2 = 1000;
        printf("%d %d %d\n", n, m1, m2);
        for (int i = 1; i <= m1; i++)
        {
            printf("%d %d %d\n", rand()% n + 1, rand()%n + 1, rand()% 2 );
        }
        for (int i = 1; i <= m2; i++)
        {
            printf("%d %d\n", rand()% n + 1, rand()%n + 1);
        }
    }
    return 0;
}