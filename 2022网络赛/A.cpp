#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x, y, v, flag = 0;
    scanf("%d%d%d", &x, &y, &v);
    if (v < 0) return 0*puts("NO");
    for (int i = 0; i <= 10000 && !flag; i++)
    {
        int j = v ^ i;
        if (i * i + j * j == x * x + y * y)
            flag = 1;
    }
    puts(flag ? "YES" : "NO");
    return 0;
}