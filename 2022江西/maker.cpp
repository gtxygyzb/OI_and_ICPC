#include <bits/stdc++.h>
using namespace std;
int main()
{
    srand(time(0));
    int n = 10000, q = 10000;
    printf("%d %d\n", n, q);
    while (q--)
    {
        int l = (rand() * rand()) % n + 1, r = (rand() * rand()) % n + 1;
        if (l > r) swap(l, r);
        int m = rand () % 20001 - 10000;
        if (rand() % 5 == 0) printf("0 %d %d\n", l, r);
        else printf("%d %d %d\n", m, l, r);
    }
    return 0;
}