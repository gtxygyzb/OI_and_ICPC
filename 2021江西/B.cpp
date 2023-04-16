#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;
int t[N], ans;
void gcd(int x, int y)
{
    t[++ans] = x / y;
    if (y == 1) return ;
    gcd(y, x % y);
}
int main()
{
    int T, x, y;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &x, &y);
        ans = 0;
        gcd(x, y);
        printf("%d ", ans - 1);
        for (int i = 1; i <= ans; i++)
            printf("%d ", t[i]);
        puts("");
    }
    return 0;
}