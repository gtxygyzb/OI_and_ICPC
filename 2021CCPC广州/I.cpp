#include <bits/stdc++.h>
using namespace std;
const int P = 998244353;
int power(int x,int k)
{
    int ret = 1;
    for (; k; k >>= 1, x = 1LL * x * x % P)
        if (k & 1) ret = 1LL * ret * x % P;
    return ret;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        if (n == 1) puts("1");
        else if (n == 2) puts("2");
        else if (n == 3) puts("6");
        else printf("%d\n", 1LL * 6 * power(2, n - 3) % P);
    }
    return 0;
}