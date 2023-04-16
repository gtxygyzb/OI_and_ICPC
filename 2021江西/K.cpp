#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ll n, m;
        scanf("%lld%lld", &n, &m);
        printf("%lld\n", n * (n + 1) * (2 * n + 1) / 6 * m);
    }
    return 0;
}