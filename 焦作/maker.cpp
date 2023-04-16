#include <bits/stdc++.h>
using namespace std;
int main()
{
    srand(time(0));
    int T = 5;
    printf("%d\n", T);
    while (T--)
    {
        int n = rand() * rand() % 200000 + 1;
        printf("%d\n", n);
        for (int i = 1; i <= n; i++)
            printf("%d ", rand() * rand() % 1000 + 1);
        puts("");
    }
}