#include <bits/stdc++.h>
using namespace std;
int main()
{
    srand(time(0));
    int n = 6000;
    printf("%d\n", n);
    while (n--)
    {
        for (int i = 1; i <= rand() % 2000 + 1; i++)
            putchar((char)('a' + rand() % 20));
        puts("");
    }
    return 0;
}
