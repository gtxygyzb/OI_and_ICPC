#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[10];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ll s = 0;
        for (int i = 1; i <= 3; i++)
        {
            scanf("%lld", a+i);
            s += a[i];
        }
        sort(a + 1, a + 3 + 1);
        if (s % 3) printf("%lld\n", s * s);
        else
        {
            if ((a[2] - a[1]) % 3 == 0 && (a[3] - a[2]) % 3 == 0)
                printf("%lld\n", s * s);
            else printf("%lld\n", s * s - 2 * s + 2);
        }
    }
    return 0;
}