#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int main()
{
    scanf("%d%d%d", &a, &b, &c);
    if (a == 1 && !b && !c) puts("YES\n0");
    else
    {
        if (a <= b + c) puts("NO");
        else
        {
            puts("YES");
            printf("%d\n", 2 * (b + c) + 1);
        }
    }
    return 0;
}