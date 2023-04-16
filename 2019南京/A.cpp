#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T, n;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        printf("%d\n", (n + 1) / 2 + 1);
    }
    return 0;
}